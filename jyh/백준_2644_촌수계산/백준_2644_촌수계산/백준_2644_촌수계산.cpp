#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define MAX 100

int n;
int startNode, endNode;
bool visited[MAX];

vector<vector<int>> v;

void bfs() {
	queue<pair<int, int>> q;
	q.push({ startNode, 0 });
	visited[startNode] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int cost = q.front().second;
		q.pop();

		if (x == endNode) {
			cout << cost << endl;
			return;
		}

		for (int i = 0; i < v[x].size(); i++) {
			int nX = v[x][i];
			
			if (visited[nX]) continue;

			visited[nX] = true;
			q.push({ nX, cost + 1 });
		}
	}

	cout << -1 << endl;
	return;
}

int main() {
	FASTIO;

	int m;

	cin >> n;
	cin >> startNode >> endNode;
	cin >> m;

	startNode--;
	endNode--;

	v.resize(n);

	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;

		s--;
		e--;

		v[s].push_back(e);
		v[e].push_back(s);
	}

	bfs();

	return 0;
}