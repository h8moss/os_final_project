#pragma once
#include "common/util/file_tree/file_tree_node.hh"
#include <map>

class FileTreeFile : public FileTreeNode {
  std::map<string, string> metadata;
  string contents;

  bool isDirectory() const override;
};
