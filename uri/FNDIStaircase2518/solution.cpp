#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>

int main() {

  std::string in;
  while (std::getline(std::cin, in)) {
    int steps;
	sscanf(in.c_str(), "%d", &steps);
	
	int h, c, l;
	std::getline(std::cin, in);
	sscanf(in.c_str(), "%d %d %d", &h, &c, &l);
	float area = (sqrt(c * c + h * h) * steps * l) / 1000;
	printf("%.4f\n", area);
  }
  return 0;
}
