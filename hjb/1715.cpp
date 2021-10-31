#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<ll>v, nv;
priority_queue<ll, vector<ll>, greater<ll>> pq;
ll ans;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a; cin >> a;
		pq.push(a);
	}

	//n이 1인 경우에는 비교를 할 필요가 없으니 0이다.
	//따라서 while문을 pq.size가 2개 이상인 것들을 기준으로 해서 (앞+뒤) + (앞+뒤)를 해주면 된다.
	while (pq.size() > 1) {
		ll bfr = pq.top();
		pq.pop();
		ll now = pq.top();
		pq.pop();
		ans += bfr + now;
		pq.push(bfr + now);
	}
	cout << ans;
}
