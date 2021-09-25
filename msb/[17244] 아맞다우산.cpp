#include <iostream>
#include <queue>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, M, sx, sy, cnt = 0, d[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
char arr[51][51];
int visited[51][51][1<<5] = { 0 };
pair<int, int> info[5];
queue<pair<pair<int,int>,int>> q;
int bfs() {
	q.push({ {sx,sy},0 });
	visited[sx][sy][0] = 1;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int s = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = x + d[i][0];
			int ny = y + d[i][1];
			int ns = s;
			
			if (arr[nx][ny] == '#') continue;
			if (arr[nx][ny] == 'X') {
				for (int j = 0; j < cnt; j++) {
					if (nx == info[j].first && ny == info[j].second)
						ns |= (1 << j);
				}
			}
			if (visited[nx][ny][ns] && visited[nx][ny][ns] <= visited[x][y][s] + 1) continue;
			visited[nx][ny][ns] = visited[x][y][s] + 1;
			
			if (arr[nx][ny]=='E') { 
				if (s == ((1 << cnt) - 1))
					return visited[nx][ny][ns] - 1;
			}
			else // E일때를 q에 넣으면 후에 범위 밖으로 나가게될 수 있으므로 넣지 않는다
				q.push({ {nx,ny},ns });
		}

	}
}
int main() {
	FASTIO;
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'S') {
				sx = i, sy = j;
			}
			else if (arr[i][j] == 'X') {
				info[cnt].first = i;
				info[cnt++].second = j;
			}
		}
	}
	cout << bfs();
	return 0;
}