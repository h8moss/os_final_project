#include "common/program.hh"
#include <iostream>
#include <string>
#include <functional>
#include <unordered_map>

Program::Program() {
  // Initialize command map
  commands = {
    // --------------- File System ---------------
    {"touch", [this](const vector<string>& args) { touch(args[1]); }},
    {"mkdir", [this](const vector<string>& args) { mkdir(args[1]); }},
    {"cat", [this](const vector<string>& args) { cat(args[1]); }},
    {"ls", [this](const vector<string>& args) { ls(args[1]); }},
    {"write", [this](const vector<string>& args) { write_file(args[1], args[2]); }},
    {"write-append", [this](const vector<string>& args) { write_append(args[1], args[2]); }},
    {"del", [this](const vector<string>& args) { del(args[1]); }},
    {"del-content", [this](const vector<string>& args) { del_content(args[1], stoi(args[2])); }},
    {"del-lines", [this](const vector<string>& args) { del_lines(args[1], stoi(args[2])); }},
    {"cd", [this](const vector<string>& args) { cd(args[1]); }}
    // ------------------------------------------
  };
}

void Program::main() {
  std::cout << fileTree.vectorToStringPath(fileTree.workingDir) << "> ";

  while (true) {
    vector<string> command = getCommand();
    if (command[0] == "exit") {
      break;
    }

    // Execute command if it exists in the map
    auto it = commands.find(command[0]);
    if (it != commands.end()) {
      it->second(command);
    }
  }
}

vector<string> Program::getCommand() {
  string input;
  std::getline(std::cin, input);
  
  vector<string> args;
  string current;
  bool inQuotes = false;
  
  for (char c : input) {
    if (c == '"') {
      inQuotes = !inQuotes;
    } else if (c == ' ' && !inQuotes) {
      if (!current.empty()) {
        args.push_back(current);
        current.clear();
      }
    } else {
      current += c;
    }
  }
  
  if (!current.empty()) {
    args.push_back(current);
  }
  
  return args;
}
