#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"
int spin_dy[4] = {0, 1, 0, -1}, spin_dx[4] = {-1, 0, 1, 0};
int blizzard_dy[5] = {0, -1, 1, 0, 0}, blizzard_dx[5] = {0, 0, 0, -1, 1};
int N, M, g_map[51][51], tmp_map[51][51];
int shark_y, shark_x;
vector<pair<int, int> > coord_v1;
int ans;

void input()
{
	FASTIO;
	cin >> N >> M;
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < N ; j++)
			cin >> g_map[i][j];
}

//터트릴 지 확인 후 터트림
void exploded_operation(vector<pair<int, int> > save_coord, bool &is_exploded)
{
	if (save_coord.size() >= 4)
	{
		is_exploded = 1;
		ans += (save_coord.size() * g_map[save_coord.back().first][save_coord.back().second]);
		for (auto &i : save_coord) {
			int y = i.first;
			int x = i.second;
			g_map[y][x] = 0;
		}
	}
}

bool explosion()
{
	int v_size = coord_v1.size();
	vector<pair<int, int> >save_coord = {{N + 1, N + 1}};
	bool is_exploded = 0;
	
	for (int i = 0 ; i < v_size ; i++)
	{
		int qy = coord_v1[i].first;
		int qx = coord_v1[i].second;
		int save_coord_back_y = save_coord.back().first, save_coord_back_x = save_coord.back().second;
		if (g_map[save_coord_back_y][save_coord_back_x] == g_map[qy][qx]){
			save_coord.push_back({qy, qx});
		}
		else
		{
			exploded_operation(save_coord, is_exploded);
			save_coord = {};
			if (g_map[qy][qx] == 0)
				save_coord.push_back({N + 1, N + 1});
			else
				save_coord.push_back({qy, qx});
		}
	}
	exploded_operation(save_coord, is_exploded);
	return (is_exploded);
}

// dir : 방향, to_dist : 방향을 바꾼 후 이동할 거리, dist : 방향을 바꾼 후 이동한 거리 dir_cnt : 방향을 몇번 바꿨는지 (2번마다 dir 바꿔야됨)
// total_dist : 총 이동거리. N*N이 되면 멈춤
void make_coord_vector(int y, int x, int dir, int to_dist, int dist, int dir_cnt, int total_dist)
{
	if (total_dist == N * N)
		return ;
	coord_v1.push_back({y, x});
	if (to_dist == dist)
	{
		dir_cnt++;
		dist = 0;
		if (dir_cnt == 2)
		{
			dir_cnt = 0;
			to_dist++;
		}
		dir = (dir + 1) % 4;
	}
	int ny = y + spin_dy[dir], nx = x + spin_dx[dir];
	dist++;
	total_dist++;
	make_coord_vector(ny, nx, dir, to_dist, dist, dir_cnt, total_dist);
}

void pull_operation()
{
	int v_size = coord_v1.size();
	queue<pair<int, int> > save_q;

	for (int i = 0 ; i < v_size ; i++)
	{
		int qy = coord_v1[i].first;
		int qx = coord_v1[i].second;

		if (!save_q.empty() && g_map[qy][qx])
		{
			int save_q_y = save_q.front().first;
			int save_q_x = save_q.front().second;
			save_q.pop();
			g_map[save_q_y][save_q_x] = g_map[qy][qx];
			g_map[qy][qx] = 0;
			save_q.push({qy, qx});
		}
		else if (!g_map[qy][qx])
			save_q.push({qy, qx});
	}
}

void grouping()
{
	int v_size = coord_v1.size();
	int start_y = coord_v1[0].first, start_x = coord_v1[0].second;
	int v_index = 0;
	int cnt = 0;
	int y, x;

	memset(tmp_map, 0, sizeof(tmp_map));
	tmp_map[N+1][N+1] = -1;
	for (int i = 0 ; i < v_size ; i++)
	{
		int qy = coord_v1[i].first;
		int qx = coord_v1[i].second;

		if (g_map[start_y][start_x] == g_map[qy][qx])
			cnt++;
		else if (v_index < v_size - 1 || (v_index < v_size - 1 && i == v_size - 1))
		{
			y = coord_v1[v_index].first;
			x = coord_v1[v_index++].second;
			tmp_map[y][x] = cnt;
			y = coord_v1[v_index].first;
			x = coord_v1[v_index++].second;
			tmp_map[y][x] = g_map[start_y][start_x];
			cnt = 1;
			start_y = qy;
			start_x = qx;
		}
	}
	memcpy(g_map, tmp_map, sizeof(g_map));
}

void solve()
{
	int d, s, ny, nx;
	shark_x = shark_y = (N + 1) / 2 - 1;
	g_map[N+1][N+1] = -1;
	make_coord_vector(shark_y, shark_x - 1, 0, 1, 1, 0, 1);
	for (int i = 0 ; i < M ; i++)
	{
		cin >> d >> s;
		ny = shark_y;
		nx = shark_x;
		//blizzard operation
		for (int j = 1 ; j <= s ; j++)
		{
			ny += blizzard_dy[d];
			nx += blizzard_dx[d];
			g_map[ny][nx] = 0;
		}
		pull_operation();
		
		while (explosion()) 
		{
			//폭발이 일어난 후, 당기는 작업
			pull_operation();
		}
		grouping();
	}
	cout << ans;
}

int main()
{
	input();
	solve();
	return (0);
}

