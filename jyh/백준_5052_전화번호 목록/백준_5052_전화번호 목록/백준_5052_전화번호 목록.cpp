#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'

typedef long long ll;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<vector<string>> v(10);
		
		for (int i = 0; i < n; i++) {
			string phone;
			cin >> phone;

			v[phone[0] - '0'].push_back(phone);
		}

		for (int i = 0; i < 10; i++) // sort�� ���ص� �ɰŶ�� �����ߴµ� ���ϸ� Ʋ��
			sort(v[i].begin(), v[i].end());

		bool flag = false;

		for (int i = 0; i < 10; i++) { // 0������ 9������ ��ȸ
			for (int j = 0; j < v[i].size(); j++) { // ��ȣ�� �� �� ���� ���������� ���
				for (int k = j + 1; k < v[i].size(); k++) { // ������ + 1���� ��
					flag = true;

					for (int l = 0; l < v[i][j].size(); l++) { // �������� ���̸�ŭ ���ؼ� �ٸ� ��찡 �ִٸ� �ٷ� false �� break
						if (v[i][j][l] != v[i][k][l]) {
							flag = false;
							break;
						}
					}

					if (flag == true) break; // �������� ���� ��ŭ ������ + 1�� ���̰� ���� �����̶�� break �ٷ� �ش� �׽�Ʈ ���̽��� �����Ѵ�.
				}

				if (flag == true) break;
			}

			if (flag == true) break;
		}

		if (!flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}