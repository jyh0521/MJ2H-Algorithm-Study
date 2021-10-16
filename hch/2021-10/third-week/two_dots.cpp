//16929
#include <iostream>
#include <cstring>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"
int N, M;
char g_map[51][51];
int dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0};
bool visited[51][51];

void input()
{
	FASTIO;
	cin >> N >> M;
	for (int i = 0 ; i < N ; i++)
		cin >> g_map[i];
}

bool dfs(int start_y, int start_x, int y, int x, int before_color, int cnt)
{
	for (int i = 0 ; i < 4 ; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (cnt >= 3 && start_y == ny && start_x == nx)
			return (true);
		if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] || before_color != g_map[ny][nx])
			continue;
		visited[ny][nx] = true;
		if(dfs(start_y, start_x, ny, nx, before_color, cnt + 1))
			return (true);
	}
	return (false);
}

void solve()
{
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < M ; j++)
		{
			memset(visited, 0, sizeof(visited));
			visited[i][j] = true;
			if(dfs(i, j, i, j, g_map[i][j], 1))
			{
				cout << "Yes";
				return;
			}
		}
	cout << "No";
}

int main()
{
	input();
	solve();
	return (0);
}
