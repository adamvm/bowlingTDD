#pragma once

#include <set>
#include <string>
#include <vector>
class Files {
public:
  Files(std::string resultsPath);
  std::set<std::string> listResultsFiles();
  std::string readFile(const std::string& filename);

private:
  std::string resultsPath_;
};
