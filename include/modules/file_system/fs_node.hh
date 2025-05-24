#pragma once
#include <string>

#include "modules/file_system/fs_metadata.hh"

using std::string;

namespace FileSystem {

class Directory; // Directory forward declaration

class Node {
protected:
  Directory *parent;

public:
  string name;
  Metadata metadata;

  Node(const string &name, Directory *parent);

  virtual ~Node() = default;
  virtual bool isDirectory() const = 0;
  virtual size_t getSize() const;

  Directory *getParent() const;
  void setParent(Directory *newParent);
};
} // namespace FileSystem
