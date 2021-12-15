#include <iostream>
#include <algorithm>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'

int main() {
	FASTIO;

	while (true) {
		int num[3];

		for (int i = 0; i < 3; i++)
			cin >> num[i];

		if (num[0] == 0 && num[1] == 0 && num[2] == 0)
			break;

		sort(num, num + 3);

		if ((num[0] * num[0]) + (num[1] * num[1]) == (num[2] * num[2]))
			cout << "right" << endl;
		else
			cout << "wrong" << endl;
	}

	return 0;
}