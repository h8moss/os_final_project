#include "common/program.hh"
#include <iostream>
#include <string>

Program::Program() {}

void Program::main() {
  std::cout << "$> ";
  std::string line{};
  std::getline(std::cin, line);
}
