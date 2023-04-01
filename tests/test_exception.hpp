#pragma once
#include <string>
#include <stdexcept>

class TestException : public std::runtime_error {
public:
  TestException(std::string msg) : std::runtime_error(msg) { }
};