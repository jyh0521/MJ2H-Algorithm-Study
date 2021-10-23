#include <iostream>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
bool cycle = 0;
int N, M, visited[50][50], d[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
char arr[51][51];
void dfs(int x, int y, int v) {
	visited[x][y] = v;
	for (int i = 0; i < 4; i++) {
		int nx = x + d[i][0];
		int ny = y + d[i][1];
		if (nx<0 || nx>N - 1 || ny<0 || ny>M - 1) continue;
		if (arr[nx][ny] != arr[x][y]) continue;
		if (visited[nx][ny] && visited[nx][ny] < visited[x][y] - 1) {
			cycle = 1;
			return;
		}
		else if (visited[nx][ny]) continue;
		dfs(nx, ny, v + 1);
	}
}
int main() {
	FASTIO;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		if (cycle) break;
		for (int j = 0; j < M; j++) {
			if (cycle) break;
			if (visited[i][j]) continue;
			dfs(i, j, 1);
		}
	}
	cycle ? cout << "Yes" : cout << "No";
	return 0;
}