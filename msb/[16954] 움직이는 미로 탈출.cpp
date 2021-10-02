#include <iostream>
#include <queue>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0);
queue<pair<pair<int, int>, int>> q;
bool arr[8][8] = { 0 }, visited[8][8][10] = { 0 };
int d[9][2] = { {0,0},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1} }, cnt = 0;
int bfs() {
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int me = q.front().second;
		q.pop();

		if (!me) {
			if (x + 1 > 7) {
				cnt -= 1;
				continue;
			}
			arr[x + 1][y] = 1;
			arr[x][y] = 0;
			q.push({ {x + 1,y},0 });
			continue;
		}
		
		if (arr[x][y]) continue;
		if (!cnt) return 1;
		for (int i = 0; i < 9; i++) {
			int nx = x + d[i][0];
			int ny = y + d[i][1];
			int nme = me + 1;
			if (nx < 0 || nx>7 || ny < 0 || ny>7) continue;
			if (arr[nx][ny]) continue;
			if (visited[nx][ny][nme]) continue;

			if (nx == 0 && ny == 7) return 1;
			visited[nx][ny][nme] = 1;
			q.push({ { nx,ny }, nme });
		}
	}
	return 0;
}
int main() {
	FASTIO;
	q.push({ { 7,0 }, 1 });
	char temp;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> temp;
			arr[i][j] = temp == '#' ? true : false;
		}
	}
	for (int i = 7; i >= 0; i--) {
		for (int j = 0; j < 8; j++) {
			if (arr[i][j]) {
				cnt++;
				q.push({ {i,j},0 });
			}
		}
	}
	cout << bfs();
	return 0;
}