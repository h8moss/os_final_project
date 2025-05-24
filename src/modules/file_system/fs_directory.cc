#include "modules/file_system/fs_directory.hh"
#include <memory>

namespace FileSystem {
Directory::Directory(const string &name, Directory *parent)
    : Node(name, parent) {}

bool Directory::isDirectory() const { return true; }

size_t Directory::getSize() const {
  size_t total = 0;
  for (const auto &child : children) {
    total += child.second->getSize();
  }
  return total;
}

bool Directory::addChild(std::unique_ptr<Node> node) {
  if (children.count(node->name) > 0) {
    return false; // Already exists
  }
  node->setParent(this);
  children[node->name] = std::move(node);
  metadata.modification_time = time(nullptr);
  return true;
}

bool Directory::removeChild(const string &name) {
  auto it = children.find(name);
  if (it == children.end()) {
    return false;
  }
  children.erase(it);
  metadata.modification_time = time(nullptr);
  return true;
}

Node *Directory::getChild(const string &name) {
  auto it = children.find(name);
  if (it == children.end()) {
    return nullptr;
  }
  return it->second.get();
}

vector<string> Directory::listChildren() const {
  vector<string> result;
  for (const auto &child : children) {
    result.push_back(child.first);
  }
  return result;
}

} // namespace FileSystem
