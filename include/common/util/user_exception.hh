#pragma once
#include <exception>
#include <string>

using std::string;

class UserException : public std::exception {
public:
  string message;
  string title;

  UserException(string _msg, string _title);
  const char *what() const noexcept override;
};
