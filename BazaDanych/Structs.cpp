#include "Structs.h"

std::ostream& operator << (std::ostream& ost, const osoba& o)
{
	COORD c = GetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE));

	coords(1 * column_W+(25-o.imie.size())/2, c.Y);
	std::cout << o.imie; 
	coords(2 * column_W+ (25 - o.nazwisko.size()) / 2, c.Y);
	std::cout << o.nazwisko; 
	coords(3 * column_W+(25-log10(o.wiek))/2, c.Y);
	std::cout << o.wiek;
	return ost;
}
std::fstream& operator << (std::fstream& ost, const osoba& o)
{
	ost << o.imie << "\n";
	ost << o.nazwisko << "\n";
	ost << o.wiek << "\n";
	return ost;
}
bool compare_name(osoba a, osoba b,bool asc) // true - roscnaco | false - malejaca
{
	if (asc)
		return a.imie > b.imie;
	return a.imie < b.imie;
}
bool compare_surname(osoba a, osoba b, bool asc)
{
	if (asc)
		return a.nazwisko > b.nazwisko;
	return a.nazwisko < b.nazwisko;
}
bool compare_age(osoba a, osoba b, bool asc)
{
	if (asc)
		return a.wiek > b.wiek;
	return a.wiek < b.wiek;
}