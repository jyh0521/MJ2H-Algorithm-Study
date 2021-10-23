#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, M, d[4][2] = { {1,0},{0,1},{-1,0},{0,-1} }, visited[1000][1000][2] = { 0 };
bool arr[1000][1000];
queue<tuple<int, int, bool>> q;
int bfs() {
	while (!q.empty()) {
		int x, y, z;
		tie(x, y, z) = q.front();
		q.pop();
		if (x == N - 1 && y == M - 1) return visited[x][y][z];

		for (int i = 0; i < 4; i++) {
			int nx = x + d[i][0];
			int ny = y + d[i][1];
			int nz = z;
			if (nx<0 || ny<0 || nx>N - 1 || ny>M - 1) continue;
			
			if (arr[nx][ny] && !nz && !visited[nx][ny][!nz]) {
				visited[nx][ny][!nz] = visited[x][y][z] + 1;
				if (x == N - 1 && y == M - 1) return visited[nx][ny][!nz];
				q.push(make_tuple(nx, ny, !nz));
			}
			
			if (!arr[nx][ny] && !visited[nx][ny][nz]) {
				visited[nx][ny][nz] = visited[x][y][z] + 1;
				if (x == N - 1 && y == M - 1) return visited[nx][ny][nz];
				q.push(make_tuple(nx, ny, nz));
			}
		}
	}
	return -1;
}
int main() {
	FASTIO;
	cin >> N >> M;
	char temp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> temp;
			arr[i][j] = (temp == '1') ? true : false;
		}
	}
	q.push(make_tuple(0, 0, 0));
	visited[0][0][0] = 1;
	cout << bfs();
	return 0;
}