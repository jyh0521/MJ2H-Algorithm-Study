//14503
#include <iostream>
#define endl "\n"

int N, M, r, c, d;
int g_map[51][51];
int visited[51][51];
int dy[4] = {-1, 0, 1, 0}; // 북 동 남 서
int dx[4] = {0, 1, 0, -1};
int ans;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> N >> M;
	std::cin >> r >> c >> d;
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < M ; j++)
			std::cin >> g_map[i][j];
}

void clean_now_location()
{
	visited[r][c] = 1;
}

int get_left_side_index() 
{
	return (d + 3) % 4 ;
}

int get_back_side_index()
{
	return (d + 2) % 4;
}

void update_state(int ny, int nx, int index)
{
	r = ny;
	c = nx;
	d = index;
}

bool check_wall_or_cleaned(int ny, int nx)
{
	if (ny < 0 || ny >= N || nx < 0 || nx >= M || g_map[ny][nx] || visited[ny][nx]) return true;
	return false;
}

//왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
int search_adjcent_a() 
{
	int left_side_index = get_left_side_index();
	int ny = r + dy[left_side_index], nx = c + dx[left_side_index]; // 다음 좌표 구하기
	if (check_wall_or_cleaned(ny, nx)) return false;
	update_state(ny, nx, left_side_index);
	return 2;
}

void get_cleaned_area() 
{
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < M ; j++)
			ans += visited[i][j];
}

int search_adjcent(int depth)
{
	if (depth == 4) {
		int back_side_index = get_back_side_index();
		int ny = r + dy[back_side_index], nx = c + dx[back_side_index]; // 다음 좌표 구하기
		if (ny < 0 || ny >= N || nx < 0 || nx >= M || g_map[ny][nx]) return false; // 2-d 네 방향 모두 청소 + 뒤쪽 방향이 벽이라 후진도 못하는 경우	
		update_state(ny, nx, d); // 후진
		return 1;
	}
	else {
		int check = search_adjcent_a();
		if (check) {
			return check;
		}
		else 
		{
			d = get_left_side_index();
			return search_adjcent(depth + 1);
		}
	}
}

void solve()
{
	int check = 1;

	clean_now_location();
	while(check)
	{
		check = search_adjcent(0);
		if (check == 2)
			clean_now_location();
	}
	get_cleaned_area();
	std::cout << ans;
}

int main()
{
	input();
	solve();
	return (0);
}
