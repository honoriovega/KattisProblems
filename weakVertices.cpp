#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

void findWeakVertices(int n, vector<int> &weakVertices);
vector<int> getNeighbors(int vertex, int **graph, int n);
int main() {

  int n;
  while (true) {
    cin >> n;
    if (n == -1)
      break;

    vector<int> weakVertices;

    findWeakVertices(n, weakVertices);

    sort(weakVertices.begin(), weakVertices.end());
    for (auto vertex : weakVertices) {
      cout << vertex << ' ';
    }
    cout << endl;
  }
}

void findWeakVertices(int n, vector<int> &weakVertices) {
  int **graph;
  graph = new int *[n];
  list<int> vertices;

  int temp;
  for (int i = 0; i < n; i++) {
    vertices.push_back(i);
    graph[i] = new int[n];
    for (int j = 0; j < n; j++) {
      cin >> temp;
      graph[i][j] = temp;
    }
  }

  while (vertices.size() != 0) {
    int current = vertices.front();
    vector<int> neighbors = getNeighbors(current, graph, n);

    if (neighbors.size() < 2) {

      weakVertices.push_back(current);
    } else {
      bool twoNeighborsConnected = false;
      for (int k = 0; k < neighbors.size(); k++) {
        for (int l = k + 1; l < neighbors.size(); l++) {
          if (graph[neighbors[k]][neighbors[l]]) {
            twoNeighborsConnected = true;

            vertices.remove(neighbors[l]);

            vertices.remove(neighbors[k]);

            break;
          }
        }
        if (twoNeighborsConnected)
          break;
      }
      if (!twoNeighborsConnected)
        weakVertices.push_back(current);
    }

    vertices.pop_front();
  }
}

vector<int> getNeighbors(int vertex, int **graph, int n) {
  vector<int> neighbors;
  for (int i = 0; i < n; i++) {
    if (i != vertex && graph[vertex][i] == 1) {
      neighbors.push_back(i);
    }
  }

  return neighbors;
}