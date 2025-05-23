#include "common/util/file_tree/file_tree_directory.hh"

bool FileTreeDirectory::isDirectory() const { return true; }

FileTreeDirectory::FileTreeDirectory(string _name) : FileTreeNode(_name) {}
