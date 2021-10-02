#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"

int N, M;
int dy[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1}, dx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int diagonal_dy[4] = {-1, -1, 1, 1}, diagonal_dx[4] = {-1, 1, 1, -1};
int A[51][51], d[101], s[101], check_cloud[51][51];
vector<pair<int, int> >cloud_coord;
int cloud_coord_size;

void input()
{
	FASTIO;
	cin >> N >> M;
	for (int i = 1 ; i <= N ; i++)
		for (int j = 1 ; j <= N ; j++)
			std::cin >> A[i][j];
	for (int i = 0  ; i < M ; i++)
		std::cin >> d[i] >> s[i];
	cloud_coord.push_back({N, 1});
	cloud_coord.push_back({N, 2});
	cloud_coord.push_back({N-1, 1});
	cloud_coord.push_back({N-1, 2});
}

void move_clouds(int index)
{
	vector<pair<int, int> > tmp;

	for (int i = 0 ; i < cloud_coord_size ; i++)
	{
		int mv_y = (cloud_coord[i].first - 1 + dy[d[index]] * s[index] % N);
		int mv_x = (cloud_coord[i].second - 1 + dx[d[index]] * s[index] % N);

		mv_y = mv_y < 0 ? mv_y + N : mv_y;
		mv_y = mv_y >= N ? mv_y % N : mv_y;
		mv_x = mv_x < 0 ? mv_x + N : mv_x;
		mv_x = mv_x >= N ? mv_x % N : mv_x;
		mv_y++;
		mv_x++;
		tmp.push_back({mv_y, mv_x});
		check_cloud[mv_y][mv_x] = 1;
	}
	cloud_coord = tmp;
}

void rain()
{
	for (int i = 0 ; i < cloud_coord_size ; i++)
	{
		int y = cloud_coord[i].first;
		int x = cloud_coord[i].second;
		A[y][x]++;
	}
}

int check_diagonal(int y, int x) // 대각선에 물이 있는 칸의 갯수만큼 리턴
{
	int result = 0;

	for (int i = 0 ; i < 4 ; i++)
	{
		int ny = y + diagonal_dy[i];
		int nx = x + diagonal_dx[i];

		if (ny <= 0 || ny > N || nx <= 0 || nx > N) continue;
		if (A[ny][nx]) result++;
	}
	return (result);
}

void increase_by_diagonal()
{
	for (int i = 0 ; i < cloud_coord_size ; i++)
	{
		int y = cloud_coord[i].first;
		int x = cloud_coord[i].second;
		
		A[y][x] += check_diagonal(y, x);
	}
}

void create_cloud()
{
	vector<pair<int, int> >tmp;

	for (int i = 1 ; i <= N ; i++)
		for (int j = 1 ; j <= N ; j++)
		{
			if (check_cloud[i][j] || A[i][j] < 2) continue;
			tmp.push_back({i, j});
			A[i][j] -= 2;
		}
	cloud_coord = tmp;
}

void print_ans()
{
	int ans = 0;

	for (int i = 1 ; i <= N ; i++)
		for (int j = 1 ; j <= N ; j++)
			ans += A[i][j];
	cout << ans;
}

void solve()
{
	for (int i = 0 ; i < M ; i++)
	{
		cloud_coord_size = cloud_coord.size();
		memset(check_cloud, 0, sizeof(check_cloud));
		move_clouds(i);
		rain();
		increase_by_diagonal();
		create_cloud();
	}
}

int main()
{
	input();
	solve();
	print_ans();
	return (0);
}

