#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define MAX 100001

int n, k;

// 0�� ����, 1�� ������
string line[2];
bool visited[2][MAX];

void bfs() {
	// ���� ��ǥ, �� ��ġ, �ð�
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(0, 0, 0));
	visited[0][0] = true;

	while (!q.empty()) {
		int pos, dir, time;
		tie(pos, dir, time) = q.front();
		q.pop();

		if (pos < time) 
			continue;

		if (pos + 1 > n - 1 || pos + k > n - 1) {
			cout << 1 << endl;
			return;
		}
		else {
			// ��ĭ ������ �̵�
			if (line[dir][pos + 1] == '1' && !visited[dir][pos + 1]) {
				q.push(make_tuple(pos + 1, dir, time + 1));
				visited[dir][pos + 1] = true;
			}

			// �ݴ��� �ٷ� ����
			if (line[dir == 0 ? 1 : 0][pos + k] == '1' && !visited[dir == 0 ? 1 : 0][pos + k]) {
				q.push(make_tuple(pos + k, dir == 0 ? 1 : 0, time + 1));
				visited[dir == 0 ? 1 : 0][pos + k] = true;
			}
		}

		// ��ĭ �ڷ� �̵�
		if (pos - 1 >= time && line[dir][pos - 1] == '1' && !visited[dir][pos - 1]) {
			q.push(make_tuple(pos - 1, dir, time + 1));
			visited[dir][pos - 1] = true;
		}
	}

	cout << 0 << endl;
	return;
}

int main() {
	FASTIO;

	cin >> n >> k;
	cin >> line[0];
	cin >> line[1];

	bfs();

	return 0;
}