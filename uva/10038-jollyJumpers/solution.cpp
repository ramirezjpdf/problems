#include <iostream>
#include <vector>
#include <stdlib.h>

bool isJollyJumper(std::vector<int>& seq) {
  std::vector<bool> bitmap(seq.size());
  for (std::vector<int>::iterator it = seq.begin(); it != seq.end() - 1; ++it) {
    int diff = abs(*it - *(it + 1));
	
	#ifdef DEBUG
	std::cout << "diff = " << diff << std::endl;
	#endif
	
	if (diff < 1 || diff > (seq.size() - 1) || bitmap[diff]) {
	  return false;
	}
	bitmap[diff] = true;
  }
  return true;
}

int main() {
  int n;
  while(std::cin >> n) {
    std::vector<int> seq(n);
    for (int i = 0; i < n; ++i) {
      int in;
      std::cin >> in;
      seq[i] = in;
    }
	
    #ifdef DEBUG
    for (std::vector<int>::iterator it = seq.begin(); it != seq.end(); ++it) {
      std::cout << *it << " ";
    }
    std::cout << std::endl;
    #endif
	
	if (isJollyJumper(seq)) {
	  std::cout << "Jolly" << std::endl;
	} else {
	  std::cout << "Not jolly" << std::endl;
	}
  }
  return 0;
}
