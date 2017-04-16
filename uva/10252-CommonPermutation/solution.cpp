#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int ALPHABETSIZESIZE = 26;
typedef vector<bool> bloomfilter;

int hash(char c) {
  return c - 'a';
}

void buildbf(bloomfilter &bf, string &s) {
  for (string::iterator it = s.begin(); it != s.end(); ++it)
    bf[hash(*it)] = true;
}

bool isinbf(bloomfilter &bf, char c) {
  return bf[hash(c)];
}

void getpermutation(bloomfilter &bf ,string &s, string &perm) {
  
}

void printbf(bloomfilter &bf) {
  for (bloomfilter::iterator it = bf.begin(); it != bf.end(); ++it)
    cout << " " << *it;
  cout << endl;
}

int main() {
  bloomfilter bf(ALPHABETSIZESIZE, false);
  string s("abc");
  buildbf(bf, s);
  printbf(bf);
  return 0;
}