//2206
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int N, M;
char g_map[1002][1002];
int visited[1002][1002][2];

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void input()
{
	FASTIO;
	cin >> N >> M;
	for (int i = 0 ; i < N ; i++)
		cin >> g_map[i];
}

void solve()
{
	int y, x, wall_flag, ny, nx, nf;
	queue<pair<pair<int, int>, int> > q;
	q.push({{0, 0}, 0});
	memset(visited, 0x3f, sizeof(visited));
	visited[0][0][0] = 1;
	visited[0][0][1] = 1;
	if (N == 1 && M == 1) { // 예외 처리
		cout << 1;
		return ;
	}
	while (!q.empty())
	{
		y = q.front().first.first;
		x = q.front().first.second;
		wall_flag = q.front().second; // 한 번이라도 벽을 뚫고 왔는지 체크. 1이면 벽 뚫은적 있음.
		q.pop();
		for (int i = 0 ; i < 4 ; i++)
		{
			ny = y + dy[i];
			nx = x + dx[i];
			nf = (g_map[ny][nx] - '0') | wall_flag; // 다음 위치가 벽이거나 벽을 뚫은적이 있는 경우 체크
			if (ny == N -1  && nx == M - 1) {
				cout << visited[y][x][wall_flag] + 1;
				return ;
			}
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			else if (g_map[ny][nx] == '1' && wall_flag) continue; // 다음이 벽이고 벽을 한 번이라도 뚫었다면 continue
			else if (visited[y][x][wall_flag] + 1 >= visited[ny][nx][nf]) continue;
			visited[ny][nx][nf] = visited[y][x][wall_flag] + 1;
			q.push({{ny, nx}, nf});
		}
	}
	cout << -1 ;
}

int main()
{
	input();
	solve();
	return (0);
}
