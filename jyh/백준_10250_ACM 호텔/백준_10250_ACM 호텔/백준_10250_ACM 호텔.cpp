#include <iostream>
#include <string>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'

int main() {
	FASTIO;

	int t;
	cin >> t;

	while (t--) {
		int h, w, n;
		cin >> h >> w >> n;

		string result = to_string(n % h == 0 ? h : n % h);

		if (n % h == 0) {
			result += n / h >= 10 ? to_string(n / h) : "0" + to_string(n / h);
		}
		else {
			result += n / h + 1 >= 10 ? to_string(n / h + 1) : "0" + to_string(n / h + 1);
		}

		cout << result << endl;
	}

	return 0;
}