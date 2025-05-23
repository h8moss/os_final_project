#pragma once
#include <string>

using std::string;

class IFSModule {
public:
  virtual void touch(string path) = 0;
  virtual void mkdir(string path) = 0;
  virtual void cat(string path) = 0;
  virtual void ls(string path) = 0;
  virtual void write_file(string path, string contents) = 0;
  virtual void write_append(string path, string contents) = 0;
  virtual void del(string path) = 0;
  virtual void del_content(string path, int n) = 0;
  virtual void del_lines(string path, int n) = 0;
  virtual void cd(string path) = 0;
};
