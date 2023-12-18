#include <samp_bcrypt>
#include <uuid>
#include <requests>
#include <logger>
// #include <settings>
#include <map>
//Login Dialogs
#define LOGIN_EMAIL 201
#define LOGIN_BAD_EMAIL 202
#define LOGIN_PASSWORD 203
#define LOGIN_BAD_PASSWORD 204
#define LOGIN_GENDER 205
#define LOGIN_GENDER_EX 206
#define LOGIN_TOKEN 207
#define LOGIN_BAD_TOKEN 208


//bcrypt_hash(0, "bcryptCallback", "hello world", BCRYPT_COST);

// forward Token(playerid);


// forward TokenVerification(playerid);



new Map:LoadRequestToPlayerID;
new RequestsClient:client;
stock bool:EmailVerification(const inputtext[], playerid) {
	if(strcount(inputtext, "@", true) > 1 || strcount(inputtext, "@", true) == 0) return false;
	//print(inputtext);
	new url[140];
	new apiKey[45];
	new endpoint[120];

	//Api credentials
	url = "https://emailvalidation.abstractapi.com/v1/";
	apiKey = "b66bbfbaca52450c9d3c77b0c89fb17f";
	format(endpoint, sizeof(endpoint), "?api_key=%s&email=%s", apiKey, inputtext);
	client = RequestsClient(url);

	new Request:id = RequestJSON(
    client,
    endpoint,
    HTTP_METHOD_GET,
    "OnGetEmailValidator",
    .headers = RequestHeaders()
	);
	MAP_insert_val_val(LoadRequestToPlayerID, _:id, playerid);
	return true;	
}
stock badEmail(playerid) {

	new emailInfo[256];
	format(emailInfo, sizeof(emailInfo), "El email ingresado no es valido, vuelve a intentar:");
	utf8encode(emailInfo, emailInfo, sizeof(emailInfo));
	ShowPlayerDialog(playerid, LOGIN_BAD_EMAIL, DIALOG_STYLE_INPUT, "Introduce un email: ", emailInfo, "Continuar", "Cancelar");

	return 1;
}

forward OnGetEmailValidator(Request:id, E_HTTP_STATUS:status, Node:node);
public OnGetEmailValidator(Request:id, E_HTTP_STATUS:status, Node:node) {

	new bool:valid;
	new Node:output;

	JsonGetObject(node, "is_valid_format", output);
	JsonGetBool(output, "value", valid);
	
	new playerid = MAP_get_val_val(LoadRequestToPlayerID, _:id);
    MAP_remove_val(LoadRequestToPlayerID, _:id);

    if(!valid) {
    	badEmail(playerid);
    } else {
		new passwordInfo[256];
		format(passwordInfo, sizeof(passwordInfo), "Ingrese una contraseña para poder registrarte\nMin 8 Caracteres");
		utf8encode(passwordInfo, passwordInfo, sizeof(passwordInfo));
		ShowPlayerDialog(playerid, LOGIN_PASSWORD, DIALOG_STYLE_PASSWORD, ret_utf8encode("Introduce una contraseña: "), passwordInfo, "Continuar", "Cancelar");
    }
	return 1;
}

