#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>


int main() {
  std::string in;
  
  while (std::getline(std::cin, in)) {
    int n, m;
	sscanf(in.c_str(), "%d %d", &n, &m);

	int mon[2];
	int me[2];	
	for (int i = 0; i < n; ++i) {
	  std::getline(std::cin, in);
	  int j = 0;
	  int k = 0;
	  while (j < m) {
	    if (in[k] == '1') {
		  me[0] = i;
		  me[1] = j;
		} else if (in[k] == '2') {
		  mon[0] = i;
		  mon[1] = j;
		}
        k += 2;
		++j;
	  }
	}
	std::cout << abs(me[0] - mon[0]) + abs(me[1] - mon[1]) << std::endl;
  }
  return 0;
}