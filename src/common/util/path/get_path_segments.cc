#include "common/util/path/get_path_segments.hh"
#include <sstream>

std::vector<std::string> getPathSegments(std::string path) {
  std::vector<std::string> components;
  std::istringstream iss{path.substr(1)}; // Remove leading '/'
  std::string component;

  while (getline(iss, component, '/')) {
    if (!component.empty()) { // Ignore empty components (e.g., double slashes)
      components.push_back(component);
    }
  }

  return components;
}
