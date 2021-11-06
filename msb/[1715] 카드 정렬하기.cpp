#include <iostream>
#include <queue>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, RES = 0;
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
	FASTIO;
	cin >> N;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		pq.push(temp);
	}
	
	int first, second;
	while (pq.size() > 1) {
		first = pq.top();
		pq.pop();
		second = pq.top();
		pq.pop();
		pq.push(first + second);
		RES += first + second;
	}
	cout << RES;
	return 0;
}