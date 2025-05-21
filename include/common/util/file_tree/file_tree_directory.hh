#pragma once
#include "common/util/file_tree/file_tree_node.hh"
#include <vector>

using std::vector;

class FileTreeDirectory : public FileTreeNode {
  vector<FileTreeNode> children;

  bool isDirectory() override;
};