forward LoginDialogsResponse(playerid, dialogid, response, listitem, inputtext[]);
public LoginDialogsResponse(playerid, dialogid, response, listitem, inputtext[]) {
	new email[144];
	new password[61];
	new gender[45];

	switch(dialogid){
		case LOGIN_EMAIL: {
			if(!response) Kick(playerid);
			printf("Dialogid: %i, inputtext: %s", dialogid, inputtext);

			if(!EmailVerification(inputtext, playerid)) {
				format(email, sizeof(email), "%s", inputtext);
				User[playerid][Email] = email;
				badEmail(playerid);
			}
		}
		case LOGIN_BAD_EMAIL: {
			if(!response) Kick(playerid);
			if(!EmailVerification(inputtext, playerid)) {
				format(email, sizeof(email), "%s", inputtext);
				User[playerid][Email] = email;
				badEmail(playerid);
			}
		}
		case LOGIN_PASSWORD: {
			if(!response) Kick(playerid);
			if(!isempty(inputtext) && strlen(inputtext) >= 8) {
				format(password, sizeof(password), "%s", inputtext);
				bcrypt_hash(playerid, "bcryptCallback", password, BCRYPT_COST);
			}else {
				new passwordInfo[256];
				format(passwordInfo, sizeof(passwordInfo), "Contraseña invalida, prueba con otra contraseña.\nMin 8 Caracteres");
				utf8encode(passwordInfo, passwordInfo, sizeof(passwordInfo));
				ShowPlayerDialog(playerid, LOGIN_PASSWORD, DIALOG_STYLE_PASSWORD, ret_utf8encode("Introduce una contraseña: "), passwordInfo, "Continuar", "Cancelar");
			}
		}
		case LOGIN_BAD_PASSWORD: {
			if(!response) Kick(playerid);
			if(!isempty(inputtext) && strlen(inputtext) >= 8) {
				format(password, sizeof(password), "%s", inputtext);
				bcrypt_hash(playerid, "bcryptCallback", password, BCRYPT_COST);
			}else {
				new passwordInfo[256];
				format(passwordInfo, sizeof(passwordInfo), "Contraseña invalida, prueba con otra contraseña.\nMin 8 Caracteres");
				utf8encode(passwordInfo, passwordInfo, sizeof(passwordInfo));
				ShowPlayerDialog(playerid, LOGIN_PASSWORD, DIALOG_STYLE_PASSWORD, ret_utf8encode("Introduce una contraseña: "), passwordInfo, "Continuar", "Cancelar");
			}
		}
		case LOGIN_GENDER: {
			if(!response) Kick(playerid);
			if(listitem == 0) {
				gender = "Hombre";
			} else if(listitem == 1) {
				gender = "Hombre";
			} else {
				ShowPlayerDialog(playerid, LOGIN_GENDER_EX, DIALOG_STYLE_INPUT, "Ingrese su genero: ", "Ingrese un genero de forma especifica.", "Continuar", "Cancelar");

			}
			User[playerid][Gender] = gender;
		}
		case LOGIN_GENDER_EX: {
			if(!response) 
				ShowPlayerDialog(playerid, LOGIN_GENDER, DIALOG_STYLE_LIST, "Genero de tu personaje: ", "Hombre\nMujer\nEspecificar...", "Continuar", "Cancelar");
			if(isempty(inputtext)) {
				ShowPlayerDialog(playerid, LOGIN_GENDER_EX, DIALOG_STYLE_LIST, "El campo 'genero' no puede estar vacio.", "Hombre\nMujer\nEspecificar...", "Continuar", "Cancelar");
			} else {
				ShowPlayerDialog(playerid, LOGIN_TOKEN, DIALOG_STYLE_INPUT, "Verificacion de email", ret_utf8encode("Hemos enviado un correo de verificación, ingrese su código: "), "Registrarse", "Cancelar");
				// Token(playerid);
			}
		}

		case LOGIN_TOKEN: {
			if(!response) Kick(playerid);

			// TokenVerification(playerid, inputtext);
		}
	}
	return 1;
}




forward bcryptCallback(playerid, hashid);
public bcryptCallback(playerid, hashid) {
	new dest[BCRYPT_HASH_LENGTH];
	bcrypt_get_hash(dest);
	User[playerid][Password] = dest;
	ShowPlayerDialog(playerid, LOGIN_GENDER, DIALOG_STYLE_LIST, "Genero de tu personaje: ", "Hombre\nMujer\nEspecificar...", "Continuar", "Cancelar");


	return 1;
}

forward Login(playerid);
public Login(playerid) {

	new emailInfo[256];
	format(emailInfo, sizeof(emailInfo), "Introduce un email valido:\nPara poder registrarte\n");
	utf8encode(emailInfo, emailInfo, sizeof(emailInfo));
	ShowPlayerDialog(playerid, LOGIN_EMAIL, DIALOG_STYLE_INPUT, "Introduce un email: ", emailInfo, "Continuar", "Cancelar");

	return 1;
}
