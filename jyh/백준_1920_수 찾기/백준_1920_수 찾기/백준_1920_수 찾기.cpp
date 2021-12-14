#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'

int n, m;

vector<int> v1;
vector<int> v2;

void input(int c, vector<int> &v) {
	for (int i = 0; i < c; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
}

int main() {
	FASTIO;

	cin >> n;

	input(n, v1);

	sort(v1.begin(), v1.end());

	cin >> m;

	input(m, v2);

	for (int i = 0; i < m; i++) {
		bool flag = false;

		int start = 0;
		int end = n - 1;

		while (true) {
			int	middle = (start + end) / 2;
			
			if (v1[middle] == v2[i]) {
				flag = true;
				cout << 1 << endl;
				break;
			}
			else if (v1[middle] > v2[i]) {
				end = middle - 1;
			}
			else if (v1[middle] < v2[i]){
				start = middle + 1;
			}

			if (start > end) {
				break;
			}
		}

		if (!flag)
			cout << 0 << endl;
	}

	return 0;
}