#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define MAX 101

int n, m;
int visited[MAX];
vector<vector<int>> v;

void bfs() {
	queue<int> q;
	q.push(0);
	visited[0] = true;

	while (!q.empty()) {
		int next = q.front();
		q.pop();

		for (int i = 0; i < v[next].size(); i++) {
			if (!visited[v[next][i]]) {
				visited[v[next][i]] = true;
				q.push(v[next][i]);
			}
		}
	}
}

int main() {
	FASTIO;

	cin >> n;
	cin >> m;

	v.resize(n);

	for (int i = 0; i < m; i++) {
		int node1, node2;
		cin >> node1 >> node2;

		node1--;
		node2--;

		v[node1].push_back(node2);
		v[node2].push_back(node1);
	}

	bfs();

	int result = 0;

	for (int i = 0; i < n; i++) {
		if (!visited[i]) continue;
		result++;
	}

	cout << result - 1 << endl;

	return 0;
}