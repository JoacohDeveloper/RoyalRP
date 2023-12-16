#include <a_mysql>
#define DB_HOST "127.0.0.1"
#define DB_USER "root"
#define DB_PASS "1248"
#define DB_NAME "RoyalRPGMDB"
#define DB_PORT 3307


new MySQL:mysql;

forward dbConn();
public dbConn() {
	new MySQLOpt:options = mysql_init_options();
	mysql_set_option(options, SERVER_PORT, DB_PORT);
	mysql = mysql_connect(DB_HOST, DB_USER, DB_PASS, DB_NAME, options);

	if(mysql_errno() != 0 || mysql == MYSQL_INVALID_HANDLE) {
		SendRconCommand("exit");
	} else {
		print("Conexión establecida a la base de datos.");
	}

	return 1;
}
