#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef pair<pi, int> pii;
#define INF 1e9

typedef struct POS{
	int x;
	int y;
	bool flag;
}pos;

int visited[1005][1005][2];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int N, M, ans;
string MAP[1005];

bool outrange(int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= M) return 1;
	return 0;
}

void bfs(int sx, int sy) {
	queue<pos>q;
	visited[sx][sy][0] = 1;
	q.push({ sx,sy,0 });

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		bool flag = q.front().flag;
		q.pop();

		if (x == N - 1 && y == M - 1) {
			ans = visited[x][y][flag];
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (outrange(nx, ny)) continue;
			if (visited[nx][ny][flag] != 0) continue;

			if (MAP[nx][ny] == '1') {
				if (!flag && visited[nx][ny][1] == 0) {
					visited[nx][ny][1] = visited[x][y][0] + 1;
					q.push({ nx,ny,1 });
				}
			}
			else{
				visited[nx][ny][flag] = visited[x][y][flag] + 1;
				q.push({ nx,ny,flag });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> MAP[i];
	
	bfs(0, 0);

	if (ans == 0) ans = -1;
	cout << ans;
}
