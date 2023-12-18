#define VW_CINEMATIC 8

stock Float:setHealth(playerid, Float:health) {

	SetPlayerHealth(playerid, health);
	return health;
}
//User[playerid][Health] = setHealth(playerid, 33.45); - Modo de uso.

stock getPlayerUsername(playerid) {
	new username[45];

	GetPlayerName(playerid, username, sizeof(username));

	return username;
}

stock GetVehicleSpeed(vehicleid)
{
	new Float:v_x;
	new Float:v_y;
	new Float:v_z;

	GetVehicleVelocity(vehicleid, v_x, v_y, v_z);

	return floatround(floatsqroot((v_x * v_x) + (v_y * v_y) + (v_z * v_z)) * 181.5);
}

forward onPlayerConnectBoundles(playerid);
public onPlayerConnectBoundles(playerid) {
	// music 
	PlayAudioStreamForPlayer(playerid, "http://localhost:3000/media/music");



	//Login
	return 1;
}


forward onPlayerSpawnBoundles(playerid);
public onPlayerSpawnBoundles(playerid) {
	// music 
	StopAudioStreamForPlayer(playerid);


	//cinematic
	SetCameraBehindPlayer(playerid);
	SetPlayerInterior(playerid, 0);





	return 1;
}


forward cinematic(playerid);
public cinematic(playerid) {

	SetPlayerVirtualWorld(playerid, VW_CINEMATIC);
	SetPlayerCameraPos(playerid,1401.052368,-2594.200195,15.526875);
	SetPlayerCameraLookAt(playerid,1406.052368,-2594.200195,14.816852);
	InterpolateCameraPos(playerid,1401.052368,-2594.200195,15.526875,2096.513671,-2594.230224,15.506888,120000,CAMERA_MOVE);
	InterpolateCameraLookAt(playerid,1406.052368,-2594.200195,14.816852,2105.361572,-2594.221435,14.776876,1000,CAMERA_MOVE);

	return 1;

}