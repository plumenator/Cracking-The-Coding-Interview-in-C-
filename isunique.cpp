#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <numeric>

template <typename StringIt>
bool occurs(char c, StringIt begin, StringIt end) {
  if (begin == end) {
    return false;
  }
  bool result = false;
  for (StringIt i = begin; i != end; ++i) {
    result |= *i == c;
  }
  return result;
}

template <typename StringIt>
bool isUniqueOccurs(StringIt begin, StringIt end) {
  if (begin == end) {
    return true;
  }
  auto curr = *begin;
  return !occurs(curr, begin + 1, end) && isUnique(begin + 1, end);
}

template <typename StringIt>
bool isUnique(StringIt begin, StringIt end) {
  if (begin == end) {
    return true;
  }
  auto curr = *begin;
  return !std::accumulate(begin + 1, end, false, [=](bool soFar, char c) {
    return soFar | c == curr;
  }) && isUnique(begin + 1, end);
}

bool isUnique(const std::string& input) {
  return isUnique(input.begin(), input.end());
}

bool isUniqueSet(const std::string& input) {
  std::set<char> chars;
  for (auto c: input) {
    chars.insert(c);
  }
  return input.size() == chars.size();
}

int main() {     
  std::vector<std::string> lines;
  for (std::string line; std::getline(std::cin, line);) {
    lines.push_back(line);
  }

  for (auto line: lines) {
    std::cout << line << ": " << (isUnique(line) ? "yes" : "no") << std::endl;
  }
}