#include <iostream>
#include "usuarios.h"

int main()
{
    cargar_usuarios();

    if (!login())
        return 1;

    // Simula un archivo propiedad de "juan"
    std::string propietario = "juan";
    std::string permiso = "lectura";
    std::string usuario_nombre = usuarios[usuario_actual].nombre;

    if (verificar_permiso(propietario, permiso, usuario_nombre))
    {
        std::cout << "Tienes permiso para leer el archivo.\n";
    }
    else
    {
        std::cout << "No tienes permiso para leer el archivo.\n";
    }

    return 0;
}
