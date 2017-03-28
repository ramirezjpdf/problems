#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::vector<int> parsemsg(const std::string &msg, const int& length) {
  std::vector<int> idxs;
  int i = 0;
  int n = 0;
  int idx;
  while (n < length) {
    if (msg[i + 1] == ' ' || msg[i + 1] == '\0') {
	  idx = msg[i] - '0';
	  i += 2;
	} else {
	  idx = (msg[i] - '0') * 10 + msg[i + 1] -  '0';
	  i += 3;
	}
    idxs.push_back(idx);
	++n;
  }
  return idxs;
}

void decyphermsg(const std::string &msg, const std::string& bulbs, const int& l) {
  std::vector<int> idxs = parsemsg(msg, l);
  for (std::vector<int>::iterator i = idxs.begin();
      i != idxs.end(); ++i) {
    std::cout << bulbs[*i - 1];
  }
  std::cout << std::endl;
} 

int main() {
  std::string bulbs;
  std::string length;
  std::string msg;
  const std::string::size_type A = 26;
  
  while (std::getline(std::cin, bulbs)) {
    if (bulbs.size() == A) {
	  std::getline(std::cin, length);
	  int l;
	  std::stringstream(length) >> l;
	  
	  std::getline(std::cin, msg);
	  decyphermsg(msg, bulbs, l);
	}
  }
  
  return 0;
}