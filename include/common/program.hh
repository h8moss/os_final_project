#pragma once
#include "common/modules/fs_module.hh"

class Program : public IFSModule {
public:
  Program();
  void main();

  // ----------- File System -----------
  void touch(string path) override;
  void mkdir(string path) override;
  void cat(string path) override;
  void ls(string path) override;
  void write_file(string path, string contents, bool append) override;
  void del(string path) override;
  void del_content(string path, int l, bool lines) override;
  void cd(string path) override;
  // -----------------------------------
};
