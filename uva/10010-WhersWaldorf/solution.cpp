#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>

#define MMAX 50
#define NMAX 50

void to_lower(char* str) {
  for (int i = 0; str[i] != '\0'; i++) {
    str[i] = (str[i] >= 'A' && str[i] <= 'Z') ?
	  str[i] - 'A' + 'a' : str[i];
   }
}

void get_grid(std::vector<char*>& grid, int m, int n) {
  char line[NMAX + 1];
  #ifdef D
  std:: cout << "get_grid: m = " << m << std::endl;
  #endif
  for (int i = 0; i < m; i++) {
    scanf("%s\n", line);
	#ifdef D
	printf("%s\n", line);
	#endif
	to_lower(line);
	strcpy(grid[i], line);
  }
}

void print_grid(std::vector<char*>& grid, int m, int n) {
  for (std::vector<char*>::iterator it = grid.begin(); it != grid.end();
   ++it)
     printf("%s\n", *it);
}

bool strcontains(const char* str, const char* word, int& fpos) {
  std::string s(str);
  fpos = (int) s.find(word);
  #ifdef D2
  std::cout << "in " << str << " find " << word << std::endl;
  std::cout << "fpos = " << fpos << std::endl;
  #endif
  return fpos != (int) std::string::npos;
}

std::string* strreverse(char* str) {
  std::string* s = new std::string(str);
  std::reverse(s->begin(), s->end());
  return s;
}

void find_word_in_grid(std::vector<char*> grid, char* word, int m, int n) {
  int row, col;
  
  #ifdef D
  std::cout << "== FIND IN ROW ==" << std::endl;
  #endif
  // search rows
  for (int i = 0; i < m; i++) {
    if (strcontains(grid[i], word, col)) {
	  row = i;
	  std::cout << row << " " << col << std::endl;
	  break;
	}
	std::string* reversed = strreverse(grid[i]);
	if (strcontains(reversed->c_str(), word, col)) {
	  row = i;
	  col = col + reversed->size() - 1;
	  delete reversed;
	  break;
	}
  }
  // search columns
  #ifdef D
  std::cout << "== FIND IN COLUMN ==" << std::endl;
  #endif
  char grid_word[MMAX + 1];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
	  grid_word[j] = grid[j][i];
	}
	grid_word[m] = '\0';
	if (strcontains(grid_word, word, row)) {
	  col = i;
	  std::cout << row << " " << col << std::endl;
	  break;
	}
  }
  // search diagonals
  #ifdef D
  std::cout << "== FIND IN DIAGONALS ==" << std::endl;
  #endif
  for (int i = 0; i < n; i++) {
    int k = i;
	int j = 0;
    while (j < m && (grid[j][k] != '\0')) {
	  grid_word[j] = grid[j][k];
	  j++;
	  k++;
	}
	grid_word[j] = '\0';
	#ifdef D
	std::cout << grid_word << std::endl;
	#endif
	if (strcontains(grid_word, word, row)) {
	  col = i + row;
	  std::cout << row << " " << col << std::endl;
	  break;
	}
  }
  
  for (int j = 0; j < m; j++) {
	int k = j;
    int i = 0;
    while (k < m && grid[k][i]!= '\0') {
	  grid_word[i] = grid[k][i];
	  i++;
	  k++;
	}
	grid_word[i] = '\0';
	#ifdef D
	std::cout << grid_word << std::endl;
	#endif
	if (strcontains(grid_word, word, col)) {
	  row = j + col;
	  std::cout << row << " " << col << std::endl;
	  break;
	}
  }
}

int main() {
  int cases;
  std::cin >> cases;
  std::string line;
  
  std::getline(std::cin, line);
  for (int i = 0; i < cases; ++i) {
    int m, n;
	scanf("%d %d\n", &m, &n);
	std::vector<char*> grid(m);
	for (int i = 0; i < m; i++)
	   grid[i] = new char[NMAX + 1];
	
	get_grid(grid, m, n);
	#ifdef D
	print_grid(grid, m, n);
	#endif
	
	int l;
	std::cin >> l;
	char word[NMAX];
	for (int i = 0; i < l; i++) {
	  scanf("%s\n", word);
	  #ifdef D
	  std::cout << word << std::endl;
	  #endif
	  to_lower(word);
	  find_word_in_grid(grid, word, m, n);
	}
	for (std::vector<char*>::iterator it = grid.begin(); it != grid.end();
	 ++it)
	   delete [] *it;
  }

  return 0;
}