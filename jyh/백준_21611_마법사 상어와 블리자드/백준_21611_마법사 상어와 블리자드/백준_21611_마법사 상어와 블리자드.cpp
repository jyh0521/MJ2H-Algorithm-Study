#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define MAX 50

int n, m, d, s;
int arr[MAX][MAX];
int result[3];
vector<pair<int, int>> v; // 0 ~ �� ��ȣ ���� ��ǥ

// ��, ��, ��, ��
int dX[4] = { -1, 1, 0, 0 };
int dY[4] = { 0, 0, -1, 1 };

void getSnake() {
	// ��� ��
	v.push_back({ n / 2, n / 2 });

	int cnt = n * 2 - 1;
	int goNum = 1;
	int dir = 2; // ���ʺ��� ����
	int x = n / 2;
	int y = n / 2;
	int num = 1;
	int rotateCnt = 0;

	while (cnt--) { // cnt�� ���δ�.
		bool flag = false;

		for (int i = 0; i < goNum; i++) { // goNum�� �̵�
			x += dX[dir];
			y += dY[dir];

			v.push_back({ x, y });

			if (x == 0 && y == 0) {
				flag = true;
				break;
			}
		}

		if (flag)
			break;

		if (dir == 0)
			dir = 2;
		else if (dir == 1)
			dir = 3;
		else if (dir == 2)
			dir = 1;
		else if (dir == 3)
			dir = 0;

		rotateCnt++;

		if (rotateCnt == 2) {
			rotateCnt = 0;
			goNum++;
		}
	}
}

void getFront() {
	queue<int> q;

	for (int i = 1; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;

		if (arr[x][y] == 0) continue;

		q.push(arr[x][y]);
	}

	for (int i = 1; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;

		if (q.empty())
			arr[x][y] = 0;
		else {
			arr[x][y] = q.front();
			q.pop();
		}
	}
}

int main() {
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	getSnake();

	int startX = n / 2, startY = n / 2;

	while (m--) { // ���ڵ� m�� ����
		cin >> d >> s;
		d--; // d�� 0���� ����

		int nextX = startX, nextY = startY;

		// ���ڵ�
		for (int i = 0; i < s; i++) {
			nextX += dX[d];
			nextY += dY[d];

			arr[nextX][nextY] = 0;
		}

		// ���� ����
		getFront();

		while (true) {
			bool flag = false;

			// 4�� �̻� ���� ���� ����
			int cnt = 0;
			int number = 0;
			int pos = 0;

			for (int i = 1; i < v.size(); i++) {
				int x = v[i].first;
				int y = v[i].second;
				pos++;

				if (arr[x][y] == 0) {
					break; // ���� ������ 0�� ���� �� ���� ���
				}

				if (number == 0) {
					number = arr[x][y];
					cnt++;
				}
				else {
					if (number == arr[x][y]) { // ���� ������ �������
						cnt++;
					}
					else { // ���� ������ �ٸ� ���
						if (cnt >= 4) { // ���� ������ 4�� �̻��� ��
							// ���ڹߡ�
							for (int j = pos - 1; j >= pos - cnt; j--) {
								int aX = v[j].first;
								int aY = v[j].second;

								arr[aX][aY] = 0;
								flag = true;
							}

							result[number - 1] += cnt;
						}

						number = arr[x][y];
						cnt = 1;
					}
				}
			}

			if (cnt >= 4) { // ���� ������ 4�� �̻��� ��
							// ���ڹߡ�
				for (int j = pos - 1; j >= pos - cnt; j--) {
					int aX = v[j].first;
					int aY = v[j].second;

					arr[aX][aY] = 0;
					flag = true;
				}

				result[number - 1] += cnt;
			}

			if (!flag)
				break;

			// ���� �� ���� ����
			getFront();
		}

		// ���� ��ȭ
		queue<int> q2;

		int number = 0;
		int cnt = 0;

		for (int i = 1; i < v.size(); i++) {
			int x = v[i].first;
			int y = v[i].second;

			if (arr[x][y] == 0) 
				break;

			if (number == 0) {
				number = arr[x][y];
				cnt++;
			}
			else {
				if (number == arr[x][y]) {
					cnt++;
				}
				else {
					q2.push(cnt);
					q2.push(number);

					cnt = 1;
					number = arr[x][y];
				}
			}
		}

		q2.push(cnt);
		q2.push(number);

		for (int i = 1; i < v.size(); i++) {
			int x = v[i].first;
			int y = v[i].second;

			if (q2.empty()) {
				arr[x][y] = 0;
			}
			else {
				arr[x][y] = q2.front();
				q2.pop();
			}
		}
	}

	cout << result[0] * 1 + result[1] * 2 + result[2] * 3 << endl;

	return 0;
}