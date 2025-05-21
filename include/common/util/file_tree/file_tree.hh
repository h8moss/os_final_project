#include "common/util/file_tree/file_tree_directory.hh"
#include "common/util/file_tree/file_tree_node.hh"
class FileTree {
  FileTreeDirectory root;

  bool pathExists(string path);
  FileTreeNode nodeFromPath(string path);
};
