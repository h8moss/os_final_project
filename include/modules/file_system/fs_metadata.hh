#pragma once
#include <ctime>

namespace FileSystem {

struct Metadata {
  time_t creation_time;
  time_t modification_time;
  size_t size;
};

} // namespace FileSystem
