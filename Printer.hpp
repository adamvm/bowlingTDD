#pragma once

#include <string>

#include "Bowling.hpp"
#include "Interpreter.hpp"

class Printer {
public:
  std::string extractLaneName(std::string name);
  std::stringstream generateSummary(std::map<std::string, std::string> results);

  std::string summarizeLane(const std::string& lane);

private:
  Interpreter interpreter;
};
