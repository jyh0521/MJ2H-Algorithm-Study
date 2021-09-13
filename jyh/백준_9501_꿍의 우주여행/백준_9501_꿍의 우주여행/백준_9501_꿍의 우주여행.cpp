#include <iostream>
using namespace std;

#define endl '\n'

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, d;
		cin >> n >> d;

		int cnt = 0;

		while (n--) {
			int v, f, c;
			cin >> v >> f >> c;

			if (((double)f / c) * v >= d) cnt++;
		}

		cout << cnt << endl;
	}
		
	return 0;
}