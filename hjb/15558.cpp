#include<iostream>
#include<string>
#include<queue>
using namespace std;
typedef pair<int, int>pi;
typedef pair<pi, int>pii;

int N, k;
string str[2];
bool visited[2][100005];
queue<pii>q;
vector<int>dy = { 1,-1};

/*
시간 복잡도 : 최대 200000
bfs : O(V+E) 노드 + 엣지
한 칸 마다, 3칸 씩 이동할 수 있는 것은 맞지만
이미 방문한 칸으로는 다시 돌아갈 수 없기 때문에,
결국 각 칸의 개수만큼의 시간만 걸리게 된다.
*/

bool bfs() {
	q.push({ { 0,0 },0 });
	visited[0][0] = 1;

	while (!q.empty()) {
		int line = q.front().first.first;
		int idx = q.front().first.second;
		int time = q.front().second; //이번에 파괴되는 칸의 번호
		q.pop();

		//현재 칸이 마지막칸(N-1)보다 큰 경우
		if (idx >= N - 1) return 1;

		for (int i = 0; i < 3; i++)
		{
			int nx = (i == 2) ? !line : line;
			int ny = idx + dy[i];

			//이번에 파괴되는 번호보다 같거나 작은 칸으로 가려는 경우를 방지함
			//-> 이번에 3번째 칸이 파괴될 예정인데, 3번째 칸으로 건너가는 것은 말이 안되기 때문이다.
			if (time < ny && 0 <= ny) {
				//다음 위치로 추정되는 칸이 이미 마지막 칸을 넘어서는 경우
				if (ny > N - 1) return 1;

				if (visited[nx][ny]) continue;

				if (str[nx][ny] == '1') {
					q.push({ { nx, ny },time + 1});
					visited[nx][ny] = 1;
				}
			}
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> k;
	cin >> str[0] >> str[1];
	dy.push_back(k);

	cout << bfs();
}
