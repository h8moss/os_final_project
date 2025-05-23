#include "common/util/file_tree/file_tree_file.hh"

FileTreeFile::FileTreeFile(string _name) : FileTreeNode(_name) {}

bool FileTreeFile::isDirectory() const { return false; }
