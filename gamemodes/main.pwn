#include <a_samp>
#include <core>
#include <streamer>
#include "../gamemodes/includes/models/user.inc"
#include "../gamemodes/includes/config/database.inc"
#include "../gamemodes/includes/authentication.inc"
#include "../gamemodes/includes/helpers/functions.inc"
#include "../gamemodes/includes/commands.inc"


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

	User[playerid][Health] = setHealth(playerid, 33.45);


	
	GameTextForPlayer(playerid,"~w~SA-MP: ~r~RoyalRP.GG",5000,5);
	return 1;
}
