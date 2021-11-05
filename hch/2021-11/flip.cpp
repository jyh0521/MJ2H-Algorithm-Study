//1439
#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"
string S;

void input()
{
	FASTIO;
	cin >> S;
}

void solve()
{
	int s_size = S.size();
	int zo_flag = S[0] - '0'; // zero one flag
	int zero_one[2] = {0, 0};
	zero_one[!zo_flag] = 1;
	for (int i = 1 ; i < s_size ; i++)
	{
		if (zo_flag != (S[i] - '0')) 
		{
			zero_one[zo_flag]++;
			zo_flag = !zo_flag;
		}
	}
	cout << min(zero_one[0], zero_one[1]);
}

int main()
{
	input();
	solve();
	return (0);
}

