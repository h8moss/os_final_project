#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "usuarios.h"

std::vector<Usuario> usuarios;
int usuario_actual = -1;

void cargar_usuarios()
{
    std::ifstream archivo("usuarios.txt");
    if (!archivo)
    {
        std::cerr << "No se pudo abrir el archivo de usuarios.\n";
        return;
    }

    usuarios.clear();
    Usuario u;
    while (archivo >> u.nombre >> u.password >> u.es_root)
    {
        usuarios.push_back(u);
    }

    archivo.close();
}

bool login()
{
    std::string nombre, pass;
    std::cout << "=== Login ===\nUsuario: ";
    std::cin >> nombre;
    std::cout << "Contraseña: ";
    std::cin >> pass;

    for (size_t i = 0; i < usuarios.size(); ++i)
    {
        if (usuarios[i].nombre == nombre && usuarios[i].password == pass)
        {
            usuario_actual = static_cast<int>(i);
            std::cout << "Bienvenido, " << nombre << ".\n";
            return true;
        }
    }

    std::cout << "Login incorrecto.\n";
    return false;
}

bool verificar_permiso(const std::string &propietario, const std::string &permiso, const std::string &usuario_nombre)
{
    if (usuario_nombre == "root")
        return true;

    if (propietario == usuario_nombre)
    {
        if (permiso == "lectura" || permiso == "escritura" || permiso == "ejecucion")
        {
            return true;
        }
    }

    return false;
}
