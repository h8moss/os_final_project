#include "common/util/file_tree/file_tree.hh"
#include "common/util/file_tree/file_tree_directory.hh"
#include "common/util/path/get_path_segments.hh"
#include "common/util/user_exception.hh"
#include <memory>

FileTree::FileTree() : root{}, workingDir{} {}

bool FileTree::pathExists(string path) const {
  path = getAbsolutePath(path);
  vector<string> segments{Path::getPathSegments(path)};

  // Start from the root nodes
  const std::vector<std::unique_ptr<FileTreeNode>> *currentLevel = &root;

  for (size_t i = 0; i < segments.size(); i++) {
    const std::string &targetName = segments[i];
    bool found = false;

    // Search for the component in the current level
    for (const auto &node : *currentLevel) {
      if (node->name == targetName) {
        if (node->isDirectory()) {
          // Move to the next level
          const auto dir = dynamic_cast<const FileTreeDirectory *>(node.get());
          currentLevel = &dir->children;
          found = true;
          break;
        } else if (i == segments.size() - 1) {
          // Last component can be a file
          found = true;
          break;
        }
        // Not a directory and not the last component → invalid path
        return false;
      }
    }

    if (!found) {
      return false; // Component not found
    }
  }

  return true; // All components exist
}

string FileTree::getAbsolutePath(string path) const {
  if (path[0] == '/')
    return path;

  if (path == ".")
    return stackToStringPath(workingDir);

  if (path == "..") {
    std::stack<int> poppedStack{workingDir};
    if (poppedStack.size() < 1)
      throw UserException("Non existant path",
                          "Cannot get parent directory of root");
    poppedStack.pop();
    return stackToStringPath(poppedStack);
  }

  if (path.substr(0, 2) == "./") {
    return stackToStringPath(workingDir) + path.substr(1);
  }
  if (path.substr(0, 3) == "../") {
    std::stack<int> poppedStack{workingDir};
    if (poppedStack.size() < 1)
      throw UserException("Non existant path",
                          "Cannot get parent directory of root");
    poppedStack.pop();
    return stackToStringPath(poppedStack) + path.substr(2);
  }
  return stackToStringPath(workingDir) + '/' + path;
}

string FileTree::stackToStringPath(stack<int> path) const {}
stack<int> FileTree::stringPathToStack(string path) const {}
