#pragma once
#include "modules/file_system/fs_node.hh"

namespace FileSystem {
class File : public Node {
private:
  string content;

public:
  File(const string &name, const string &owner, Directory *parent = nullptr);
  bool isDirectory() const override;
  size_t getSize() const override;
  string read() const;
  void write(const string &data);
  void append(const string &data);
  void empty();
};
} // namespace FileSystem
