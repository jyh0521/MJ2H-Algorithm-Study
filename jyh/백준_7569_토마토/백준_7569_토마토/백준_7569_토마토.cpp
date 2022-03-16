#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define MAX 100

int n, m, h;
int arr[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];

vector<tuple<int, int, int>> v;

int dX[6] = {1, -1, 0, 0, 0, 0};
int dY[6] = {0, 0, 1, -1, 0, 0};
int dZ[6] = {0, 0, 0, 0, 1, -1};

void bfs() {
	queue<tuple<int, int, int, int>> q;

	for (int i = 0; i < v.size(); i++) {
		int x, y, z;
		tie(x, y, z) = v[i];

		q.push({ x, y, z, 0 });
		visited[z][x][y] = true;
	}

	while (!q.empty()) {
		int x, y, z, day;
		tie(x, y, z, day) = q.front();
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nX = x + dX[i];
			int nY = y + dY[i];
			int nZ = z + dZ[i];

			if (!(0 <= nX && nX < n && 0 <= nY && nY < m && 0 <= nZ && nZ < h)) continue;
			if (visited[nZ][nX][nY]) continue;
			if (arr[nZ][nX][nY] == -1 || arr[nZ][nX][nY] == 1) continue;

			visited[nZ][nX][nY] = true;
			arr[nZ][nX][nY] = 1;
			q.push({ nX, nY, nZ, day + 1 });
		}

		if (q.size() == 0) {
			bool flag = false;

			for (int i = 0; i < h; i++) {
				for (int j = 0; j < n; j++) {
					for (int k = 0; k < m; k++) {
						if (arr[i][j][k] == 0) {
							flag = true;
						}
					}
				}
			}

			if (!flag)
				cout << day << endl;
			else
				cout << -1 << endl;

			return;
		}
	}
}

int main() {
	cin >> m >> n >> h;

	int noTomato = 0;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> arr[i][j][k];

				if (arr[i][j][k] == -1)
					noTomato++;
				else if (arr[i][j][k] == 1)
					v.push_back({ j, k, i });
			}
		}
	}

	if (v.size() == n * m * h - noTomato) {
		cout << 0 << endl;
		return 0;
	}
	if (v.size() == 0) {
		cout << -1 << endl;
		return 0;
	}

	bfs();

	return 0;
}