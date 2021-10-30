#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
queue<tuple<int, int, bool>> q;
int R, C, d[4][2] = { {1,0},{0,1},{0,-1},{-1,0} }, visited[50][50] = { 0 }, sx, sy, ANS = -1;
char arr[51][51];
void bfs() {
	q.push(make_tuple(sx, sy, 0));
	visited[sx][sy] = 1;
	while (!q.empty()) {
		int x, y, w;
		tie(x, y, w) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + d[i][0];
			int ny = y + d[i][1];
			if (nx<0 || nx>R - 1 || ny<0 || ny>C - 1) continue;
			if (arr[nx][ny] == 'X' || arr[nx][ny] == '*') continue;
			if (w && arr[nx][ny] == '.') {
				arr[nx][ny] = '*';
				q.push(make_tuple(nx, ny, 1));
			}
			if (!w) {
				if (visited[nx][ny]) continue;
				visited[nx][ny] = visited[x][y] + 1;
				if (arr[nx][ny] == 'D') {
					ANS = visited[nx][ny]-1;
					return;
				}
				q.push(make_tuple(nx, ny, 0));
			}

		}
	}
}
int main() {
	FASTIO;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'S') {
				sx = i, sy = j;
				arr[i][j] = '.';
			}
			else if (arr[i][j] == '*')
				q.push(make_tuple(i, j, 1));
		}
	}
	bfs();
	ANS == -1 ? cout << "KAKTUS" : cout << ANS;
	return 0;
}