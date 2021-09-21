#include <iostream>
using namespace std;

#define endl '\n'

int n, m;
int x, y, d, result = 0;
int map[50][50];
bool visited[50][50]; // 청소 구역 표시

// 북, 동, 남, 서
int dX[4] = { -1, 0, 1, 0};
int dY[4] = { 0, 1, 0, -1};

int rotateLeft(int dir) {
	return (dir + 3) % 4;
}

int getBackPos(int dir) {
	return (dir + 2) % 4;
}

int main() {
	cin >> n >> m;
	cin >> x >> y >> d;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	while (1) {
		result++;
		visited[x][y] = true;

		int rotateCnt = 0;
		bool canClean = false;

		while(1) {
			d = rotateLeft(d);
			int nX = x + dX[d];
			int nY = y + dY[d];

			rotateCnt++;

			// a. 왼쪽 방향이 빈칸 이면서 청소하지 않은 경우
			if (map[nX][nY] == 0 && !visited[nX][nY]) {
				x = nX;
				y = nY;
				//d = nextDir;
				canClean = true;
				break;
			}

			if (rotateCnt == 4) { // 네 방향으로 갈 수 없는 경우
				int backDir = getBackPos(d);
				int backX = x + dX[backDir];
				int backY = y + dY[backDir];

				if (map[backX][backY] == 1) { // 후진도 할 수 없는 경우
					canClean = false;
					break;
				}

				x = backX;
				y = backY;
				rotateCnt = 0;
				continue;
			}
		}

		if (!canClean) {
			cout << result << endl;
			return 0;
		}
	}

	return 0;
}