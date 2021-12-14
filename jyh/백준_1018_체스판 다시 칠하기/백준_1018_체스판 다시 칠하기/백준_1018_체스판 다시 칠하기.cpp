#include <iostream>
#include <vector>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'

int n, m;
string board[2][8];

vector<string> v;

void makeBoard(int c) {
	string line[2] = { "WBWBWBWB", "BWBWBWBW" };
	int idx = c;

	for (int j = 0; j < 8; j++) {
		board[c][j] = line[idx];
		idx = idx == 0 ? 1 : 0;
	}
}

int main() {
	FASTIO;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;

		v.push_back(tmp);
	}

	for (int i = 0; i < 2; i++)
		makeBoard(i);

	int sX = 0, sY = 0;
	int eX = 7, eY = 7;
	int result = 99999999;
	
	while (true) {
		string tmp[8];

		int idx = 0;

		for (int i = sY; i <= eY; i++) {
			string str = "";

			for (int j = sX; j <= eX; j++) {
				str += v[i][j];
			}

			tmp[idx] = str;
			idx++;
		}

		for (int k = 0; k < 2; k++) {
			int difCnt = 0;
			
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					if (board[k][i][j] != tmp[i][j])
						difCnt++;
				}
			}

			if (result > difCnt)
				result = difCnt;
		}

		if (eX + 1 < m) {
			sX++;
			eX++;
		}
		else {
			sX = 0;
			eX = 7;
			sY++;
			eY++;
		}

		if (!(0 <= sX && eX < m && 0 <= sY && eY < n))
			break;
	}

	cout << result << endl;

	return 0;
}