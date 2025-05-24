#pragma once
#include <iomanip>
#include <iostream>
#include <sstream>

#include "modules/file_system/fs_directory.hh"

using std::stringstream, std::cout, std::endl, std::put_time;

namespace FileSystem {

class FileSystem {
private:
  std::unique_ptr<Directory> root;
  Directory *currentDir;

  vector<string> splitPath(const string &path);

  Node *resolvePath(const string &path);

public:
  FileSystem();

  bool mkdir(const string &path);
  bool touch(const string &path);
  vector<string> ls(const string &path = "");
  string cat(const string &path);
  bool empty(const string &path);
  bool append(const string &path, const string &content);
  bool rm(const string &path);
  bool rmdir(const string &path);
  bool cd(const string &path);

  string getCurrentPath();
  string joinPath(const vector<string> &parts);
  void printMetadata(const string &path);
};
} // namespace FileSystem
