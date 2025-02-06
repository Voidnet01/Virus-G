# Virus-G

**Descripción:**
Virus-G es una prueba de concepto (PoC) de un malware visual y sonoro diseñado para crear un efecto tenebroso en el sistema infectado. No causa daños permanentes y está pensado únicamente para pruebas en entornos controlados como máquinas virtuales.

**Características:**

- Reproduce música de fondo en bucle.

- Genera un efecto de "lluvia de sangre" en la pantalla.

- Hace parpadear los colores de la consola.

- Crea múltiples ventanas con mensajes en pantalla.

- Mueve las ventanas de forma aleatoria para causar un efecto molesto.

---

![neon-biohazard-caution-sign-symbol-of-hazard-caused-free-vector](https://github.com/user-attachments/assets/5e030896-f860-4799-b8e8-addb6c5006b6)

Requisitos:

- Sistema operativo: Windows

- Lenguaje: C++

- Librerías necesarias: windows.h, mmsystem.h, thread, ctime, cstdlib

- Archivo de audio virusg.mp3 en la misma carpeta del ejecutable

Compilación:
Este programa puede ser compilado con MinGW o Visual Studio. Para compilar en MinGW, usa:
```
 g++ virusg.cpp -o virusg.exe -mwindows -lwinmm
```

jecución:
Ejecuta el archivo virusg.exe en un entorno controlado (máquina virtual recomendada).

**Advertencia:**
Este código es solo para fines educativos y experimentales en entornos controlados. No debe ser utilizado para causar daños o molestias a terceros. Usa este programa con responsabilidad.
