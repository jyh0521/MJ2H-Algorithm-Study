#include <iostream>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int N, M, X, Y, D, CNT = 0;
int d[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
bool place[50][50] = { 0 }, visited[50][50] = { 0 }, flag = true;

void move() {
	if (!visited[X][Y]) {
		CNT++;
		visited[X][Y] = 1;
	}

	for (int i = 0; i < 4; i++) {
		int nx = X + d[(D + 3) % 4][0];
		int ny = Y + d[(D + 3) % 4][1];
		D = (D + 3) % 4;
		if (place[nx][ny] == 1 || visited[nx][ny] == 1) continue;

		X = nx, Y = ny;
		return;
	}

	int nx, ny;
	if (D > 1) {
		nx = X + d[D - 2][0];
		ny = Y + d[D - 2][1];
	}
	else {
		nx = X + d[D + 2][0];
		ny = Y + d[D + 2][1];
	}
	if (place[nx][ny] == 1)
		flag = false;
	else
		X = nx, Y = ny;
}

int main() {
	cin >> N >> M;
	cin >> X >> Y >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> place[i][j];
		}
	}

	while (flag) {
		move();
	}
	cout << CNT << "\n";
	return 0;
}