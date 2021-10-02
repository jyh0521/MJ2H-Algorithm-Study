#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
char maze[9][9];
queue<pair<int, int> >q;
int dy[9] = {0, 0, -1, -1 , -1, 0, 1, 1, 1}, dx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
bool visited[9][9];

void input()
{
	FASTIO;
	for (int i = 0 ; i < 8 ; i++)
		cin >> maze[i];

}

void falling() // 벽 내려가는 작업
{
	for (int i = 7 ; i >= 1 ; i--)
		for (int j = 0 ; j < 8 ; j++)
		{
			if (maze[i-1][j] == '#')
			{
				maze[i][j] = '#';
				maze[i-1][j] = '.';
			}
		}
}

void bfs()
{
	q.push({7, 0});
	while (!q.empty())
	{
		int q_size = q.size();
		memset(visited, 0, sizeof(visited));
		for (int i = 0 ; i < q_size ; i++)
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			if (maze[y][x] == '#') continue;
			for (int j = 0 ; j < 9 ; j++)
			{
				int ny = y + dy[j];
				int nx = x + dx[j];
				if (ny < 0 || ny > 7 || nx < 0 || nx > 7 || maze[ny][nx] == '#' || visited[ny][nx]) continue;
				if (ny == 0 && nx == 7) {
					cout << 1;
					return;
				}
				visited[ny][nx] = 1;
				q.push({ny, nx});
			}
		}
		falling();
	}
	cout << 0;
}

void solve()
{
	bfs();
}

int main()
{
	input();
	solve();
	return (0);
}
