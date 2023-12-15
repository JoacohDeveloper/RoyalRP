
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