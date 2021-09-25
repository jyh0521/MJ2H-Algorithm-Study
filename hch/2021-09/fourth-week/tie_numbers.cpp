//1744
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> positive;
vector<int> negative;
int N, positive_size, negative_size, ans;

void io_faster()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input()
{
	int tmp;

	io_faster();
	cin >> N;
	positive.reserve(10001);
	negative.reserve(10001);
	for (int i = 0 ; i < N ; i++)
	{
		cin >> tmp;
		if (tmp == 1)
			ans++;
		else
			tmp <= 0 ? negative.push_back(tmp) : positive.push_back(tmp);
	}
	positive_size = positive.size();
	negative_size = negative.size();
}

/* 
 * 아이디어
 * => 두 수를 묶을 수 있기 때문에, 음수면 음수끼리, 양수면 양수끼리 최대한 절대값이 큰 수 끼리 먼저 곱하도록 한다.
*/

void solve()
{
	sort(positive.begin(), positive.end());
	sort(negative.begin(), negative.end());
	for (int i = positive_size - 2 ; i >= 0 ; i-=2)
		ans += positive[i] * positive[i + 1];
	if (positive_size % 2) // 0을 제외한 양수가 원소인 벡터의 사이즈가 홀수이면
		ans += positive[0];
	for (int i = 1 ; i < negative_size ; i+=2)
		ans += negative[i] * negative[i - 1];
	if (negative_size % 2)
		ans += negative.back();

	cout << ans;
}

int main()
{
	input();
	solve();
	return (0);
}

