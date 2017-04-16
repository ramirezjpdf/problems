#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

const int MAXV = 10000;
const int MAXDEGREE = 8;
const int DIGITS = 4;

struct graph {
  vector<vector<int> > edges;
  vector<int> degrees;
  int nvertices;
  int nedges;
  
  graph(): edges(vector<vector<int> >(MAXV, vector<int>(MAXDEGREE))),
      degrees(vector<int>(MAXV, 0)) {};
};

string itos(int n) {
  string s(DIGITS, '0');
  s[0] = n / 1000 + '0';
  s[1] = (n % 1000) / 100 + '0';
  s[2] = ((n % 1000) % 100) / 10 + '0';
  s[3] = ((n % 1000) % 100) % 10 + '0';
  return s;
}

int stoijp(string s) {
  stringstream ss(s);
  int i;
  ss >> i;
  return i;
}

int ctoi(char c) {
  return c - '0';
}

char itoc(int i) {
  return i + '0';
}

bool isin(int n, vector<bool> &restrictions) {
  return restrictions[n];
}

int digitdec(char c) {
  int d = ctoi(c) - 1;
  return d == -1 ? (d + 10) : d;
}

void makeedges(int node, vector<int> &edges, int &degree) {
  string s = itos(node);
  for (int i = 0; i < ((int)s.size()); i++) {
    char cur = s[i];
    char inc = itoc((ctoi(s[i]) + 1) % 10);
	char dec = itoc(digitdec(s[i]));
	
	s[i] = inc;
	edges[degree++] = stoijp(s);
	  
	s[i] = dec;
	edges[degree++] = stoijp(s);

	s[i] = cur;
  }
}

void makegraph(graph &g) {
  for (int i = 0; i < MAXV; i++) {
    makeedges(i, g.edges[i], g.degrees[i]);
  }
}

void printgraph(graph &g) {
  for (int i = 0; i < 10; i++) {
    cout << i << ":";
    for (int j = 0; j < g.degrees[i]; j++)
	  cout << " " << g.edges[i][j];
	cout << endl;
  }
}

int distancebfs(graph &g, vector<bool> &restrictions,
    int start, int target) {
  vector<bool> discovered(MAXV);
  vector<bool> processed(MAXV);
  vector<int> distances(MAXV, -1);
  queue<int> q;
  
  q.push(start);
  discovered[start] = true;
  distances[start] = 0;
  
  while(!q.empty()) {
    int v = q.front();
	q.pop();
	processed[v] = true;
	
	for (int i = 0; i < g.degrees[v]; ++i) {
	  if (!discovered[g.edges[v][i]] &&
	      !isin(g.edges[v][i], restrictions)) {
	    discovered[g.edges[v][i]] = true;
		q.push(g.edges[v][i]);
		distances[g.edges[v][i]] = distances[v] + 1;
	  }
	}
  }
  return distances[target];
}

void parseline(int &d) {
  d = 0;
  int j;
  for (int i = 0, alg = 1000; i < DIGITS; ++i, alg /= 10) {
    cin >> j;
	d += j * alg;
  }
}

void parsest(int &start, int &target) {
  start = 0;
  target = 0;
  parseline(start);
  parseline(target);
}

void parserestrictions(vector<bool> &restrictions, int n) {
  for (int i = 0; i < n; ++i) {
    int r = 0;
    parseline(r);
	restrictions[r] = true;
  }
}

int main() {
  int tests;
  cin >> tests;
  string line;
  
  vector<bool> *r = new vector<bool>(MAXV, false);
  graph g;
  makegraph(g);
  int s, t;
  for (int i = 0; i < tests; ++i) {
    parsest(s, t);
	int n;
	cin >> n;
	parserestrictions(*r, n);
	
    cout << distancebfs(g, *r, s, t) << endl;
	//printgraph(*g);
	
	delete r;
	r = new vector<bool>(MAXV, false);
	//getline(cin, line);
  }
  delete r;
  return 0;
}