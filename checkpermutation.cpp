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

auto identity = [](auto s) {
    return s; 
};

template<typename T>
std::vector<T> split(std::string line, const std::string& delim, auto toT(std::string) -> T) {
  std::vector<T> out;
  for (;;) {
    if(auto delim_position = line.find(delim);
          delim_position != std::string::npos) {
      out.push_back(toT(line.substr(0, delim_position)));
      line = line.substr(delim_position + delim.size());
    } else {
    break;
    }
  }
  out.push_back(toT(line));
  return out;
}

template<typename T>
std::vector<T> split(std::string line, const std::string& delim) {
  return split<T>(line, delim, identity);
}

template<typename T>
std::vector<T> split(std::string line) {
  return split<T>(line, " ");
}

bool isPermutation(const std::string& one, const std::string& other) {
  std::multiset<char> one_count, other_count;
  one_count.insert(one.begin(), one.end());
  other_count.insert(other.begin(), other.end());
  return one_count == other_count;
}

bool isPermutationSort(const std::string& one, const std::string& other) {
  std::string sorted_one {one}, sorted_other{other};
  std::sort(sorted_one.begin(), sorted_one.end());
  std::sort(sorted_other.begin(), sorted_other.end());
  return sorted_one == sorted_other;
}

int main() {     
  std::vector<std::string> lines;
  for (std::string line; std::getline(std::cin, line);) {
    lines.push_back(line);
  }

  for (auto line: lines) {
    auto pair = split<std::string>(line);
    std::cout << line << ": " << (isPermutation(pair[0], pair[1]) ? "yes" : "no") << std::endl;
  }
}