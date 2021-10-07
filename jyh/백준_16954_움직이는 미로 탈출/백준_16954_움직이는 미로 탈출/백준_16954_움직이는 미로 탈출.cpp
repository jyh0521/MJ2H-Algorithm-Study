#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <tuple>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define MAX 8

vector<string> v;
pair<int, int> start = { 7, 0 };

int dX[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dY[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };

bool visited[MAX][MAX][9];

bool bfs() {
	queue<tuple<int, int, int>> q;
	visited[start.first][start.second][0] = true;
	q.push({ start.first, start.second, 0 });

	while (!q.empty()) {
		int x, y, t;
		tie(x, y, t) = q.front();
		q.pop();

		if (t == 8) return true;

		// ¿Ãµø
		for (int i = 0; i < 8; i++) {
			int nX = x + dX[i];
			int nY = y + dY[i];

			if (!(0 <= nX && nX < MAX && 0 <= nY && nY < MAX)) continue;
			if (nX - t >= 0 && v[nX - t][nY] == '#') continue;
			if (nX - t - 1 >= 0 && v[nX - t - 1][nY] == '#') continue;
			if (visited[nX][nY][t + 1]) continue;

			visited[nX][nY][t + 1] = true;
			q.push({ nX, nY, t + 1 });
		}
	}

	return false;
}

int main() {
	for (int i = 0; i < MAX; i++) {
		string str;
		cin >> str;

		v.push_back(str);
	}

	bfs() ? cout << 1 << endl : cout << 0 << endl;

	return 0;
}