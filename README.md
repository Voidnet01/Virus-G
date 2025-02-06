**Virus G - Descripción General**

  ![virus](https://github.com/user-attachments/assets/f4acc8ab-77af-4750-a284-7759e934a8c3)


Virus G es un software malicioso avanzado diseñado para generar caos en las máquinas infectadas, empleando técnicas avanzadas de persistencia, anti-forense y anti-debugging. Su objetivo es sumergir al usuario en una experiencia de terror digital, modificando la apariencia del sistema operativo, bloqueando la pantalla, generando efectos visuales aterradores, y reproduciendo sonidos perturbadores.

Este malware, una vez ejecutado, se asegura de permanecer oculto y resistente a intentos de desinstalación, persistiendo incluso después de reinicios del sistema. El Virus G está diseñado para ejecutarse automáticamente al iniciar el sistema, lo que garantiza que su impacto sea continuo y prolongado.

A continuación, se describen las principales características de Virus G:

**Características Principales:**
Persistencia:

El virus se asegura de ejecutarse automáticamente cada vez que el sistema se inicia. Esto se logra mediante la creación de una entrada en el registro de Windows, lo que garantiza que el malware se ejecute de forma continua en cada arranque del sistema.
Anti-Forense:

Modificación de Tiempos de Archivo: El virus modifica las fechas de acceso y creación de los archivos infectados para ocultar su presencia.
Prevención de Detección: Utiliza técnicas avanzadas para asegurarse de que no pueda ser fácilmente detectado, manipulando la fecha de los archivos y asegurándose de que no queden rastros visibles de su actividad en el sistema.
Técnicas Anti-Debugging:

Detección de Depuradores: El malware tiene la capacidad de detectar la presencia de herramientas de depuración como OllyDbg, x32dbg, IDA y otras.
Detección de Entornos de Prueba (Sandbox): Virus G verifica si está siendo ejecutado en un entorno controlado, como una máquina virtual o sandbox, evitando la ejecución de efectos maliciosos en dichos entornos para evitar la detección.
Efectos Visuales Aterradores:

Lluvia de Sangre: Un efecto visual donde líneas rojas caen aleatoriamente sobre la pantalla, simulando una lluvia de sangre.
Parpadeo de Pantalla: Cambios rápidos de color en la pantalla, alternando entre colores rojos y verdes, generando una atmósfera de caos.
Ventanas Rotas: Simula la rotura de ventanas del sistema, creando una sensación de desorden y peligro.
Distorsión de Pantalla: Se presentan distorsiones y cambios aleatorios en el tamaño de las ventanas, alterando la estabilidad visual del sistema.
Reproducción de Sonidos Espeluznantes:

Sonidos aleatorios: Reproduce sonidos aterradores, como risas malignas y gritos espeluznantes, a intervalos aleatorios, creando un ambiente aterrador.
Sonidos constantes: En segundo plano, se reproducen de forma continua sonidos terroríficos que añaden tensión a la experiencia.
Imagenes Aterradoras:

Muestra imágenes aterradoras aleatorias en la pantalla. Estas imágenes se presentan en ventanas que aparecen y desaparecen rápidamente, aumentando la sensación de descontrol.
Bloqueo de Pantalla:

Pantalla bloqueada: El virus muestra un mensaje aterrador en la pantalla, simulando un bloqueo completo del sistema, haciendo creer al usuario que no puede salir o controlar su computadora.
Mensajes como "¡ESTÁS ATRAPADO!" o "¡ES DEMASIADO TARDE PARA ESCAPAR!" se repiten en la pantalla para aterrorizar al usuario.

---

**Futuras Mejoras:**
Virus G es solo la primera versión de un malware que tiene grandes posibilidades de mejora y expansión. En el futuro, se planean agregar las siguientes funcionalidades:

**Ransomware Integrado:**

Virus G podría evolucionar hacia un ransomware real, donde los archivos del usuario sean encriptados y se exija un rescate para su recuperación. El contador de tiempo que indica la eliminación de fotos y documentos sería más prominente, y los usuarios tendrían una sensación más realista de estar en peligro de perder sus datos.
Mayor Personalización en los Efectos Visuales:

Se agregarán más tipos de efectos visuales perturbadores, como distorsiones de la interfaz de usuario, efectos de "pantalla rota" más avanzados, y más imágenes espeluznantes para aumentar la inmersión.
Nuevas Técnicas Anti-Forense y Anti-Debugging:

Se planea mejorar las técnicas de evasión, incluyendo la evasión de nuevas tecnologías de depuración y la ocultación de los archivos del malware a través de nuevas técnicas de camuflaje en el sistema.
Más Sonidos y Efectos de Audio:

El virus podría incorporar sonidos adicionales como susurros, gritos o música discordante para aumentar la sensación de terror.
Captura de Pantalla y Datos del Usuario:

En versiones posteriores, se implementará la capacidad de tomar capturas de pantalla o grabar la actividad del usuario mientras interactúa con el malware, para hacer el ataque aún más intrusivo.
Mayor Persistencia y Escalabilidad:

El malware se hará aún más resistente, asegurándose de que sus efectos se mantengan activos incluso si el usuario intenta eliminarlo o reiniciar el sistema.


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

Ejecución:
Ejecuta el archivo virusg.exe en un entorno controlado (máquina virtual recomendada).

**Advertencia:**
Virus G está diseñado con fines educativos para aprender sobre seguridad informática, pero su uso en entornos no autorizados puede ser ilegal y éticamente incorrecto. El uso de este malware en sistemas ajenos sin el permiso explícito del propietario del sistema está penado por la ley y puede tener graves consecuencias legales. Se recomienda encarecidamente usar este software solo en entornos controlados de prueba y nunca en sistemas de producción o personales.


