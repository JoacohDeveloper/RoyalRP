#include <samp_bcrypt>



forward saludar();
public saludar() {
	print("Saludando...");
	// playerid, fn, text, cost
	bcrypt_hash(0, "bcryptCallback", "hello world", BCRYPT_COST);
	return 1;
}

forward bcryptCallback(playerid, hashid);
public bcryptCallback(playerid, hashid) {
	print("hello world");
	new dest[BCRYPT_HASH_LENGTH];
	bcrypt_get_hash(dest);
	printf("hash : %s", dest);
	return 1;
}

