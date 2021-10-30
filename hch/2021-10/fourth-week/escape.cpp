//3055
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"
int R, C;
char g_map[51][51];
vector<pair<int, int> >water_coord;
vector<pair<int, int> >gowsoom_coord;
int gowsoom_size;
bool visited[51][51][2];
int gowsoom_map[51][51];
int dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0};

void input()
{
	FASTIO;
	cin >> R >> C;
	for (int i = 0 ; i < R ; i++)
	{
		cin >> g_map[i];
		for (int j = 0 ; j < C ; j++)
		{
			if (g_map[i][j] == '*') 
			{
				water_coord.push_back({i, j});
				visited[i][j][0] = true;
			}
			else if (g_map[i][j] == 'S') 
			{
				gowsoom_coord.push_back({i, j});
				visited[i][j][1] = true;
			}
		}
	}
}

void solve()
{
	// 고슴도치 이동후 물 이동
	queue<pair<int, int> >q;
	gowsoom_size = gowsoom_coord.size();
	int q_size, qy, qx, ny, nx;

	for (size_t i = 0 ; i < gowsoom_coord.size() ; i++)
		q.push({gowsoom_coord[i].first, gowsoom_coord[i].second});

	for (size_t i = 0 ; i < water_coord.size() ; i++)
		q.push({water_coord[i].first, water_coord[i].second});
	while (gowsoom_size)
	{
		q_size = q.size();
		for (int i = 0 ; i < q_size ; i++)
		{
			qy = q.front().first;
			qx = q.front().second;
			q.pop();
			for (int j = 0 ; j < 4 ; j++)
			{
				ny = qy + dy[j];
				nx = qx + dx[j];
				if (ny < 0 || ny >= R || nx < 0 || nx >= C || g_map[ny][nx] == 'X') continue;
				if (g_map[qy][qx] == 'S') 
				{
					if (g_map[ny][nx] == 'D')
					{
						cout << gowsoom_map[qy][qx] + 1;
						return ;
					}
					if (visited[ny][nx][1] || g_map[ny][nx] == '*') continue;
					visited[ny][nx][1] = true;
					gowsoom_map[ny][nx] = gowsoom_map[qy][qx] + 1;
					gowsoom_size++;
					g_map[ny][nx] = 'S';
				}
				else if (g_map[qy][qx] == '*')
				{
					if (visited[ny][nx][0] || g_map[ny][nx] == 'D') continue;
					if (g_map[ny][nx] == 'S') gowsoom_size--;
					visited[ny][nx][0] = true;
					g_map[ny][nx] = '*';
				}
				q.push({ny, nx});
			}
		}
	}
	cout << "KAKTUS";
}

int main()
{
	input();
	solve();
	return (0);
}
