#include "program.hh"

vector<string> Program::tokenize(const string &input) const {
  vector<string> tokens;
  string token;
  bool inQuotes = false;

  for (char c : input) {
    if (c == '"') {
      inQuotes = !inQuotes;
    } else if (isspace(c) && !inQuotes) {
      if (!token.empty()) {
        tokens.push_back(token);
        token.clear();
      }
    } else {
      token += c;
    }
  }

  if (!token.empty()) {
    tokens.push_back(token);
  }

  return tokens;
}

void Program::run() {
  cout << "Type 'exit' to quit." << endl;

  while (true) {
    cout << fs.getCurrentPath() << "> ";
    string input;
    getline(cin, input);

    if (input.empty())
      continue;
    if (input == "exit")
      break;

    vector<string> tokens = tokenize(input);
    if (tokens.empty())
      continue;

    string command = tokens[0];
    try {
      if (command == "mkdir" && tokens.size() > 1) {
        if (!fs.mkdir(tokens[1])) {
          cout << "Error creating directory" << endl;
        }
      } else if (command == "touch" && tokens.size() > 1) {
        if (!fs.touch(tokens[1])) {
          cout << "Error creating file" << endl;
        }
      } else if (command == "ls") {
        string path = tokens.size() > 1 ? tokens[1] : "";
        vector<string> contents = fs.ls(path);
        for (const string &item : contents) {
          cout << item << endl;
        }
      } else if (command == "cat" && tokens.size() > 1) {
        cout << fs.cat(tokens[1]) << endl;
      } else if (command == "empty" && tokens.size() > 1) {
        if (!fs.empty(tokens[1])) {
          cout << "Error emptying file" << endl;
        }
      } else if (command == "append" && tokens.size() > 2) {
        if (!fs.append(tokens[1], tokens[2])) {
          cout << "Error appending to file" << endl;
        }
      } else if (command == "rm" && tokens.size() > 1) {
        if (!fs.rm(tokens[1])) {
          cout << "Error removing file" << endl;
        }
      } else if (command == "rmdir" && tokens.size() > 1) {
        if (!fs.rmdir(tokens[1])) {
          cout << "Error removing directory" << endl;
        }
      } else if (command == "meta" && tokens.size() > 1) {
        fs.printMetadata(tokens[1]);
      } else if (command == "cd" && tokens.size() > 1) {
        fs.cd(tokens[1]);
      } else {
        cout << "Unknown command or invalid arguments" << endl;
      }
    } catch (const exception &e) {
      cout << "Error: " << e.what() << endl;
    }
  }
}
