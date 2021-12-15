#include <iostream>
#include <queue>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
queue<pair<int, int>> q;
bool CLEAR = false, arr[2][100000];
int N, K, INF = 987654321, TIME = -1;
void check(int x, int y) {
	if (y > N - 1) {
		CLEAR = 1;
		return;
	}
	if (arr[x][y]) return;
	if (y <= TIME) return;
	arr[x][y] = 1;
	q.push({ x,y });
}

void bfs() {
	while (q.size()>1) {
		if (CLEAR) return;
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x !=INF && y <= TIME) continue;
		if (x == INF) {
			TIME++;
			q.push({ INF, 0 });
		}
		else {
			check(x, y + 1);
			check(x, y - 1);
			x == 0 ? check(1, y + K) : check(0, y + K);
		}
	}
}
int main() {
	FASTIO;
	cin >> N >> K;
	char temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		temp == '1' ? arr[0][i] = 0 : arr[0][i] = 1;
	}
	for (int i = 0; i < N; i++) {
		cin >> temp;
		temp == '1' ? arr[1][i] = 0 : arr[1][i] = 1;
	}
	q.push({ 0,0 });
	q.push({ INF, 0 });
	arr[0][0] = 1;
	bfs();
	cout << CLEAR;
	return 0;
}