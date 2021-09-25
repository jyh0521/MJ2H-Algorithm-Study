#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define MAX 50

int n, m, result = 99999999;
bool visited[MAX][MAX];

vector<string> map;
vector<pair<int, int>> needs;
vector<int> order;

pair<int, int> start;
pair<int, int> door;

int dX[4] = { 0, 0, 1, -1 };
int dY[4] = { 1, -1, 0, 0 };

void initVisited() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			visited[i][j] = false;
}

void bfs() {
	queue<tuple<int, int, int>> q;
	q.push({ start.first, start.second, 0 });
	visited[start.first][start.second] = true;

	int totalCnt = 0;

	for (int i = 0; i < order.size() + 1; i++) {
		int destX;
		int destY;

		if (i == order.size()) { // 마지막 물건 위치에서 문을 찾는다.
			destX = door.first;
			destY = door.second;
		}
		else {
			destX = needs[order[i]].first;
			destY = needs[order[i]].second;
		}

		while (!q.empty()) {
			int x, y, cnt;
			tie(x, y, cnt) = q.front();
			q.pop();

			// 도착 처리
			if (x == destX && y == destY) {
				initVisited(); // visited 초기화
				while (!q.empty()) q.pop(); // 큐 비우기

				totalCnt += cnt;
				q.push({ x, y, 0 }); // 현재 위치부터 새로운 시작점
				visited[x][y] = true;
				break;
			}


			for (int j = 0; j < 4; j++) {
				int nX = x + dX[j];
				int nY = y + dY[j];

				if (!(0 <= nX && nX < n && 0 <= nY && nY < m)) continue;
				if (map[nX][nY] == '#') continue;
				if (visited[nX][nY]) continue;

				visited[nX][nY] = true;
				q.push({ nX, nY, cnt + 1 });
			}
		}
	}

	if (result > totalCnt)
		result = totalCnt;
}

int main() {
	FASTIO;

	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		map.push_back(str);

		for (int j = 0; j < str.length(); j++) {
			if (str[j] == 'S')
				start = { i, j };
			else if (str[j] == 'X')
				needs.push_back({ i, j });
			else if (str[j] == 'E')
				door = { i, j };
		}
	}

	for (int i = 0; i < needs.size(); i++)
		order.push_back(i);

	do {
		initVisited();
		bfs();
	} while (next_permutation(order.begin(), order.end()));

	cout << result << endl;

	return 0;
}