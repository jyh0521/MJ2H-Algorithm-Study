//1946
#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"
int T, N;
int max_rank;

pair<int, int> new_recruit[100002];

void input()
{
	FASTIO;
	cin >> T;
}

bool compare(pair<int, int> a, pair<int, int> b)
{
	return (a.first < b.first);
}

void solve()
{
	int ans;

	while (T--)
	{
		cin >> N;
		max_rank = 100002; // 최소 등수로 초기화
		ans = 0;
		for (int i = 0 ; i < N ; i++)
			cin >> new_recruit[i].first >> new_recruit[i].second;
		sort(new_recruit, new_recruit + N, compare);
		for (int i = 0 ; i < N ; i++)
		{
			if (new_recruit[i].second > max_rank)
				continue;
			ans++;
			if (max_rank > new_recruit[i].second)
				max_rank = new_recruit[i].second;
		}
		cout << ans << endl;
	}
}

int main()
{
	input();
	solve();
	return (0);
}
