//5052
#include <iostream>
#include <algorithm>
#include <string>
#define endl "\n"

int t, n;
std::string phone_number[10001];

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> t;
}

bool is_consistency(std::string a, std::string b) {
	int length = a.size() > b.size() ? b.size() : a.size();

	for (int i = 0 ; i < length ; i++) {
		if (a[i] != b[i]) 
			return true;
	}
	return false;
}

void print_yes() {
	std::cout << "YES" << endl;
}

void print_no() {
	std::cout << "NO" << endl;
}

void solve()
{
	int consistency_flag;

	while (t--) {
		std::cin >> n;
		for (int i = 0 ; i < n ; i++)
			std::cin >> phone_number[i];
		if (n == 1) {
			print_yes();
			continue;
		}
		consistency_flag = 1;
		std::sort(phone_number, phone_number + n);
		for (int i = 1 ; consistency_flag && i < n ; i++) {
			if (!is_consistency(phone_number[i], phone_number[i - 1])) {
				print_no();
				consistency_flag = 0;
			}
		}
		if (consistency_flag)
			print_yes();
	}
}

int main()
{
	input();
	solve();
	return (0);
}
