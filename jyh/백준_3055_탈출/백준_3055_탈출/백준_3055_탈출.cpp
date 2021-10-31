#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define MAX 51

int r, c;
int sX, sY;
bool visited[MAX][MAX];

vector<string> v;
vector<pair<int, int>> wv;

int dX[] = { 1, -1, 0, 0 };
int dY[] = { 0, 0, 1, -1 };

void bfs() {
	queue<tuple<int, int, int>> q; // x, y, cost
	vector<tuple<int, int, int>> t;
	q.push({ sX, sY, 0 });
	visited[sX][sY] = true;

	while (true) {
		queue<pair<int, int>> w;
		
		for (int i = 0; i < wv.size(); i++)
			w.push({ wv[i].first, wv[i].second });

		wv.clear();

		while (!w.empty()) { // 물 증가
			int wX = w.front().first;
			int wY = w.front().second;
			w.pop();

			for (int j = 0; j < 4; j++) {
				int nX = wX + dX[j];
				int nY = wY + dY[j];

				if (!(0 <= nX && nX < r && 0 <= nY && nY < c)) continue;
				if (v[nX][nY] == '*' || v[nX][nY] == 'D' || v[nX][nY] == 'X') continue;
				v[nX][nY] = '*';
				wv.push_back({ nX, nY });
			}
		}

		for (int i = 0; i < t.size(); i++) {
			int tX, tY, tCost;
			tie(tX, tY, tCost) = t[i];
			q.push({ tX, tY, tCost });
		}

		t.clear();

		bool flag = false;

		while (!q.empty()) { // 도치
			int x, y, cost;
			tie(x, y, cost) = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nX = x + dX[i];
				int nY = y + dY[i];

				if (!(0 <= nX && nX < r && 0 <= nY && nY < c)) continue;
				if (visited[nX][nY] || v[nX][nY] == '*' || v[nX][nY] == 'X') continue;

				if (v[nX][nY] == 'D') {
					cout << cost + 1 << endl;
					return;
				}

				visited[nX][nY] = true;
				t.push_back({ nX, nY, cost + 1 });
				flag = true;
			}
		}

		if (!flag)
			break;
	}

	cout << "KAKTUS" << endl;
}

int main() {
	FASTIO;

	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		string str;
		cin >> str;
		v.push_back(str);

		for (int j = 0; j < c; j++) {
			if (str[j] == 'S') {
				sX = i;
				sY = j;
			}
			else if (str[j] == '*')
				wv.push_back({ i, j });
		}
	}

	bfs();

	return 0;
}