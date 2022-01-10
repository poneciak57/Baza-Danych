#pragma once
#include <iostream>
#include <windows.h>
#include <memory>
#include <cstdlib>
#include <conio.h>
#include <fstream>
#include <string>
#include <thread>

const int column_W = 22;
const int  WIDTH  = 100;
const int  HEIGHT  = 72;


// coordinate set //
void coords(int x, int y);
// window size set //
void SetWindow(int Width, int Height);
// get current position //
COORD GetConsoleCursorPosition(HANDLE hConsoleOutput);


// loading screen //
void LoadingScreen();

/// text color set ///
/// SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1); ///
/// ------------------------------
/// |     1 - 8 = dim ones       |
/// |   9 - 15 = vibrant ones    |
/// |    16 - 25 = blue bg       |
/// ------------------------------
/// |        1 - blue            |
/// |        2 - green           |
/// |        3 - cyan            |
/// |        4 - red             |
/// |        5 - pink            |
/// |        6 - yellow          |
/// |        7 - white           |
/// |        8 - grey            |
/// |        9 - blue            |
/// |        10 - green          |
/// |        11 - cyan           |
/// |        12 - red            |
/// |        13 - pink           |
/// |        14 - yellow         |
/// |        15 - white          |
/// ------------------------------

