#include <a_samp>
#include <core>
#include <streamer>
#include <Rogue-AC>
#include "../gamemodes/includes/helpers/functions.inc"
#include "../gamemodes/includes/models/user.inc"
#include "../gamemodes/includes/config/database.inc"
#include "../gamemodes/includes/authentication.inc"
#include "../gamemodes/includes/commands.inc"
#include <sscanf2>

main()
{
	print("Hello frikin well");
	// saludar();
}



//Anticheat
public OnPlayerViolate(playerid, severity, violationCode, const violationName[]) {

	return 1;
}

public OnGameModeInit() {

	dbConn();
	return 1;
}


public OnPlayerConnect(playerid)
{

	// User[playerid][Health] = setHealth(playerid, 33.45);
	SetPlayerCameraPos(playerid,132.000000,-67.291427,1.578125);
	SetPlayerCameraLookAt(playerid,137.000000,-67.291427,1.578125);
	SetPlayerCameraPos(playerid,132.000000,-67.291427,1.578125);
	SetPlayerCameraLookAt(playerid,137.000000,-67.291427,1.578125);
	InterpolateCameraPos(playerid,132.000000,-67.291427,1.578125,296.909515,-67.291427,1.578125,30000,CAMERA_MOVE);
	InterpolateCameraLookAt(playerid,137.000000,-67.291427,1.578125,308.819641,-67.291427,1.578125,1000,CAMERA_MOVE);


	GameTextForPlayer(playerid,"~w~SA-MP: ~r~RoyalRP.GG",5000,5);
	return 1;
}
