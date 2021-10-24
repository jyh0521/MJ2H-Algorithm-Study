#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int>pi;
typedef pair<pi, int>pii;
#define INF 1e9

int R, C, ans;
bool Bvisited[55][55], Wvisited[55][55], isFin;
char MAP[55][55];

queue<pi>Wq;
queue<pi>Bq;

int dx[] = { 0,0,1,-1 };
int dy[] = { -1,1,0,0 };

void bfs(int size, queue<pi> &q, bool visited[][55], bool beaver) {
	while (size--) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (beaver && MAP[x][y] == 'D') {
			isFin = 1;
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
			if (visited[nx][ny]) continue;
			if (MAP[nx][ny] == 'X')continue;
			if (MAP[nx][ny] == '*') continue;
			if (!beaver && MAP[nx][ny] == 'D') continue;
			visited[nx][ny] = 1;
			q.push({ nx,ny });
			if (!beaver) MAP[nx][ny] = '*';
		}
	}
}

int main() {
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
		{
			char c; cin >> c;
			MAP[i][j] = c;
			if (c == 'S') {
				Bq.push({ i,j });
				Bvisited[i][j] = 1;
				MAP[i][j] = '.';
			}
			else if (c == '*') {
				Wq.push({ i,j });
				Wvisited[i][j] = 1;
			}
		}
	}

	while (1) {
		int Bsize = Bq.size();
		int Wsize = Wq.size();
		bfs(Wsize, Wq, Wvisited, 0);
		bfs(Bsize, Bq, Bvisited, 1);
		if (isFin) break;
		else if (Bsize == 0) { ans = INF; break;}
		ans++;
	}
	if (ans == INF) cout << "KAKTUS";
	else cout << ans;
}
