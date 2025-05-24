#include "modules/file_system/fs_file.hh"

namespace FileSystem {

File::File(const string &name) : Node(name), content("") {}

bool File::isDirectory() const { return false; }

size_t File::getSize() const { return content.size(); }

string File::read() const { return content; }

void File::write(const string &data) {
  content = data;
  metadata.modification_time = time(nullptr);
  metadata.size = getSize();
}

void File::append(const string &data) {
  content += data;
  metadata.modification_time = time(nullptr);
  metadata.size = content.size();
}

void File::empty() {
  content.clear();
  metadata.modification_time = time(nullptr);
  metadata.size = 0;
}

} // namespace FileSystem
