#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define MAX 100

int n, m, k;
int arr[MAX][MAX];

int dX[4] = { 1, -1, 0, 0 };
int dY[4] = { 0, 0, 1, -1 };

void bfs(int x, int y, int g) {
	queue<pair<int, int>> q;
	q.push({x, y});
	arr[x][y] = g;

	while (!q.empty()) {
		int nowX = q.front().first;
		int nowY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nX = nowX + dX[i];
			int nY = nowY + dY[i];

			if (!(0 <= nX && nX < n && 0 <= nY && nY < m)) continue;
			if (arr[nX][nY] != 0) continue;

			arr[nX][nY] = g;
			q.push({ nX, nY });
		}
	}
}

int main() {
	cin >> n >> m >> k;

	while (k--) {
		int sX, sY, eX, eY;
		cin >> sY >> sX >> eY >> eX;

		int row = abs(sY - eY);
		int col = abs(sX - eX);

		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++) {
				arr[abs(sX + i - n + 1)][sY + j] = -1;
			}
		}
	}

	int group = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!arr[i][j] == 0) continue;
			group++;
			bfs(i, j, group);
		}
	}

	cout << group << endl;

	vector<int> result;

	for (int i = 1; i <= group; i++) {
		int nowGroupCnt = 0;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (arr[j][k] == i) {
					nowGroupCnt++;
				}
			}
		}

		result.push_back(nowGroupCnt);
	}

	sort(result.begin(), result.end());

	for (int i = 0; i < result.size(); i++)
		cout << result[i] << ' ';

	cout << endl;

	return 0;
}