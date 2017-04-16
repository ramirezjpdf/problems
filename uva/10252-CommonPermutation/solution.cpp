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

void getpermutation(bloomfilter &bf ,string &s, vector<char> &perm) {
  for (string::iterator it = s.begin(); it != s.end(); ++it)
    If (isinbf(bf, *it))
      perm.push_back(*it);
}

void printbf(bloomfilter &bf) {
  for (bloomfilter::iterator it = bf.begin(); it != bf.end(); ++it)
    cout << " " << *it;
  cout << endl;
}

void test() {
  bloomfilter bf(ALPHABETSIZESIZE, false);
  string s0("walking");
  string s1("women");
  buildbf(bf, s0);
  printbf(bf);
  vector<char> perm;
  getpermutation(bf, s1, perm);
  sort(perm);
  cout << string(perm) << endl;
}

int main() {
  test();
  string s0;
  while(getline(cin, s0)) {
    string s1;
    getline(cin, other);

    bloomfilter bf(ALPHABETSIZESIZE, false);
    buildbf(bf, s0);
    printbf(bf);
    vector<char> perm;
    getpermutation(bf, s1, perm);
    sort(perm);
    cout << string(perm) << endl;
  }

  return 0;
}
