#include "DataBase.h"

/**
*	\brief glowna metoda DB uruchamiajaca baze danych 
*	i obslugujaca jej glowny watek
*	
*	\param no parameters
*	\return no return
**/
void DB::OpenDatabase()
{
	ShowAll();
	MainMenu();
	while (!(c == char(13) && wybor == 3))
	{
		switch (c)
		{
		case 'w':{ wybor -= 1 * (wybor > 0); }break;
		case 's':{ wybor += 1 * (wybor < 3); }break;
		case char(13) :{
			switch (wybor)
			{
			case 0: // push_back
			{
				ClearMenu();
				coords(m.x, m.y);
				std::cout << "Podaj imie:";
				std::cin >> imie;
				coords(m.x, m.y+1);
				std::cout << "Podaj nazwisko:";
				std::cin >> nazwisko;
				coords(m.x, m.y+2);
				std::cout << "Podaj wiek:";
				std::cin >> wiek;
				L.push_back({ imie ,nazwisko,wiek });
				ShowAll();
			}break;
			case 1: //drop
			{
				ClearMenu();
				coords(m.x, m.y);
				std::cout << "Podaj ID do usuniecia:";
				std::cin >> wiek;
				try { L.drop(wiek); }
				catch (LPCSTR s) { MessageBoxA(NULL, s, "Alert!", MB_OK | MB_ICONEXCLAMATION); }
				ShowAll();
			}break;
			case 2: //sort
			{
				ClearMenu();
				coords(m.x, m.y);
				std::cout << " 1.Sortuj po imieniu";
				coords(m.x, m.y+1);
				std::cout << " 2.Sortuj po nazwisku";
				coords(m.x, m.y+2);
				std::cout << " 3.Sortuj po wieku \r";
				c = _getch();

				coords(m.x, m.y);
				std::cout << " 1.Rosnaco             ";
				coords(m.x, m.y+1);
				std::cout << " 2.Malejaco             ";
				coords(m.x, m.y+2);
				std::cout << "                       \r";
				char asc = _getch();
				try {
					switch (c)
					{
					case '1': {
						L.sort(asc == '1', compare_name);
					}break;
					case '2': {
						L.sort(asc == '1', compare_surname);
					}break;
					case '3': {
						L.sort(asc == '1', compare_age);
					}break;
					}
				}
				catch (LPCSTR s) { MessageBoxA(NULL, s, "Alert!", MB_OK | MB_ICONEXCLAMATION); }
				ShowAll();
			}break;
			}}break;
		}
		MainMenu();
		c = 'c';
		c = _getch();

	}
	try { zapisz(); }
	catch (LPCSTR s) { MessageBoxA(NULL, s, "Alert!", MB_OK | MB_ICONEXCLAMATION); }
}
/**
*	\brief metoda odpowiedzialna za wypisanie glownych opcji
*	glownego menu bazy danych
*
*	\param no parameters
*	\return no return
**/
void DB::MainMenu()
{
	coords(m.x, m.y);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (wybor == 0) * +11 + 7);
	std::cout << " 1.Dodaj Do Bazy Danych\n";

	coords(m.x, m.y+1);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (wybor == 1) * +11 + 7);
	std::cout << " 2.Usun Z Bazy Danych\n";

	coords(m.x, m.y+2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (wybor == 2) * 11 + 7);
	std::cout << " 3.Sortuj Baze Danych\n";

	coords(m.x, m.y+3);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (wybor == 3) * 11 + 7);
	std::cout << " 4.Wyjdz i zapisz\n";

	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
/**
*	\brief czysci pole na menu
*
*	\param no parameters
*	\return no return
**/
void DB::ClearMenu()
{
	for (int i = 0; i < 6; i++)
	{
		coords(m.x, m.y-1+i);
		std::cout << "                         ";
	}
	coords(0, 0);
}
/**
*	\brief wyswietla wszystkie rekordy bazy danych
*
*	\param no parameters
*	\return no return
**/
void DB::ShowAll()
{
	system("cls");
	COORD c;
	Node<osoba>* temp = L.first();
	for (int i = 0; i <= 4 * column_W + 31 ; i++)
	{
		coords(i, 0);
		std::cout << char(219);
	}
	coords(0 * column_W, 1);
	std::cout << char(219) << "          ID";
	coords(1 * column_W, 1);
	std::cout << char(219) << "         Imie";
	coords(2 * column_W, 1);
	std::cout << char(219) << "        Nazwisko";
	coords(3 * column_W, 1);
	std::cout << char(219) << "         Wiek";
	coords(4 * column_W, 1);
	std::cout << char(219);
	for (int i = 0; i <= 31; i++)
	{
		coords(4 * column_W + i, 1);
		std::cout << char(219);
	}
	for (int i = 0; i <= 4 * column_W + 31; i++)
	{
		coords(i, 2);
		std::cout << char(219);
	}
	while (temp)
	{
		c = GetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE));
		for (int i = 0; i <= 4; i++)
		{
			coords(i * column_W, c.Y + 1);
			std::cout << char(219);
		}
		for (int i = 0; i <= 31; i++)
		{
			coords(4 * column_W + i, c.Y + 1);
			std::cout << char(219);
		}
		coords(0 * column_W + (25 - log10(temp->index +1)) / 2, c.Y + 1);
		std::cout << temp->index;
		std::cout << temp->rekord;
		temp = temp->next;
	}
	c = GetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE));
	for (int i = 0; i <= 4 * column_W+31; i++)
	{
		coords(i, c.Y + 1);
		std::cout << char(219);
	}
	ClearMenu();
}

//Load&Save//
/**
*	\brief zaladowuje wszystkie dane z pliku tekstowego save.txt
*	do bazy danych
*
*	\param no parameters
*	\return no return
**/
void DB::wczytaj()
{
	std::fstream plik;
	plik.open("save.txt", std::ios::in);
	if (plik.good() == true)
	{
		std::string napis;
		getline(plik, napis);
		int nr = stoi(napis);
		while (nr--)
		{
			getline(plik, imie);
			getline(plik, nazwisko);
			getline(plik, napis);
			wiek = stoi(napis);
			L.push_back({ imie,nazwisko,wiek });
		}
		plik.close();
	}
	else
		throw "Nie udalo sie otworzyc pliku";
}
/**
*	\brief zapisuje wszystkie dane z bazy danych do pliku tekstowego
* 
*	\param no parameters
*	\return no return
**/
void DB::zapisz()
{
	std::fstream plik;
	plik.open("save.txt", std::ios::out);
	if (plik.good() == true)
	{
		Node<osoba>* temp = L.first();
		plik << L.size() << "\n";
		while (temp)
		{
			plik << temp->rekord;
			temp = temp->next;
		}
		plik.close();
	}
	else
		throw "Nie udalo sie otworzyc pliku";
}

