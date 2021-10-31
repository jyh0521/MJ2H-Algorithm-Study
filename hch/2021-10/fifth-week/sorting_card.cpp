#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
int N;
priority_queue<int>pq;

void input()
{
	FASTIO;

	int tmp;
	cin >> N;
	for (int i = 0 ; i < N; i++) {
		cin >> tmp;
		pq.push(-tmp);
	}
}

void solve()
{
	int ans = 0, tmp;

	if (N != 1) 
	{
		while (!pq.empty())
		{
			tmp = -pq.top();
			if (pq.size() >= 2) {
				pq.pop();
				tmp += (-pq.top());
			}
			pq.pop();
			ans += tmp;
			if (!pq.empty())
				pq.push(-tmp);
		}
	}
	cout << ans;
}

int main()
{
	input();
	solve();
	return (0);
}
