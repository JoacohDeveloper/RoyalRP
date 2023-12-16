
#include <zcmd>
// #include <sscanf2>

// CMD:saludar(playerid){

// 	new msg[144];
// 	format(msg, sizeof(msg), "Hello %s", getPlayerUsername(playerid));
// 	SendClientMessage(playerid, -1, msg);

// 	return 1;

// }

// CMD:prueba(playerid, params[]) {

// 	new text1[45];
// 	new text2[45];
// 	new text3[45];
// 	if(sscanf(params, "s[45]s[45]s[45]", text1, text2, text3)) {
// 		printf("No hay 3 parametros");
// 	} else {
// 		printf("%s %s %s ", text1, text2, text3);
// 	}


// 	new query[128];

// 	mysql_format(mysql, query, sizeof(query), "INSERT INTO `user` (`uuid`,`username`,`email`,`password`) VALUES ('%s','%s','%s', '%s')",
// 			"uuukd",
// 			"joaco",
// 			"caca@caca",
// 			"hola123"
// 		);
// 	mysql_query(mysql, query, false);

// 	print(query);

// 	return 1;

// }


CMD:vida(playerid) {
	if(!IsPlayerConnected(playerid) || playerid == INVALID_PLAYER_ID) return 0;
	
	User[playerid][Health] = setHealth(playerid, 50.0);
	SCM(playerid, -1, "Your Health has been changed by 50");
	return 1;
}

CMD:cinematica(playerid) {


	SetPlayerCameraPos(playerid,132.000000,-67.291427,1.578125);
	SetPlayerCameraLookAt(playerid,137.000000,-67.291427,1.578125);
	SetPlayerCameraPos(playerid,132.000000,-67.291427,1.578125);
	SetPlayerCameraLookAt(playerid,137.000000,-67.291427,1.578125);
	InterpolateCameraPos(playerid,132.000000,-67.291427,1.578125,296.909515,-67.291427,1.578125,30000,CAMERA_MOVE);
	InterpolateCameraLookAt(playerid,137.000000,-67.291427,1.578125,308.819641,-67.291427,1.578125,1000,CAMERA_MOVE);

	return 1;
}



public OnObjectMoved(objectid) {
	//AttachCameraToObject(playerid, objectId);
	printf("%d", objectid);

	return 1;
}