#pragma once
#include "Libraries_Engine.h"
#include "Node.h"
// struct //
struct osoba
{
	std::string imie;
	std::string nazwisko;
	int wiek;
};
// struct cout method //
std::ostream& operator << (std::ostream& ost, const osoba& o);
std::fstream& operator << (std::fstream& ost, const osoba& o);
// compare by functions for struct //
bool compare_name(osoba a,osoba b, bool asc); // true - rosnaco | false - malejaca
bool compare_surname(osoba a, osoba b,bool asc);
bool compare_age(osoba a, osoba b,bool asc);
