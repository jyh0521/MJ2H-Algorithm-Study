#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define MAX 1000

int n, m;
int arr[MAX][MAX];
int result = 99999999;
bool visited[MAX][MAX][2];

int dX[4] = { 1, -1, 0, 0 };
int dY[4] = { 0, 0, 1, -1 };

void bfs() {
	// x, y, cost, 벽을 부순 횟수
	queue<tuple<int, int, int, int>> q;
	q.push({ 0, 0, 1, 0 });
	visited[0][0][0] = true;
	
	while (!q.empty()) {
		int x, y, cost, cnt;
		tie(x, y, cost, cnt) = q.front();
		q.pop();

		if (x == n - 1 && y == m - 1) { // 마지막 점 도달
			if (result > cost)
				result = cost;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nX = x + dX[i];
			int nY = y + dY[i];

			if (!(0 <= nX && nX < n && 0 <= nY && nY < m)) continue;
			if (arr[nX][nY] == 1 && cnt == 1) continue;
			if (!visited[nX][nY][1] && arr[nX][nY] == 1 && cnt == 0) { // 다음 칸이 벽인데, 벽을 깬 횟수가 0이고, 방문하지 않은 경우
				q.push({ nX, nY, cost + 1, cnt + 1 });
				visited[nX][nY][cnt + 1] = true;
			}
			else if(!visited[nX][nY][cnt] && arr[nX][nY] == 0){ // 다음 칸이 벽이 아니고, 방문하지 않은 경우
				q.push({ nX, nY, cost + 1, cnt });
				visited[nX][nY][cnt] = true;
			}
		}
	}

	result = -1;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &arr[i][j]);

	bfs();

	cout << result << endl;
}