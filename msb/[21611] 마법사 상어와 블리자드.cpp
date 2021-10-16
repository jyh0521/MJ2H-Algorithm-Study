#include <iostream>
#include <vector>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
vector<pair<int, int>> v;
int N, M, arr[51][51], res[4] = { 0 };
int d[5][2] = { {0,0}, {-1,0},{1,0},{0,-1},{0,1} }, r[4][2] = { {0,-1},{1,0},{0,1},{-1,0} };
void blizard(int dir, int s) {
	int x = (N + 1) / 2, y = (N + 1) / 2;
	for (int i = 1; i <= s; i++) {
		int nx = x + d[dir][0] * i;
		int ny = y + d[dir][1] * i;
		arr[nx][ny] = 0;
	}
}
bool map() {
	bool res = 0;
	int x = (N + 1) / 2, y = (N + 1) / 2, flag = 0, idx = 0, idx_cnt = 0;

	pair<int, int> seq = { 0,0 };
	int dist = 1, direction = 0;
	while (!(x == 1 && y == 1)) {
		if (flag == 2) {
			dist++;
			flag = 0;
		}
		flag++;

		for (int i = 0; i < dist; i++) {
			x += r[direction][0];
			y += r[direction][1];
			if (v.empty() || idx > v.size() - 1) arr[x][y] = 0;
			else {
				arr[x][y] = v[idx].first;
				if (arr[x][y] == seq.first) {
					++seq.second;
					if (seq.second >= 4) {
						res = 1;
					}
				}
				else {
					seq.first = arr[x][y];
					seq.second = 1;
				}
				if (!(--v[idx].second)) idx++;
			}
			if (x == 1 && y == 1) break;
		}
		direction = (direction + 1) % 4;
	}
	v.clear();
	return res;
}

void explosion() {
	bool repeat = 1, first = 1;
	while (repeat) {
		if (first) first = 0;
		else repeat = map();

		int x = (N + 1) / 2, y = (N + 1) / 2, flag = 0, dist = 1, direction = 0;
		while (!(x == 1 && y == 1)) {
			if (flag == 2) {
				dist++;
				flag = 0;
			}
			flag++;
			for (int i = 0; i < dist; i++) {
				x += r[direction][0];
				y += r[direction][1];
				if (!arr[x][y] && !(x==1&&y==1)) continue;
				if (!arr[x][y] && (x == 1 && y == 1)) break;
				if (!v.empty() && arr[x][y] == v.back().first) v.back().second++;
				else {
					if (!v.empty() && v.back().second >= 4) {
						res[v.back().first] += v.back().second;
						v.pop_back();
					}
					v.push_back({ arr[x][y], 1 });
				}
				if (x == 1 && y == 1) break;
			}
			direction = (direction + 1) % 4;
		}
		if (!v.empty() && v.back().second >= 4) {
			res[v.back().first] += v.back().second;
			v.pop_back();
		}
	}
}

void change() {
	int x = (N + 1) / 2, y = (N + 1) / 2, total = 1, flag = 0, dist = 1, direction = 0, idx = 0;
	bool next = 0;
	while (!(x == 1 && y == 1)) {
		if (flag == 2) {
			dist++;
			flag = 0;
		}
		flag++;
		for (int i = 0; i < dist; i++) {
			x += r[direction][0];
			y += r[direction][1];
			if (v.empty() || idx > v.size() - 1) arr[x][y] = 0;
			else if (!next) arr[x][y] = v[idx].second;
			else if (next) {
				arr[x][y] = v[idx].first;
				idx++;
			}
			next = !next;
			if (x == 1 && y == 1) break;
		}
		direction = (direction + 1) % 4;
	}
	v.clear();
}

int main() {
	FASTIO;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
	int d, s;
	for (int i = 0; i < M; i++) {
		cin >> d >> s;
		blizard(d, s);
		explosion();
		change();
	}
	cout << res[1] + res[2] * 2 + res[3] * 3;
	return 0;
}