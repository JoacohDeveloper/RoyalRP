
#include <zcmd>
#include <sscanf2>

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





CMD:cinematica(playerid) {


	new objectId = CreateObject(13, -812.2347, 2221.4792, 134.2138, 0.0, 0.0, 0.0);
	AttachCameraToObject(playerid, objectId);
	MoveObject(objectId, -742.6212, 1897.6364, 27.7391, 60000, 0, 0, 0);

	SetTimerEx("cinematic", 0, true, "ii", playerid, objectId);
	return 1;
}


forward cinematic(playerid, objectid);
public cinematic(playerid, objectid) {
	AttachCameraToObject(playerid, objectid);
	return 1;

}


public OnObjectMoved(objectid) {
	//AttachCameraToObject(playerid, objectId);
	printf("%d", objectid);

	return 1;
}