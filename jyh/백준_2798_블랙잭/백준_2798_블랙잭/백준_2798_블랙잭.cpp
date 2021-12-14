#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'

int n, m;
vector<int> v;

int main() {
	FASTIO;

	cin >> n >> m;

	for(int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	int result = 0;

	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				int sum = v[i] + v[j] + v[k];
				if (sum > m) break;

				if (result < sum)
					result = sum;
			}
		}
	}

	cout << result << endl;

	return 0;
}