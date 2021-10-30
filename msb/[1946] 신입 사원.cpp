#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
vector<pair<int, int>> v;
int T, N;
int main() {
	FASTIO;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		v.clear();
		int a, b;
		for (int i = 0; i < N; i++) {
			cin >> a >> b;
			v.push_back({ a,b });
		}
		sort(v.begin(), v.end());
		
		int minimum = N, cnt = N;
		for (int i = 0; i < N; i++) {
			if (v[i].second > minimum) cnt--;
			else minimum = v[i].second;
		}
		cout << cnt << '\n';
	}
	return 0;
}