#define SCM SendClientMessage

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
