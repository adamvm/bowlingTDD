#pragma once
#include <map>
#include <string>
#include <utility>
#include <vector>
class Interpreter {
public:
  std::pair<std::string, std::string> extractRecord(std::string input);
  std::vector<int> processLaneRecordToRolls(std::string input);
  std::string getGameStatus(std::string lane);
  bool isFinished(std::string lane);
  [[nodiscard]] std::vector<std::string>
  getVector(const std::string &lane) const;

private:
  std::map<std::string, std::string> matchFinish{
      {"regularEnd", R"(([^X]\|\|$))"},
      {"perfectFinish", R"((X\|\|XX))"},
      {"endWithSpare", R"((\|\|\d/))"},
      {"lastBallMiss", R"((X\|\|\d-|X\|\|\d\d))"},
      {"twoHits", R"((X\|\|\d\d))"}};
  [[nodiscard]] bool isSingleGamerFinished(std::string) const;
};
