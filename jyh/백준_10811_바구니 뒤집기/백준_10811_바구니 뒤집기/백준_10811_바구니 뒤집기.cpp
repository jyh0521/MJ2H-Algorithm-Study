#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'

int n, m;

int main() {
	FASTIO;

	cin >> n >> m;

	vector<int> v;

	for (int i = 1; i <= n; i++)
		v.push_back(i);

	for (int i = 0; i < m; i++) {
		int sB, eB;
		cin >> sB >> eB;

		sB--;

		reverse(v.begin() + sB, v.begin() + eB);
	}

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';
	cout << endl;

	return 0;
}