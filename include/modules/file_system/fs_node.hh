#pragma once
#include <string>

#include "modules/file_system/fs_metadata.hh"

using std::string;

namespace FileSystem {

class Node {
public:
  string name;
  Metadata metadata;

  Node(const string &name);

  virtual ~Node() = default;
  virtual bool isDirectory() const = 0;
  virtual size_t getSize() const;
};
} // namespace FileSystem
