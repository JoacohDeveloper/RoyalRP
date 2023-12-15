#include <a_samp>
#include <core>
#include <streamer>
#include <sscanf2>
#include <zcmd>
#include "../gamemodes/includes/config/database.inc"
#include "../gamemodes/includes/authentication.inc"


main()
{
	print("Hello frikin well");

	saludar();
}

public OnGameModeInit() {

	dbConn();
	
	return 1;
}

public OnPlayerConnect(playerid)
{
	new query[128];

	mysql_format(mysql, query, sizeof(query), "INSERT INTO `user` (`uuid`,`username`,`email`,`password`) VALUES ('%s','%s','%s', '%s')",
			"uuukd",
			"joaco",
			"caca@caca",
			"hola123"
		);
	mysql_query(mysql, query, false);

	print(query);

	GameTextForPlayer(playerid,"~w~SA-MP: ~r~RoyalRP.GG",5000,5);
	return 1;
}

CMD:saludar(playerid){

	new msg[144];
	format(msg, sizeof(msg), "Hello %s", getPlayerUsername(playerid));
	SendClientMessage(playerid, -1, msg);


	return 1;

}

stock getPlayerUsername(playerid) {
	new username[45];

	GetPlayerName(playerid, username, sizeof(username));

	return username;
}



CMD:prueba(playerid, params[]) {

	new text1[45];
	new text2[45];
	new text3[45];
	if(sscanf(params, "s[45]s[45]s[45]", text1, text2, text3)) {
		printf("No hay 3 parametros");
	} else {
		printf("%s %s %s ", text1, text2, text3);
	}

	return 1;

}