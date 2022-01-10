#include "Libraries_Engine.h"

void LoadingScreen()
{
    HWND myconsole = GetConsoleWindow();
    HDC mydc = GetDC(myconsole);
    COLORREF COLOR = RGB(255, 255, 255);

    coords(55, 12 );
    std::cout << "Welcome";
    coords(57, 13);
    std::cout << "to";
    coords(54, 14);
    std::cout << "Databaase";
    int radius = 150,x = 467,y = 217;
    double temp;
    int r = 255, g = 255, b =255;
    for (int j = 0; j < 2; j++,radius = 150)
    {
        for (int i = 0; i < 5; i++)
        {
            radius--;
            r -= i * 20;
            g -= i * 50;
            COLOR = RGB(r, g, b);
            for (double temp_x = x - radius, y1, y2; temp_x < x - radius + 2 * radius; temp_x += 0.01)
            {
                temp = sqrt(pow(radius, 2) - pow(temp_x - x, 2));
                y1 = temp + y;
                y2 = -1 * temp + y;
                SetPixel(mydc, temp_x, y1, COLOR);
                SetPixel(mydc, temp_x, y2, COLOR);
            }
        }
    }
    //Sleep(1000);
}

void coords(int x, int y)
{
    COORD coord = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void SetWindow(int Width, int Height)
{
    _COORD coord;
    coord.X = Width;
    coord.Y = Height;

    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = Height - 1;
    Rect.Right = Width - 1;

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle
    SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size
    SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size
}
COORD GetConsoleCursorPosition(HANDLE hConsoleOutput)
{
    CONSOLE_SCREEN_BUFFER_INFO cbsi;
    if (GetConsoleScreenBufferInfo(hConsoleOutput, &cbsi))
    {
        return cbsi.dwCursorPosition;
    }
    else
    {
        // The function failed. Call GetLastError() for details.
        COORD invalid = { 0, 0 };
        return invalid;
    }
}