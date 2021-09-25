#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define MAX 10000

int n, result = 0;
bool zero = false;

vector<int> plusNum;
vector<int> minusNum;

bool op(int a, int b) {
	return a > b;
}

int main() {
	FASTIO;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (num < 0) minusNum.push_back(num);
		else if (num == 1) result++;
		else if (num > 1) plusNum.push_back(num);
		else if(num == 0) zero = true;
	}

	sort(minusNum.begin(), minusNum.end());
	sort(plusNum.begin(), plusNum.end(), op);
	
	if (plusNum.size() % 2 == 0) { // 전부 곱셈이 가능한 경우
		for (int i = 0; i < plusNum.size(); i += 2) result += plusNum[i] * plusNum[i + 1];
	}
	else {
		for (int i = 0; i < plusNum.size() - 1; i += 2) result += plusNum[i] * plusNum[i + 1];
		result += plusNum[plusNum.size() - 1];
	}

	if (minusNum.size() % 2 == 0) { // 전부 곱셈이 가능한 경우
		for (int i = 0; i < minusNum.size(); i += 2) result += minusNum[i] * minusNum[i + 1];
	}
	else {
		for (int i = 0; i < minusNum.size() - 1; i += 2) result += minusNum[i] * minusNum[i + 1];

		if (!zero) {
			result += minusNum[minusNum.size() - 1];
		}
	}

	cout << result << endl;

	return 0;
}