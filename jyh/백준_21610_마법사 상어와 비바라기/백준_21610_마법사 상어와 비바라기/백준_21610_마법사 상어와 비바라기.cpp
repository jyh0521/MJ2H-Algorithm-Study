#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'

int n, m;
int arr[50][50];
vector<pair<int, int>> cloud;

int dX[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dY[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

int main() {
	FASTIO;
	
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	// ���۽� ���� ��ġ
	cloud.push_back({ n - 1, 0 });
	cloud.push_back({ n - 1, 1 });
	cloud.push_back({ n - 2, 0 });
	cloud.push_back({ n - 2, 1 });

	for (int k = 0; k < m; k++) {
		vector<pair<int, int>> newCloud;
		int d, s;
		cin >> d >> s;

		d--;

		// 1. ������ d �������� s��ŭ �̵�
		for (int i = 0; i < cloud.size(); i++) {

			// ��� ��� ��� ó��
			for (int j = 0; j < s; j++) {
				cloud[i].first += dX[d];
				cloud[i].second += dY[d];

				if (cloud[i].first == -1) cloud[i].first = n - 1;
				if (cloud[i].first == n) cloud[i].first = 0;

				if (cloud[i].second == -1) cloud[i].second = n - 1;
				if (cloud[i].second == n) cloud[i].second = 0;
			}
		}

		// 2. �� ������
		for (int i = 0; i < cloud.size(); i++)
			arr[cloud[i].first][cloud[i].second]++;

		// 4. ���� ������ ĭ�� �� ����
		for (int i = 0; i < cloud.size(); i++) {
			int x = cloud[i].first;
			int y = cloud[i].second;

			for (int j = 1; j <= 7; j += 2) { // 2, 4, 6, 8�� �밢�� ����
				int nX = x + dX[j];
				int nY = y + dY[j];

				if (!(0 <= nX && nX < n && 0 <= nY && nY < n)) continue;

				if (arr[nX][nY] <= 0) continue;
				arr[x][y]++;
			}
		}

		// 5. �ٱ��Ͽ� ����� ���� ���� 2 �̻��� ��� ĭ�� ������ �����, ���� ���� 2 �پ���. �̶� 3���� ����� ������ ��ġ���� ������ �ʴ´�.
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] < 2) continue;

				if (find(cloud.begin(), cloud.end(), make_pair(i, j)) == cloud.end()) { // �ش� ��ġ�� ������ 3������ ����� ������ �ƴ϶��
					newCloud.push_back({ i, j });
					arr[i][j] -= 2;
				}
			}
		}

		// 3. ������ ������ ��� �������.
		cloud = newCloud;
	}

	int result = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			result += arr[i][j];

	cout << result << endl;

	return 0;
}