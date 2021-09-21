#include <iostream>
#include <algorithm>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'

string arr[10001];

int main() {
	FASTIO;

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		for (int i = 0; i < n; i++) cin >> arr[i];

		sort(arr, arr + n);
		
		bool flag = true;

		for (int i = 0; i < n - 1; i++) {
			flag = true;

			for (int j = 0; j < arr[i].length(); j++) {
				if (arr[i][j] != arr[i + 1][j]) {
					flag = false;
					break;
				}
			}

			if (flag) {
				cout << "NO" << endl;
				break;
			}
		}

		if (!flag) cout << "YES" << endl;
	}

	return 0;
}