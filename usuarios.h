#ifndef USUARIOS_H
#define USUARIOS_H

#define MAX_USUARIOS 10

typedef struct
{
    char nombre[20];
    char password[20];
    int es_root; // 1 si es root, 0 si es usuario normal
} Usuario;

extern Usuario usuarios[MAX_USUARIOS];
extern int total_usuarios;
extern int usuario_actual;

void cargar_usuarios();
int login();
int verificar_permiso(const char *propietario, const char *permiso, const char *usuario_actual);

#endif
