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

		for (int i = 0; i < 10; i++) // sort를 안해도 될거라고 생각했는데 안하면 틀림
			sort(v[i].begin(), v[i].end());

		bool flag = false;

		for (int i = 0; i < 10; i++) { // 0번부터 9번까지 순회
			for (int j = 0; j < v[i].size(); j++) { // 번호의 맨 앞 부터 기준점으로 잡고
				for (int k = j + 1; k < v[i].size(); k++) { // 기준점 + 1부터 비교
					flag = true;

					for (int l = 0; l < v[i][j].size(); l++) { // 기준점의 길이만큼 비교해서 다른 경우가 있다면 바로 false 후 break
						if (v[i][j][l] != v[i][k][l]) {
							flag = false;
							break;
						}
					}

					if (flag == true) break; // 기준점의 길이 만큼 기준점 + 1의 길이가 같은 내용이라면 break 바로 해당 테스트 케이스를 종료한다.
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