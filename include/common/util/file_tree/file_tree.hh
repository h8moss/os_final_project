#pragma once
#include "common/util/file_tree/file_tree_directory.hh"
#include "common/util/file_tree/file_tree_node.hh"
#include <memory>
#include <stack>
#include <vector>

using std::stack;
using std::vector;

class FileTree {
public:
  vector<std::unique_ptr<FileTreeNode>> root;
  stack<int> workingDir;

  FileTree();

  bool pathExists(string path) const;
  string getAbsolutePath(string path) const;
  string stackToStringPath(stack<int> path) const;
  stack<int> stringPathToStack(string path) const;
};
