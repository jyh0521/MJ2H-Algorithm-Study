#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define MAX 50

int n, m;
bool visited[MAX][MAX];
string str[MAX];

int answer = 0;

int dX[4] = { 1, -1, 0, 0 };
int dY[4] = { 0, 0, 1, -1 };

void bfs(int sX, int sY) {
	memset(visited, false, sizeof(visited));
	queue<tuple<int, int, int>> q;
	q.push({ sX, sY, 0 });
	visited[sX][sY] = true;

	while (!q.empty()) {
		int x, y, cost;
		tie(x, y, cost) = q.front();
		q.pop();

		if (answer < cost)
			answer = cost;

		for (int i = 0; i < 4; i++) {
			int nX = x + dX[i];
			int nY = y + dY[i];

			if (!(0 <= nX && nX < n && 0 <= nY && nY < m)) continue;
			if (visited[nX][nY]) continue;
			if (str[nX][nY] == 'W') continue;

			visited[nX][nY] = true;
			q.push({ nX, nY, cost + 1 });
		}
	}

	return;
}

int main() {
	FASTIO;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> str[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (str[i][j] == 'W')  continue;
			bfs(i, j);
		}
	}

	cout << answer << endl;

	return 0;
}