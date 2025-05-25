#include "modules/file_system/file_system_module.hh"
#include "program.hh"

int main() {
  cargar_usuarios();

  Program program{};
  program.run();

  return 0;
}
