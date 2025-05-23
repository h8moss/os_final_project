#pragma once
#include <string>

using std::string;

class IFSModule {
  virtual void touch(string path) = 0;
  virtual void mkdir(string path) = 0;
  virtual void cat(string path) = 0;
  virtual void ls(string path) = 0;
  virtual void write_file(string path, string contents, bool append) = 0;
  virtual void del(string path) = 0;
  virtual void del_content(string path, int l, bool lines) = 0;

  virtual void cd(string path);
};
