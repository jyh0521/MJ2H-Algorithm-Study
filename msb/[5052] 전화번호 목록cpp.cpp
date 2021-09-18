#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;
int T, N;
vector<string> list;

bool check(int i) {
		for (int j = 0; j < list[i - 1].size(); j++) {
			if (list[i][j] != list[i - 1][j]) return true;
		}
		return false;
}

int main() {
	FASTIO;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		list.clear();
		string phoneNumber;
		bool flag = true;

		for (int i = 0; i < N; i++) {
			cin >> phoneNumber;
			list.push_back(phoneNumber);
		}
		sort(list.begin(), list.end());

		for (int i = 1; i < N; i++) {
			if (!check(i)) flag = false;
		}
		flag ? cout << "YES\n" : cout << "NO\n";
	}
	return 0;
}