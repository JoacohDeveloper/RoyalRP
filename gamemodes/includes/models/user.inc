#include "a_samp"

// 0 User, 1 Helper, 2 Staff, 3 Admin, 4 Founder
enum E_User {
	Uuid[45],
	Rol,
	Username[45],
	Gender[45],
	Float:Health,
	Float:Armour,
	Money,
	bool:Dead,
	bool:LoggedIn,
	Email[144],
	Password[61],
	Token[45],
	bool:Verified,
	bool:Banned,
	Warnings,
	LastConnection[45],
	CreatedAt[45]
}

new User[MAX_PLAYERS][E_User];