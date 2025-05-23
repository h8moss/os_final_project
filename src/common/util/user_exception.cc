#include "common/util/user_exception.hh"

UserException::UserException(string _msg, string _title)
    : message{_msg}, title{_title} {}
const char *UserException::what() const noexcept {
  static const string what_str{title + ": " + message};

  return what_str.c_str();
}
