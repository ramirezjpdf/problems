#include <iostream>

int makeSequence(int n) {
  #ifdef DEBUG
  std::cout << std::endl;
  std::cout << "========" << std::endl;
  #endif
  int i;
  #ifdef DEBUG
  std::cout << n << " ";
  #endif
  for (i = 1; n > 1; ++i) {
    n = ((n & 0x1) == 0) ? n >> 1 : (n + (n << 1)) + 1;
	#ifdef DEBUG
    std::cout << n << " ";
	#endif
  }
  #ifdef DEBUG
  std::cout << n << std::endl;
  std::cout << "========" << std::endl;
  #endif
  return i;
}

int main() {
  int i, j;
  while(std::cin >> i >> j) {
    std::cout << i << " " << j << " ";
	if (i > j) {
	  i = i ^ j;
	  j = i ^ j;
	  i = i ^ j;
	}
    int maxcycle = 0;
    for (; i <= j; ++i) {
	  int cycle = makeSequence(i);
	  maxcycle = (cycle > maxcycle) ? cycle : maxcycle;
	}
	std::cout << maxcycle << std::endl;
  }
  return 0;
}