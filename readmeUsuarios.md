# Módulo de Control de Usuarios y Permisos

## Descripción

Esta parte del proyecto implementa el sistema básico de usuarios, login y verificación de permisos para archivos.

Incluye:

- Carga de usuarios desde archivo o código.
- Función de login para validar usuarios.
- Verificación de permisos (lectura, escritura, ejecución) basada en propietario y rol (root o usuario normal).
- Usuario `root` con acceso total.

## Archivos

- `usuarios.h` — definición de la estructura `Usuario` y funciones.
- `usuarios.c` — implementación de funciones de carga, login y permisos.
- `main.c` — ejemplo básico de uso del módulo (login y verificación de permisos).

## Usuarios definidos (ejemplo)

| Usuario | Contraseña | Rol     |
| ------- | ---------- | ------- |
| isai    | isai123    | root    |
| daniel  | daniel123  | usuario |
| iñigo   | inigo123   | usuario |

## Cómo usar

1. Incluir `usuarios.h` en tu código.
2. Llamar `cargar_usuarios()` para inicializar los usuarios.
3. Usar `login()` para pedir credenciales e identificar usuario.
4. Usar `verificar_permiso(propietario, permiso, usuario_actual_nombre)` para validar acceso.

## Integración con proyecto principal

- Agregar `usuarios.c` al `CMakeLists.txt` o al sistema de compilación.
- En el `main.c` o el módulo principal, llamar las funciones en el flujo adecuado.
- Asegurarse de manejar el índice `usuario_actual` para saber qué usuario está logueado.

## Compilación (ejemplo con CMake)

```bash
mkdir build
cd build
cmake ..
make
./SO.exe
```
