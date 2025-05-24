#pragma once
#include <map>
#include <memory>
#include <vector>

#include "modules/file_system/fs_node.hh"

using std::map, std::vector;

namespace FileSystem {

class Directory : public Node {
private:
  map<string, std::unique_ptr<Node>> children;

public:
  Directory(const string &name, Directory *parent = nullptr);

  bool isDirectory() const override;
  size_t getSize() const override;

  bool addChild(std::unique_ptr<Node> node);
  bool removeChild(const string &name);
  Node *getChild(const string &name);
  vector<string> listChildren() const;
};

} // namespace FileSystem
