#pragma once
#include "common/util/file_tree/file_tree_node.hh"
#include <memory>
#include <vector>

using std::vector;

class FileTreeDirectory : public FileTreeNode {
public:
  vector<std::unique_ptr<FileTreeNode>> children;

  bool isDirectory() const override;
};
