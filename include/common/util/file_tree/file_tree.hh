#pragma once
#include "common/util/file_tree/file_tree_directory.hh"
#include "common/util/file_tree/file_tree_node.hh"
#include <memory>
#include <vector>
#include <string>

using std::vector;
using std::string;

class FileTree {
public:
  vector<std::unique_ptr<FileTreeNode>> root;
  vector<string> workingDir;

  FileTree();

  bool pathExists(string path) const;
  string getAbsolutePath(string path) const;
  string vectorToStringPath(const vector<string>& path) const;
  vector<string> stringPathToVector(string path) const;

  std::optional<std::reference_wrapper<FileTreeNode>> getNode(string path);

  void createFile(string path);
  void createDirectory(string path);
};
