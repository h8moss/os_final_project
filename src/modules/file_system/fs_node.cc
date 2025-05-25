#include "modules/file_system/fs_node.hh"

namespace FileSystem {

Node::Node(const string &name, const string &owner, Directory *directory)
    : name{name}, parent{directory}, owner{owner} {
  time_t now = time(nullptr);
  metadata.creation_time = now;
  metadata.modification_time = now;
  metadata.size = 0;
}

size_t Node::getSize() const { return 0; }

Directory *Node::getParent() const { return parent; }
void Node::setParent(Directory *newParent) { parent = newParent; }

string Node::getOwner() const { return owner; }

} // namespace FileSystem
