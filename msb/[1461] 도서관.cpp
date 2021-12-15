#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, M, ANS, DIST = 0;
vector<int> m, p;
void solve(vector<int>& v) {
	sort(v.begin(), v.end());
	
	if (!v.empty())
		DIST = max(DIST, v.back());

	while (!v.empty()) {
		int size = min((int)v.size(), M);
		ANS += v.back() * 2;
		for (int i = 0; i < size; i++) 
			v.pop_back();
	}
}

int main() {
	FASTIO;
	cin >> N >> M;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		temp > 0 ? p.push_back(temp) : m.push_back(-temp);
	}

	solve(p);
	solve(m);

	cout << ANS - DIST;
	return 0;
}