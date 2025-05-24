#pragma once
#include <exception>
#include <iostream>
#include <string>
#include <vector>

#include "modules/file_system/file_system_module.hh"

using std::string, std::vector, std::cout, std::cin, std::endl, std::exception;

class Program {
private:
  FileSystem::FileSystem fs;

  vector<string> tokenize(const string &input) const;

public:
  void run();
};
