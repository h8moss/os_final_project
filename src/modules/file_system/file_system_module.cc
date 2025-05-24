#include "modules/file_system/file_system_module.hh"
#include "modules/file_system/fs_file.hh"
#include <algorithm>
#include <memory>

namespace FileSystem {
vector<string> FileSystem::splitPath(const string &path) {
  vector<string> parts;
  stringstream ss(path);
  string part;

  while (getline(ss, part, '/')) {
    if (!part.empty()) {
      parts.push_back(part);
    }
  }

  return parts;
}

Node *FileSystem::resolvePath(const string &path) {
  if (path.empty())
    return currentDir;

  vector<string> parts = splitPath(path);
  Node *node = (path[0] == '/') ? root.get() : currentDir;

  for (const string &part : parts) {
    if (part == ".")
      continue;
    if (part == "..") {
      if (node->getParent()) {
        node = node->getParent();
      }
      continue;
    }

    if (!node->isDirectory())
      return nullptr;

    Directory *dir = static_cast<Directory *>(node);
    node = dir->getChild(part);
    if (!node)
      return nullptr;
  }

  return node;
}

FileSystem::FileSystem() {
  root = std::make_unique<Directory>("");
  currentDir = root.get();
}

string FileSystem::getCurrentPath() {
  vector<string> pathParts;
  Node *node = currentDir;

  while (node && node != root.get()) {
    pathParts.push_back(node->name);
    node = node->getParent();
  }

  std::reverse(pathParts.begin(), pathParts.end());

  if (pathParts.empty())
    return "/";

  string path;
  for (const string &part : pathParts) {
    path += "/" + part;
  }

  return path;
}

bool FileSystem::mkdir(const string &path) {
  vector<string> parts = splitPath(path);
  if (parts.empty())
    return false;

  string dirName = parts.back();
  parts.pop_back();

  Directory *parent = static_cast<Directory *>(
      resolvePath(parts.empty() ? "" : joinPath(parts)));

  if (!parent || !parent->isDirectory())
    return false;

  return parent->addChild(std::make_unique<Directory>(dirName, parent));
}

bool FileSystem::touch(const string &path) {
  vector<string> parts = splitPath(path);
  if (parts.empty())
    return false;

  string fileName = parts.back();
  parts.pop_back();

  Directory *parent = static_cast<Directory *>(
      resolvePath(parts.empty() ? "" : joinPath(parts)));

  if (!parent || !parent->isDirectory())
    return false;

  return parent->addChild(std::make_unique<File>(fileName, parent));
}

vector<string> FileSystem::ls(const string &path) {
  Node *node = resolvePath(path);
  if (!node)
    return {};

  if (node->isDirectory()) {
    Directory *dir = static_cast<Directory *>(node);
    return dir->listChildren();
  } else {
    return {node->name};
  }
}

string FileSystem::cat(const string &path) {
  Node *node = resolvePath(path);
  if (!node || node->isDirectory())
    return "";

  File *file = static_cast<File *>(node);
  return file->read();
}

bool FileSystem::empty(const string &path) {
  Node *node = resolvePath(path);
  if (!node || node->isDirectory())
    return false;

  File *file = static_cast<File *>(node);
  file->empty();
  return true;
}

bool FileSystem::append(const string &path, const string &content) {
  Node *node = resolvePath(path);
  if (!node || node->isDirectory())
    return false;

  File *file = static_cast<File *>(node);
  file->append(content);
  return true;
}

bool FileSystem::rm(const string &path) {
  vector<string> parts = splitPath(path);
  if (parts.empty())
    return false;

  string fileName = parts.back();
  parts.pop_back();

  Directory *parent = static_cast<Directory *>(
      resolvePath(parts.empty() ? "" : joinPath(parts)));

  if (!parent || !parent->isDirectory())
    return false;

  return parent->removeChild(fileName);
}

bool FileSystem::rmdir(const string &path) {
  Node *node = resolvePath(path);
  if (!node || !node->isDirectory())
    return false;

  Directory *dir = static_cast<Directory *>(node);
  if (!dir->listChildren().empty())
    return false;

  Directory *parent = dir->getParent();
  if (!parent)
    return false; // Can't remove root

  return parent->removeChild(dir->name);
}

bool FileSystem::cd(const string &path) {
  Node *target{resolvePath(path)};
  if (!target || !target->isDirectory())
    return false;
  currentDir = static_cast<Directory *>(target);
  return true;
}

string FileSystem::joinPath(const vector<string> &parts) {
  if (parts.empty())
    return "";

  string result;
  for (const string &part : parts) {
    result += "/" + part;
  }
  return result;
}

void FileSystem::printMetadata(const string &path) {
  Node *node = resolvePath(path);
  if (!node) {
    cout << "File or directory not found" << endl;
    return;
  }

  cout << "Name: " << node->name << endl;
  cout << "Type: " << (node->isDirectory() ? "Directory" : "File") << endl;
  cout << "Size: " << node->getSize() << " bytes" << endl;

  tm *creation_time = localtime(&node->metadata.creation_time);
  cout << "Created: " << put_time(creation_time, "%Y-%m-%d %H:%M:%S") << endl;

  tm *mod_time = localtime(&node->metadata.modification_time);
  cout << "Modified: " << put_time(mod_time, "%Y-%m-%d %H:%M:%S") << endl;
}

} // namespace FileSystem
