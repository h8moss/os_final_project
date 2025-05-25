#include <stdio.h>
#include <string.h>
#include "usuarios.h"

Usuario usuarios[MAX_USUARIOS];
int total_usuarios = 0;
int usuario_actual = -1;

void cargar_usuarios()
{
    FILE *archivo = fopen("usuarios.txt", "r");
    if (!archivo)
    {
        printf("No se pudo abrir el archivo de usuarios.\n");
        return;
    }

    total_usuarios = 0;
    while (total_usuarios < MAX_USUARIOS && fscanf(archivo, "%19s %19s %d",
                                                   usuarios[total_usuarios].nombre,
                                                   usuarios[total_usuarios].password,
                                                   &usuarios[total_usuarios].es_root) == 3)
    {
        total_usuarios++;
    }

    fclose(archivo);
}

int login()
{
    char nombre[20], pass[20];
    printf("=== Login ===\nUsuario: ");
    scanf("%19s", nombre);
    printf("Contraseña: ");
    scanf("%19s", pass);

    for (int i = 0; i < total_usuarios; i++)
    {
        if (strcmp(nombre, usuarios[i].nombre) == 0 &&
            strcmp(pass, usuarios[i].password) == 0)
        {
            usuario_actual = i;
            printf("Bienvenido, %s.\n", nombre);
            return 1;
        }
    }
    printf("Login incorrecto.\n");
    return 0;
}

int verificar_permiso(const char *propietario, const char *permiso, const char *usuario_nombre)
{
    if (strcmp(usuario_nombre, "root") == 0)
        return 1; // root tiene acceso total

    if (strcmp(propietario, usuario_nombre) == 0)
    {
        if (strcmp(permiso, "lectura") == 0 ||
            strcmp(permiso, "escritura") == 0 ||
            strcmp(permiso, "ejecucion") == 0)
        {
            return 1;
        }
    }

    return 0; // acceso denegado
}
