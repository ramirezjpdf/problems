#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXV      = 200;
const int MAXDEGREE = 200;

struct graph{
  vector<vector<int> > edges;
  vector<int> degrees;
  int nvertices;
  int nedges;
  
  graph() : edges(MAXV, vector<int>(MAXDEGREE)),
      degrees(MAXV, 0) {}
};

void insertedge(graph &g, int x, int y, bool directed) {
  if (g.degrees[x] > MAXDEGREE) {
    cout << "Warning: insertion(" << x << ", " << y;
	cout << " exceeds max degrees" << endl;
  }
  
  g.edges[x][g.degrees[x]] = y;
  g.degrees[x]++;
  
  if (directed) insertedge(g, y, x, false);
  else g.nedges++;
}

bool readgraph(graph &g, bool directed) {
  int m;
  int x, y;
  
  cin >> g.nvertices >> m;
  if (g.nvertices == 0) return false;
  
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
	insertedge(g, x, y, directed);
  }
  
  return true;
}

void printgraph(graph &g) {
  for (vector<vector<int> >::iterator it = g.edges.begin();
      it != g.edges.end(); ++it) {
	cout << (it - g.edges.begin())  << ":";
	for (vector<int>::iterator it2 = (*it).begin();
	    it2 != (*it).end(); ++it2) {
	  cout << " " << *it2;	
    }
	cout << endl;
  }
}

const int RED = 2;
const int BLUE = 3;
const int UNCOLOR = 0;

int ccolor(int color) {
  if (color == RED) return BLUE;
  if (color == BLUE) return RED;
  if (color = UNCOLOR) return UNCOLOR;
}

bool bicoloredbfs(graph g, int start) {
  vector<bool> discovered(g.nvertices, false);
  vector<bool> processed(g.nvertices, false);
  bool bicolored = true;
  
  vector<int> colors(g.nvertices, UNCOLOR);
  queue<int> q;
  
  q.push(start);
  discovered[start] = true;
  colors[start] = RED;
  
  while(!q.empty()) {
    int v = q.front();
	q.pop();
	processed[v] = true;
	for (int i = 0; i < g.degrees[v]; i++) {
	  if (!discovered[g.edges[v][i]]) {
	    q.push(g.edges[v][i]);
		discovered[g.edges[v][i]] = true;
		colors[g.edges[v][i]] = ccolor(colors[v]);
	  } else {
	    if (colors[v] == colors[g.edges[v][i]]) {
		  bicolored = false;
		  return bicolored;
		}
	  }
	}
  }
  
  return bicolored;
}

int main() {
  graph *g = new graph();
  while (readgraph(*g, false)) {
    if (bicoloredbfs(*g, 0))
      cout << "BICOLORABLE." << endl;
    else
      cout << "NOT BICOLORABLE." << endl;
	delete g;
	g = new graph();
  }
  delete g;
  return 0;
}