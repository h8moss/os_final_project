#include "common/program.hh"

void Program::touch(string path) {
    fileTree.createFile(path);
}

void Program::mkdir(string path) {}
void Program::cat(string path) {}
void Program::ls(string path) {}
void Program::write_file(string path, string contents) {}
void Program::write_append(string path, string contents) {}
void Program::del(string path) {}
void Program::del_content(string path, int n) {}
void Program::del_lines(string path, int n) {}
void Program::cd(string path) {}
