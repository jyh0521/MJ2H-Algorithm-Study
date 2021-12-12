#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'

int n, m;
vector<int> v1; // -
vector<int> v2; // +

int main() {
	FASTIO;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (num < 0)
			v1.push_back(-num);
		else
			v2.push_back(num);
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	int result1 = 0;
	int result2 = 0;


	for (int i = v2.size() - 1; i >= 0; i -= m) {
		result1 += 2 * v2[i];
	}
	for (int i = v1.size() - 1; i >= 0; i -= m) {
		if (i == v1.size() - 1)
			result1 += v1[i];
		else
			result1 += 2 * v1[i];
	}

	for (int i = v1.size() - 1; i >= 0; i -= m) {
		result2 += 2 * v1[i];
	}
	for (int i = v2.size() - 1; i >= 0; i -= m) {
		if (i == v2.size() - 1)
			result2 += v2[i];
		else
			result2 += 2 * v2[i];
	}
	
	cout << (result1 < result2 ? result1 : result2) << endl;

	return 0;
}