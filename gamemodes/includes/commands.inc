#include <sscanf2>
#include <zcmd>

CMD:saludar(playerid){

	new msg[144];
	format(msg, sizeof(msg), "Hello %s", getPlayerUsername(playerid));
	SendClientMessage(playerid, -1, msg);


	return 1;

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


	new query[128];

	mysql_format(mysql, query, sizeof(query), "INSERT INTO `user` (`uuid`,`username`,`email`,`password`) VALUES ('%s','%s','%s', '%s')",
			"uuukd",
			"joaco",
			"caca@caca",
			"hola123"
		);
	mysql_query(mysql, query, false);

	print(query);

	return 1;

}