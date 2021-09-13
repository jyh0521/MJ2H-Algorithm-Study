#include <iostream>
using namespace std;

#define endl '\n'

int main() {
	int cnt = 1;
	int result;

	cin >> result;

	int num;
	char op;

	while (1) {
		if (cnt % 2 == 0) {
			cin >> num;
		
			if (op == '+')
				result += num;
			else if (op == '-')
				result -= num;
			else if (op == '/')
				result /= num;
			else if (op == '*') 
				result *= num;
			else if (op == '=') {
				cout << result << endl;
				return 0;
			}

		}
		else cin >> op;

		cnt++;
	}

	return 0;
}