#ifndef USUARIOS_H
#define USUARIOS_H

#include <string>
#include <vector>

struct Usuario {
  std::string nombre;
  std::string password;
  int es_root;
};

extern std::vector<Usuario> usuarios;
extern int usuario_actual;

Usuario *get_current_user();
void cargar_usuarios();
bool login();
bool verificar_permiso(const std::string &propietario,
                       const std::string &permiso,
                       const std::string &usuario_nombre);

#endif
