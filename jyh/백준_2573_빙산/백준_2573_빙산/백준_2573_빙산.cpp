#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define MAX 300

int n, m;
int arr[MAX][MAX];
int visited[MAX][MAX];

int dX[4] = { 1, -1, 0, 0 };
int dY[4] = { 0, 0, 1, -1 };

queue<pair<int, int>> q;
//queue<pair<int, int>> q1;
vector<pair<int, int>> v;

bool check() { // 빙산이 2덩어리인지 검사하는 함수
	int ice = 1;
	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;

		if (visited[x][y] != 0) continue;

		queue<pair<int, int>> q1;
		q1.push({ x, y });
		visited[x][y] = ice;

		while (!q1.empty()) {
			int nowX = q1.front().first;
			int nowY = q1.front().second;
			q1.pop();

			for (int i = 0; i < 4; i++) {
				int nX = nowX + dX[i];
				int nY = nowY + dY[i];

				if (!(0 <= nX && nX < n && 0 <= nY && nY < m)) continue;
				if (arr[nX][nY] == 0 || visited[nX][nY] != 0) continue;

				visited[nX][nY] = ice;
				q1.push({ nX, nY });
			}
		}

		if (ice >= 2)
			return true;

		ice++;
	}

	return false;
}

void bfs() {
	int day = 1;
	
	queue<tuple<int, int, int>> q2;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		int sea = 0;

		for (int i = 0; i < 4; i++) {
			int nX = x + dX[i];
			int nY = y + dY[i];

			if (!(0 <= nX && nX < n && 0 <= nY && nY < m)) continue;
			if (arr[nX][nY] != 0) continue;
			sea++;
		}

		q2.push({ x, y, sea });

		if (q.size() == 0) { // 큐가 비었을 때 2덩어리인지 검사 후 완료가 되지 않았다면 얼음들 q에 push
			while (!q2.empty()) {
				int x, y, cnt;
				tie(x, y, cnt) = q2.front();
				q2.pop();

				arr[x][y] = arr[x][y] - cnt < 0 ? 0 : arr[x][y] - cnt;
			}

			v.clear();

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (arr[i][j] == 0) continue;
					q.push({ i, j });
					v.push_back({ i, j });
				}
			}

			if (check()) {
				cout << day << endl;
				return;
			}
			else
				day++;
		}
	}

	cout << 0 << endl;
	return;
}

int main() {
	FASTIO;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			
			if (arr[i][j] == 0) continue;

			q.push({ i, j });
		}
	}

	bfs();

	return 0;
}