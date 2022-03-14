#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define MAX 100

int n, answer = 1, maxHeight = -1;
int arr[MAX][MAX];
bool visited[MAX][MAX];

int dX[4] = { 1, -1, 0, 0 };
int dY[4] = { 0, 0, 1, -1 };

void bfs(int x, int y, int h) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = true;

	while (!q.empty()) {
		int nowX = q.front().first;
		int nowY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nX = nowX + dX[i];
			int nY = nowY + dY[i];

			if (!(0 <= nX && nX < n && 0 <= nY && nY < n)) continue;
			if (visited[nX][nY] || arr[nX][nY] <= h) continue;

			visited[nX][nY] = true;
			q.push({ nX, nY });
		}
	}
}

int main() {
	FASTIO;

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (maxHeight < arr[i][j])
				maxHeight = arr[i][j];
		}
	}

	for (int h = 1; h <= maxHeight; h++) {
		int saveArea = 0;
		memset(visited, false, sizeof(visited));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j] || arr[i][j] <= h) continue;
				saveArea++;
				bfs(i, j, h);
			}
		}

		if (answer < saveArea)
			answer = saveArea;
	}

	cout << answer << endl;

	return 0;
}