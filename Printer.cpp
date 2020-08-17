#include <iostream>
#include <regex>

#include "Printer.hpp"

std::string Printer::extractLaneName(std::string name) {
  std::string result;
  try {
    std::regex re("([0-9]+)");
    std::smatch match;
    if (std::regex_search(name, match, re) && match.size() > 1) {
      result = match.str(1);
    } else {
      result = std::string("");
    }
  } catch (std::regex_error& e) {
    std::cerr << "Syntax error in the regular expression";
  }

  return std::string("Lane " + result);
}

std::stringstream
Printer::generateSummary(std::map<std::string, std::string> results) {
  std::stringstream output;
  for (const auto& lane : results) {
    output << "### " << extractLaneName(lane.first) << ": " << interpreter.getGameStatus(lane.second) << " ###" << std::endl;
  }
  return output;
}

std::string Printer::summarizeLane(const std::string& lane) {
  std::string result;
  auto gamerResult{0};
  auto lines = interpreter.getVector(lane);
  for (const auto& line : lines) {
    Bowling game;
    auto record = interpreter.extractRecord(line);
    if (not record.first.empty()) {
      result += record.first + " ";
    }
    for (const auto&nextRoll : interpreter.processLaneRecordToRolls(record.second))
      game.roll(nextRoll);

    gamerResult = game.score();
    result += std::to_string(gamerResult) + '\n';
  }
  return result;
}
