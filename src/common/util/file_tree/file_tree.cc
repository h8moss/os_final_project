#include "common/util/file_tree/file_tree.hh"
#include "common/util/file_tree/file_tree_directory.hh"
#include "common/util/path/get_path_segments.hh"
#include "common/util/user_exception.hh"
#include <memory>

FileTree::FileTree() : root{}, workingDir{} {}

bool FileTree::pathExists(string path) const {
  path = getAbsolutePath(path);
  return getNode(path).has_value();
}

string FileTree::getAbsolutePath(string path) const {
  if (path[0] == '/')
    return path;

  if (path == ".")
    return vectorToStringPath(workingDir);

  if (path == "..") {
    if (workingDir.empty())
      throw UserException("Non existant path",
                         "Cannot get parent directory of root");
    vector<string> parentPath = workingDir;
    parentPath.pop_back();
    return vectorToStringPath(parentPath);
  }

  if (path.substr(0, 2) == "./") {
    return vectorToStringPath(workingDir) + path.substr(1);
  }
  
  if (path.substr(0, 3) == "../") {
    if (workingDir.empty())
      throw UserException("Non existant path",
                         "Cannot get parent directory of root");
    vector<string> parentPath = workingDir;
    parentPath.pop_back();
    return vectorToStringPath(parentPath) + path.substr(2);
  }
  
  return vectorToStringPath(workingDir) + '/' + path;
}

string FileTree::vectorToStringPath(const vector<string>& path) const {
  if (path.empty())
    return "/";
    
  string result;
  for (const auto& segment : path) {
    result += "/" + segment;
  }
  return result;
}

vector<string> FileTree::stringPathToVector(string path) const {
  vector<string> result;
  if (path.empty() || path == "/")
    return result;
    
  // Remove leading slash if present
  if (path[0] == '/')
    path = path.substr(1);
    
  // Split path into segments
  size_t start = 0;
  size_t end = path.find('/');
  
  while (end != string::npos) {
    if (end > start)
      result.push_back(path.substr(start, end - start));
    start = end + 1;
    end = path.find('/', start);
  }
  
  // Add the last segment if there is one
  if (start < path.length())
    result.push_back(path.substr(start));
    
  return result;
}

std::optional<std::reference_wrapper<FileTreeNode>> FileTree::getNode(string path) {
  path = getAbsolutePath(path);
  vector<string> segments{Path::getPathSegments(path)};

  // Start from root
  FileTreeNode* current = nullptr;
  for (const auto& node : root) {
    if (node->name == segments[0]) {
      current = node.get();
      break;
    }
  }

  // If root node not found, return nullopt
  if (!current) {
    return std::nullopt;
  }

  // Traverse through path segments
  for (size_t i = 1; i < segments.size(); i++) {
    bool found = false;
    for (const auto& child : current->children) {
      if (child->name == segments[i]) {
        current = child.get();
        found = true;
        break;
      }
    }
    if (!found) {
      return std::nullopt;
    }
  }

  return std::ref(*current);
}


void FileTree::createFile(string path) {
  path = getAbsolutePath(path);
  vector<string> segments{Path::getPathSegments(path)};

  if (getNode(path).has_value()) {
    throw UserException("File already exists", "Cannot create file at path: " + path);
  } else {
    // Get the parent directory
    vector<string> parentPath{segments};
    parentPath.pop_back();
    // Check if parent directory exists
    auto parentResult = getNode(vectorToStringPath(parentPath));
    if (!parentResult.has_value()) {
      throw UserException("Parent directory does not exist", "Cannot create file at path: " + path);
    } else {
      // Create the file
      auto parent = parentResult.value().get();
      if (parent.isDirectory()) {
        parent.children.push_back(std::make_unique<FileTreeNode>(segments.back()));
      } else {
        throw UserException("Parent is not a directory", "Cannot create file at path: " + path);
      }
    }
  }
  
}
