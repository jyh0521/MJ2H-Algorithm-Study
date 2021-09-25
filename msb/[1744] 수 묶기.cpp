#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, res = 0;
bool zero = false;
vector<int> positive, negative;

void solve(vector<int>& v, bool pos) {
	while (!v.empty()) {
		int first = v.back();
		v.pop_back();
		if (v.empty()) {
			if (!(!pos&&zero))
				res += first;
			return;
		}
		if (pos && v.back() == 1) 
			res += first + 1;
		else
			res += first * v.back();
		v.pop_back();
	}
}

int main() {
	FASTIO;
	cin >> N;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (!temp) 
			zero = true;
		else
			(temp > 0) ? positive.push_back(temp) : negative.push_back(temp);
	}
	
	sort(positive.begin(), positive.end());
	sort(negative.begin(), negative.end(), greater<int>());

	solve(positive, true);
	solve(negative, false);

	cout << res << '\n';
	return 0;
}