#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define MAX 50

int n, m;
bool visited[MAX][MAX];
vector<string> v;

int dX[4] = { 1, -1, 0, 0 };
int dY[4] = { 0, 0, 1, -1 };

bool flag = false;

void dfs(int x, int  y, int cnt, int startX, int startY, char startC) {
	if (cnt >= 4 && x == startX && y == startY) {
		flag = true;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nX = x + dX[i];
		int nY = y + dY[i];

		if (!(0 <= nX && nX < n && 0 <= nY && nY < m)) continue;
		if (visited[nX][nY]) continue;
		if (v[nX][nY] != startC) continue;

		visited[nX][nY] = true;
		dfs(nX, nY, cnt + 1, startX, startY, startC);

		if (flag) return;

		visited[nX][nY] = false;
	}

	return;
}

int main() {
	FASTIO;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		v.push_back(str);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			memset(visited, false, sizeof(visited));
			dfs(i, j, 1, i, j, v[i][j]);
			visited[i][j] = true;

			if(flag) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << v[i][j] << ' ';
		}
		cout << endl;
	}*/
	
	cout << "No" << endl;

	return 0;
}