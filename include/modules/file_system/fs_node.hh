#pragma once
#include <string>

#include "modules/file_system/fs_metadata.hh"

using std::string;

namespace FileSystem {

class Directory; // Directory forward declaration

class Node {
protected:
  Directory *parent;
  string owner;

public:
  string name;
  Metadata metadata;

  Node(const string &name, const string &owner, Directory *parent);

  virtual ~Node() = default;
  virtual bool isDirectory() const = 0;
  virtual size_t getSize() const;

  Directory *getParent() const;
  void setParent(Directory *newParent);

  string getOwner() const;
};
} // namespace FileSystem
