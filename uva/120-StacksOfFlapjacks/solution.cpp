#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<int>::iterator findmaxpos(vector<int>& v, vector<int>::iterator& end) {
  vector<int>::iterator maxpos = v.begin();
  for (vector<int>::iterator it = v.begin(); it != end; ++it) {
    if (*it > *maxpos) {
	  maxpos = it;
	}
  }
  return maxpos;
}

void flip(vector<int>& v, vector<int>::iterator pos) {
  reverse(v.begin(), pos);
}

void sortpanck(vector<int> &panck, vector<int> &sorted) {
  int flipscount = 0;
  vector<int>::iterator pos = panck.end();
  while (panck != sorted && pos != panck.begin()) {
    vector<int>::iterator maxpos = findmaxpos(panck, pos);
	if (maxpos != panck.begin()) {
	  cout << (panck.end() - maxpos) << " ";
      flip(panck, maxpos + 1);
	}
	cout << (panck.end() - (pos - 1)) << " ";
    flip(panck, pos);
	--pos;
  }
  cout << 0 << endl;
}

void parseline(string& line, vector<int>& v) {
  stringstream ss(line);
  int i;
  while (ss >> i) {
    v.push_back(i);
  }
}

int main() {  
  string line;
  while (getline(cin, line)) {
    cout << line << endl;
    vector<int> v;
	parseline(line, v);
    vector<int> sorted(v);
    sort(sorted.begin(), sorted.end());
    sortpanck(v, sorted);
  }
  
  //for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
  //  cout << *it << " ";
  //}
  //cout << endl;
  return 0;
}