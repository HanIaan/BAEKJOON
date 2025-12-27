#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N, M, count = 0, zero_count = 0;
    queue<pair<int, int>> q;
    vector<vector<pair<int, int>>> v;

    cin >> M >> N;

    v.resize(N);     
    for (int i = 0; i < N; i++) {
        v[i].resize(M);
        for (int j = 0; j < M; j++) {
            cin >> v[i][j].first;
            v[i][j].second = 0;
            if (v[i][j].first == 0) zero_count++;
            else if (v[i][j].first == 1) q.push(make_pair(i, j));
        }
    }

    if (zero_count == 0) {
        cout << "0";
        return 0;
    }

    while(!q.empty()) {
        pair<int, int> idx = q.front();
        q.pop();
        int r = idx.first;
        int c = idx.second;
        if (r - 1 >= 0) {
            if (v[r - 1][c].first == 0) {
                v[r - 1][c].first = 1;
                v[r - 1][c].second = v[r][c].second + 1;
                q.push(make_pair(r - 1, c));
            }
        }
        if (r + 1 < N) {
            if (v[r + 1][c].first == 0) {
                v[r + 1][c].first = 1;
                v[r + 1][c].second = v[r][c].second + 1;
                q.push(make_pair(r + 1, c));
            }
        }
        if (c - 1 >= 0) {
            if (v[r][c - 1].first == 0) {
                v[r][c - 1].first = 1;
                v[r][c - 1].second = v[r][c].second + 1;
                q.push(make_pair(r, c - 1));
            }
        }
        if (c + 1 < M) {
            if (v[r][c + 1].first == 0) {
                v[r][c + 1].first = 1;
                v[r][c + 1].second = v[r][c].second + 1;
                q.push(make_pair(r, c + 1));
            }
        }
        count = v[r][c].second;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (v[i][j].first == 0) {
                cout << "-1";
                return 0;
            }
        }
    }

    cout << count;

    return 0;
}