//17244
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <cstring>
#define endl "\n"

using namespace std;
int N, M, start_y, start_x;
char g_map[51][51];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
map<int, int> m_object; // 행 + 열 : object의 번호
int m_object_size, visited_max_value;
int visited, ans = 999999999;

void io_faster()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input()
{
	io_faster();
	
	cin >> N >> M;
	for (int i = 0 ; i < M ; i++)
	{
		cin >> g_map[i];
		for (int j = 0 ; j < N ; j++)
		{
			if (g_map[i][j] == 'S')
			{
				start_y = i;
				start_x = j;
			}
			else if (g_map[i][j] == 'X')
			{
				m_object[i * N + j] = m_object_size++;
			}
		}
	}
	visited_max_value = (1 << m_object_size) - 1;
}

void brute_force(int visited, int y, int x, int distance)
{
	bool map_visited[51][51];

	memset(map_visited, 0, sizeof(map_visited));
	queue<pair<pair<int, int> , int> > q;
	if (visited == visited_max_value) // 모두 돌았으니까 E를 찾아서 가야됨
	{
		q.push({{y, x}, 0});
		map_visited[y][x] = 1;
		while(!q.empty())
		{
			int front_y = q.front().first.first;
			int front_x = q.front().first.second;
			int dist = q.front().second;
			q.pop();
			for (int i = 0 ; i < 4 ; i++)
			{
				int ny = front_y + dy[i], nx = front_x + dx[i];
				if (g_map[ny][nx] == '#' || map_visited[ny][nx])
					continue;
				if (g_map[ny][nx] == 'E')
				{
					ans = min(ans, distance + dist + 1);
					return;
				}
				q.push({{ny, nx}, dist + 1});
				map_visited[ny][nx] = 1;
			}
		}
	}
	q.push({{y, x}, 0});
	map_visited[y][x] = 1;
	while(!q.empty())
	{
		int front_y = q.front().first.first;
		int front_x = q.front().first.second;
		int dist = q.front().second;
		q.pop();
		for (int i = 0 ; i < 4 ; i++)
		{
			int ny = front_y + dy[i], nx = front_x + dx[i];
			if (g_map[ny][nx] == '#' || g_map[ny][nx] == 'E' || map_visited[ny][nx])
				continue;
			map_visited[ny][nx] = 1;
			q.push({{ny, nx}, dist + 1});
			if (m_object.find(ny * N + nx) != m_object.end())
			{
				if (!(visited & (1 << m_object[ny * N + nx])))
					brute_force(visited | (1 << m_object[ny * N + nx]), ny, nx, dist + 1 + distance);
			}
		}
	}
}

void solve()
{
	brute_force(0, start_y, start_x, 0);
	cout << ans;
}

int main()
{
	input();
	solve();
	return (0);
}

