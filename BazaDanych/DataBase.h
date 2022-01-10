#pragma once
#include "Library.h"

class DB 
{
private:
	char c;
	int wybor;

	std::string imie, nazwisko; int wiek;

	struct menu
	{
		int x;
		int y;
	}m;
	lista<osoba> L;
public:
	DB():wybor(0),c(0) {
		SetWindow(WIDTH, HEIGHT);
		std::thread load(LoadingScreen);
		try { wczytaj(); }
		catch (LPCSTR s) { MessageBoxA(NULL, s, "Alert!", MB_OK | MB_ICONEXCLAMATION); }
		load.join();
		m = { column_W * 4 + 3,2 };
	}
	void OpenDatabase();
private:
	//Main thread//
	void MainMenu();

	//Showing funcs//
	void ClearMenu();
	void ShowAll();

	//Load&Save//
	void wczytaj();
	void zapisz();

};