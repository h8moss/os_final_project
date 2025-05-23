#pragma once
#include "common/modules/fs_module.hh"
#include <vector>
#include <string>
#include <functional>
#include <unordered_map>

class Program : public IFSModule {
public:
  Program();
  void main();

  vector<string> getCommand();

  // ----------- File System -----------
  void touch(string path) override;
  void mkdir(string path) override;
  void cat(string path) override;
  void ls(string path) override;
  void write_file(string path, string contents) override;
  void write_append(string path, string contents) override;
  void del(string path) override;
  void del_content(string path, int n) override;
  void del_lines(string path, int n) override;
  void cd(string path) override;
  // -----------------------------------

private:
  // Map of command names to their handler functions
  std::unordered_map<std::string, std::function<void(const std::vector<std::string>&)>> commands;
};
