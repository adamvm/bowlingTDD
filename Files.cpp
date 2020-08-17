#include "Files.hpp"
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <utility>

Files::Files(std::string resultsPath) : resultsPath_(std::move(resultsPath)) {}

std::set<std::string> Files::listResultsFiles() {

  std::filesystem::path p(resultsPath_);
  std::filesystem::directory_iterator start(p);
  std::filesystem::directory_iterator end;
  std::set<std::string> result;

  std::for_each(start, end, [&result](auto file) {
    result.emplace(file.path().filename().string());
  });

  return result;
}

std::string Files::readFile(const std::string &filename) {
  std::string result;
  std::string file{resultsPath_ + "/" + filename};
  std::ifstream input(file);

  input.seekg(0, std::ios::end);
  result.reserve(input.tellg());
  input.seekg(0, std::ios::beg);

  result.assign((std::istreambuf_iterator<char>(input)),
                std::istreambuf_iterator<char>());

  return result;
}
