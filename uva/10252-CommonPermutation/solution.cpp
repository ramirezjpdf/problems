#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

const int ALPHABETSIZESIZE = 26;
typedef vector<int> bset;

int bsethash(char c) {
  return c - 'a';
}

void buildbset(bset &bs, string &s) {
  for (string::iterator it = s.begin(); it != s.end(); ++it)
    bs[bsethash(*it)] += 1;
}

bool isinbset(bset &bs, char c) {
  if (bs[bsethash(c)] > 0) {
    bs[bsethash(c)] -= 1;
	return true;
  }
  return false;
}

void getpermutation(bset &bs ,string &s, stringstream &perm) {
  for (string::iterator it = s.begin(); it != s.end(); ++it)
    if (isinbset(bs, *it)) {
      perm << (*it);
    }
}

void printbset(bset &bs) {
  for (bset::iterator it = bs.begin(); it != bs.end(); ++it)
    cout << " " << *it;
  cout << endl;
}

void printperm(string &s0, string &s1) {
  bset bs(ALPHABETSIZESIZE, 0);
  buildbset(bs, s0);
  stringstream permstream;
  getpermutation(bs, s1, permstream);
  string perm = permstream.str();
  sort(perm.begin(), perm.end());
  cout << perm << endl;
}

int main() {
  string s0;
  string s1;
  while(getline(cin, s0)) {
    getline(cin, s1);
	if (*(s0.end() - 1) == '\r')
	  s0.erase(s0.end() - 1);
	if (*(s1.end() - 1) == '\r')
	  s1.erase(s1.end() - 1);
    printperm(s0, s1);
  }

  return 0;
}