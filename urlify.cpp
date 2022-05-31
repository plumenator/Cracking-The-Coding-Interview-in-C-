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

void urlify(std::string& text) {
  auto last = text.rbegin();
  for (; last != text.rend(); ++last) {
    if (*last != ' ') {
      break;
    }
  }
  for (auto i = text.rbegin(); i != text.rend(); ++i) {
    if (*last == ' ') {
      *i = '0';
      *(i + 1) = '2';
      *(i + 2) = '%';
      i += 2;
    } else {
      *i = *last;
    }
    ++last;
  }
}

int main() {     
  std::vector<std::string> lines;
  for (std::string line; std::getline(std::cin, line);) {
    lines.push_back(line);
  }

  for (auto line: lines) {
    std::cout << line << "<";
    urlify(line);
    std::cout << line << ">" << std::endl;
  }
}