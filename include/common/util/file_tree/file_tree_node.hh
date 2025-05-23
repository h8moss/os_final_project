#pragma once
#include <string>

using std::string;

class FileTreeNode {
public:
  string name;
  unsigned long creationTime;

  FileTreeNode(string _name);

  virtual bool isDirectory() const = 0;
};
