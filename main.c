#include <stdio.h>
#include "usuarios.h"

int main()
{
    // Carga usuarios desde el archivo usuarios.txt
    cargar_usuarios();

    // Intenta hacer login; si falla, termina el programa
    if (!login())
        return 1;

    // Simula un archivo propiedad de "juan"
    const char *propietario_archivo = "juan";
    const char *permiso_solicitado = "lectura";

    printf("\nArchivo propiedad de: %s\n", propietario_archivo);
    printf("Usuario actual: %s\n", usuarios[usuario_actual].nombre);

    // Verifica si el usuario actual tiene el permiso para el archivo
    if (verificar_permiso(propietario_archivo, permiso_solicitado, usuarios[usuario_actual].nombre))
    {
        printf("Tienes permiso para %s el archivo.\n", permiso_solicitado);
    }
    else
    {
        printf("No tienes permiso para %s el archivo.\n", permiso_solicitado);
    }

    return 0;
}
