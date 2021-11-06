#include <iostream>
#include <vector>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'

string s;
int result1 = 999999999, result2 = 999999999;
int zeroCnt = 0, oneCnt = 0;

int getResult() {
	for (int i = 0; i < s.length() - 1; i++) {
		if (s[i] != s[i + 1]) {
			if (s[i] == '0')
				zeroCnt++;
			else
				oneCnt++;
		}
	}

	return zeroCnt > oneCnt ? zeroCnt : oneCnt;
}

int main() {
	FASTIO;

	cin >> s;

	result1 = getResult();

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '0')
			s[i] = '1';
		else
			s[i] = '0';
	}

	zeroCnt = 0; oneCnt = 0;

	result2 = getResult() + 1;

	cout << (result1 < result2 ? result1 : result2) << endl;

	return 0;
}