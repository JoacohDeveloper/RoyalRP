#include <a_samp>
#include <core>
#include <streamer>
#include <strlib>
#include <sscanf2>

//colors
#define RED 0xFF0000

#define SCM SendClientMessage
#include "../gamemodes/includes/config/database.inc"
#include "../gamemodes/includes/config/anticheat.inc"
#include "../gamemodes/includes/models/user.inc"
#include "../gamemodes/includes/authentication.inc"
#include "../gamemodes/includes/helpers/functions.inc"
#include "../gamemodes/includes/commands.inc"
#include "../gamemodes/includes/helpers/constants.inc"




main()
{
}

public OnPlayerRequestClass(playerid, classid) {

	cinematic(playerid);
	Login(playerid);
	return 1;
}

public OnGameModeInit() {

	dbConn();
	UsePlayerPedAnims();
	DisableInteriorEnterExits();
	return 1;
}


public OnPlayerConnect(playerid)
{

	onPlayerConnectBoundles(playerid);

	return 1;
}

public OnPlayerSpawn(playerid) {

	onPlayerSpawnBoundles(playerid);
	return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]) {

	LoginDialogsResponse(playerid, dialogid, response, listitem, inputtext);
	return 1;
}
