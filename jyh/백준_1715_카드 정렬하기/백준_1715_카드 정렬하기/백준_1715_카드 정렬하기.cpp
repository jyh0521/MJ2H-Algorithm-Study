#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define MAX 100001

int n;

int main() {
	FASTIO;

	cin >> n;

	priority_queue<int, vector<int>, greater<int>> q;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		q.push(num);
	}

	int sum = 0;

	while (true) {
		if (q.size() == 1)
			break;

		int a = q.top();
		q.pop();
		int b = q.top();
		q.pop();

		sum += a + b;
		q.push(a + b);
	}
	cout << sum << endl;

	return 0;
}