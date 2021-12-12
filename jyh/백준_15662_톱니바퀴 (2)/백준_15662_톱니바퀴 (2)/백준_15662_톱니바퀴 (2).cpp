#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'

int t, k;
vector<string> v;

string rotate(string str, int dir) {
	if (dir == 1) { // 시계
		rotate(str.begin(), str.end() - 1, str.end());
	}
	else { // 반 시계
		rotate(str.begin(), str.begin() + 1, str.end());
	}

	return str;
}

int main() {
	FASTIO;

	cin >> t;

	for (int i = 0; i < t; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}
	
	cin >> k;

	while (k--) {
		int num, dir;
		cin >> num >> dir;

		num--;

		vector<string> result(t);

		result[num] = rotate(v[num], dir);

		int tmpDir = dir;

		bool flag = true;

		for (int i = num; i >= 1; i--) { // 현재를 기준으로 왼쪽 검사
			if (flag && v[i][6] != v[i - 1][2]) { // 돌리기
				tmpDir *= -1;
				result[i - 1] = rotate(v[i - 1], tmpDir);
				flag = true;
			}
			else {
				flag = false;
				result[i - 1] = v[i - 1];
			}
		}

		tmpDir = dir;
		flag = true;

		for (int i = num; i < t - 1; i++) { // 현재를 기준으로 오른쪽 검사
			if (flag && v[i][2] != v[i + 1][6]) {
				tmpDir *= -1;
				result[i + 1] = rotate(v[i + 1], tmpDir);
				flag = true;
			}
			else {
				flag = false;
				result[i + 1] = v[i + 1];
			}
		}

		v = result;
	}

	int ans = 0;

	for (int i = 0; i < t; i++) {
		if (v[i][0] == '1')
			ans++;
	}

	cout << ans << endl;

	return 0;
}