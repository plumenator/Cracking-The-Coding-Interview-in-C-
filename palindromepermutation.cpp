#include <numeric>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cctype>
#include <list>

bool isPalindromePermutation(const std::string& text) {
  std::map<char, int> counts;
  for (auto c: text) {
    if (!std::isalnum(c)) {
      continue;
    }
    char lower = std::tolower(c);
    auto it = counts.find(lower);
    if (it == counts.end()) {
      counts.insert({lower, 1});
    } else {
      ++it->second;
    }
  }
  int rem_sum = std::accumulate(counts.begin(), counts.end(), 0, [] (int sofar, const auto& c) {
    return sofar + (c.second % 2);
  });
  return rem_sum == 1 || rem_sum == 0;
}

int main() {     
  std::vector<std::string> lines;
  for (std::string line; std::getline(std::cin, line);) {
    lines.push_back(line);
  }

  for (auto line: lines) {
    std::cout << line << ": " << (isPalindromePermutation(line) ? "yes" : "no") << std::endl;
  }
}