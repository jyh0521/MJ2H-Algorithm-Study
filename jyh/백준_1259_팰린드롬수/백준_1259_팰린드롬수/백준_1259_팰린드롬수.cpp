#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'

int main() {
	FASTIO;

	while (true) {
		int num;
		cin >> num;

		if (num == 0)
			break;

		string str = to_string(num);
		string tmp = "";

		bool flag = true;
		int half = str.length() / 2;

		if (str.length() % 2 == 0) { // 짝수 자리인 경우
			for (int i = half; i < str.length(); i++)
				tmp += str[i];
		}

		else { // 홀수 자리인 경우
			for (int i = half + 1; i < str.length(); i++)
				tmp += str[i];
		}

		reverse(tmp.begin(), tmp.end());

		for (int i = 0; i < half; i++) {
			if (tmp[i] != str[i]) {
				flag = false;
				break;
			}
		}

		if (flag)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}

	return 0;
}