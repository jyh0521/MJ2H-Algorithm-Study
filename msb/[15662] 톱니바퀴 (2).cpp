#include <iostream>
#include <vector>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
bool v[1001][8];
int info[1001] = { 0 };
int T, K;
void findOut(int n, int prev, int direc) {
	if (!direc) return;
	if (n < 1 || n>T) return;

	if (n == prev - 1 && v[n][2] == v[prev][6]) return;
	if (n == prev + 1 && v[n][6] == v[prev][2]) return;
	
	info[n] = direc == 1 ? -1 : 1;

	if (prev != (n + 1) && n != T)
		findOut(n + 1, n, direc == 1 ? -1 : 1);
	if (prev != (n - 1) && n != 1)
		findOut(n - 1, n, direc == 1 ? -1 : 1);
}

void rotateClockwise(int n) {
	bool prev = v[n][0], temp;
	int step = 1;
	for (int i = 0; i < 8; i++) {
		temp = v[n][(i + step) % 8];
		v[n][(i + step) % 8] = prev;
		prev = temp;
	}
}
void rotate(int n) {
	bool prev = v[n][7], temp;
	int step = 7;
	for (int i = 7; i >= 0; i--) {
		temp = v[n][(i + step) % 8];
		v[n][(i + step) % 8] = prev;
		prev = temp;
	}
}
int main() {
	FASTIO;
	cin >> T;
	char num;
	for (int i = 1; i <= T; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> num;
			v[i][j] = num-'0';
		}
	}
	cin >> K;
	int a, b;
	for (int i = 0; i < K; i++) {
		for (int j = 1; j <= T; j++)
			info[j] = 0;
		cin >> a >> b;
		info[a] = b;
		findOut(a-1, a, b);
		findOut(a+1, a, b);
		for (int j = 1; j <= T; j++) {
			if (info[j] == 1) rotateClockwise(j);
			else if (info[j] == -1) rotate(j);
		}
	}
	int cnt = 0;
	for (int i = 1; i <= T; i++) {
		if (v[i][0] == 1) cnt++;
	}
	cout << cnt;
	return 0;
}