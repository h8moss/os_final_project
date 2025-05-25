# Proyecto final de Sistemas Operativos

## Requerimientos
Los siguientes son los requerimientos minimos del proyecto final de Sistemas Operativos.

### Gestion de procesos
- [ ] Simula la creación y ejecución de procesos. Muestra el comportamiento de procesos padre e hijo. 
- [ ] Se espera que el alumno utilice fork() para crear procesos hijos, y exec() para que estos ejecuten otras tareas o programas. El uso de wait() debe servir para que el proceso padre espere a los hijos. 
- [ ] Además, se pueden emplear señales (kill, SIGSTOP, SIGCONT) para simular la suspensión o reanudación de procesos.

### Planificacion del CPU
- [ ] Implementa un planificador de procesos con algoritmo FIFO y Round Robin así como todas sus características.
- [ ] Este módulo simula la forma en que el sistema operativo decide cuál proceso debe ejecutarse y en qué orden.
- [ ] Los procesos pueden representarse como estructuras en memoria (con PID, estado y prioridad).
- [ ] La simulación puede hacerse con sleep() y mensajes en consola para representar el cambio de contexto.

### Sistema de archivos
- [x] Implementa un sistema de archivos básico que permita crear, leer, escribir y cerrar archivos. Simula metadatos y estructura jerárquica.
- [x] Los alumnos deben poder crear, leer, escribir y cerrar archivos utilizando open(), read(), write() y close().
- [x] Además, pueden simular la estructura de un sistema de archivos usando carpetas y metadatos guardados en archivos.
- [x] No es necesario implementar un filesystem completo, pero sí se espera una organización clara de los archivos simulados y su contenido.
- [x] cd command y directorios relativos (./file, ../sibling/)

### Entrada y salida
- [ ] Simula entrada/salida de usuario (por teclado y archivo). Imprime mensajes y guarda logs en archivos externos.
- [ ] La salida debe escribirse en archivos simulados (como una 'impresora') o mostrarse por consola. Se espera que los alumnos comprendan cómo simular flujos de entrada y salida.

### Control de acceso
- [ ] Desarrolla un sistema de control de usuarios y permisos. Cada archivo debe tener propietario y permisos. Simula el login de usuario y restringe acciones según sus privilegios.
- [ ] Este módulo simula la existencia de múltiples usuarios en el sistema.
- [ ] Cada archivo debe tener un propietario y permisos asignados (lectura, escritura, ejecución).
- [ ] Los alumnos deben simular un inicio de sesión y validar si el usuario actual tiene permiso para realizar operaciones sobre un archivo.
- [ ] El usuario 'root' tiene privilegios totales y otro usuario con accesos limitados.

## Instrucciones de compilacion
Tras descargar el proyecto y encontrarse en la carpeta del proyecto:

1. Asegurarse de tener instalado Cmake, Make y un compilador de C++
```bash
$> sudo apt install make cmake g++
```

2. Crear un directorio "build" y moverse a dicho directorio.
```bash
$> mkdir build
$> cd build
```

3. Generar los archivos de compilacion.
```bash
$> cmake ..
```

4. Generar el ejecutable.
```bash
$> make 
```

Al terminar, el archivo `my_os` debe de haberse generado en la carpeta build.

## Instrucciones de uso
Al ejecutar `my_os`, serás recibido con una pantalla donde se pueden introducir comandos.

### Lista de comandos

- exit                      - Salir de la aplicacion
- mkdir "path"              - Crear directorio
- touch "path"              - Crear archivo o actualizar tiempo de edicion
- ls "path"                 - Listar archivos en folder.
- cat "path"                - Mostrar contenidos de un archivo
- empty "path"              - Vaciar un archivo
- append "path" "string"    - Agregar texto a un archivo
- rm "path"                 - Quitar archivo
- rmdir "path"              - Quitar directorio vacio
- meta "path"               - Mostrar metadatos de un archivo
- cd "path"                 - Cambiar de directorio actual
- whoami                    - Imprime el usuario actual
- login                     - Permite iniciar sesion con un nuevo usuario
