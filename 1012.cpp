#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0) {
        int N, M, K, count = 0;
        cin >> M >> N >> K;
        vector<vector<int>> v(N, vector<int>(M, 0));
        vector<pair<int, int>> v1;
        queue<pair<int, int>> q;
        int pr[4] = {-1, 1, 0, 0};
        int pc[4] = {0, 0, -1, 1};
        for (int i = 0; i < K; i++) {
            int r, c;
            cin >> c >> r;
            v[r][c] = 1;
            v1.push_back(make_pair(r, c));
        }
        for (auto it: v1) {
            auto [i, j] = it;
            if (v[i][j] == 1) {
                q.push(make_pair(i, j));
                v[i][j] = 0;
            }
            else continue;
            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int nr = r + pr[k];
                    int nc = c + pc[k];
                    if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
                    if (v[nr][nc] == 1) {
                        q.push(make_pair(nr, nc));
                        v[nr][nc] = 0;
                    }
                }
            }
            count++;
            
        }
        cout << count << '\n';
    }
    return 0;
}