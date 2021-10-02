#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0);
int N, M,D,S, arr[51][51] = { 0 };
bool beforeCloud[51][51] = { 0 };
int d[9][2] = { {0,0},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1} };
queue<pair<int,int>> c, m;
void moveAndRain() {
    memset(beforeCloud, 0, sizeof(beforeCloud));
    while (!c.empty()) {
        int x = c.front().first;
        int y = c.front().second;
        c.pop();
        int nx = x + d[D][0] * S;
        int ny = y + d[D][1] * S;
        while (nx > N) nx -= N;
        while (nx < 1) nx += N;
        while (ny> N) ny -= N;
        while (ny < 1) ny += N;
        arr[nx][ny]++;
        beforeCloud[nx][ny] = 1;
        m.push({ nx,ny });
    }
}
void magic() {
    while (!m.empty()) {
        int x = m.front().first;
        int y = m.front().second;
        m.pop();
        for (int i = 1; i <= 4; i++) {
            int nx = x + d[i * 2][0];
            int ny = y + d[i * 2][1];
            if (nx<1 || nx>N || ny<1 || ny>N) continue;
            if (arr[nx][ny]) arr[x][y]++;
        }
    }
}
void cloud() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (arr[i][j] >= 2 && !beforeCloud[i][j]) {
                arr[i][j] -= 2;
                c.push({ i,j });
            }
        }
    }
}
int main() {
    FASTIO;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }
    c.push({ N, 1 });
    c.push({ N, 2 });
    c.push({ N - 1, 1 });
    c.push({ N - 1, 2 });
    for (int i = 0; i < M; i++) {
        cin >> D >> S;
        moveAndRain();
        magic();
        cloud();
    }
    int res = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            res += arr[i][j];
        }
    }
    cout << res;
    return 0;
}