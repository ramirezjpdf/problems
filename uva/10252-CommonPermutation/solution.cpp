#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

const int ALPHABETSIZESIZE = 26;
typedef vector<bool> bset;

int bsethash(char c) {
  return c - 'a';
}

void buildbset(bset &bs, string &s) {
  for (string::iterator it = s.begin(); it != s.end(); ++it)
    bs[bsethash(*it)] = true;
}

bool isinbset(bset &bs, char c) {
  return bs[bsethash(c)];
}

void getpermutation(bset &bs ,string &s, stringstream &perm) {
  bset alreadyin(ALPHABETSIZESIZE, false);
  for (string::iterator it = s.begin(); it != s.end(); ++it)
    if (isinbset(bs, *it) &&
        !isinbset(alreadyin, *it)) {
      perm << (*it);
      alreadyin[bsethash(*it)] = true;
    }
}

void printbset(bset &bs) {
  for (bset::iterator it = bs.begin(); it != bs.end(); ++it)
    cout << " " << *it;
  cout << endl;
}

void printperm(string &s0, string &s1) {
  bset bs(ALPHABETSIZESIZE, false);
  buildbset(bs, s0);
  printbset(bs);
  stringstream permstream;
  getpermutation(bs, s1, permstream);
  string perm = permstream.str();
  sort(perm.begin(), perm.end());
  cout << perm << endl;
}

int main() {
  string s0("women");
  string s1("walking");
    
  printperm(s0, s1);

  while(getline(cin, s0)) {
    getline(cin, s1);
    printperm(s0, s1);
  }

  return 0;
}