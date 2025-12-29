#include <iostream>
#include <vector>
using namespace std;
static int count0 = 0;
static int count1 = 0;

void div(const vector<vector<int>>& v, int sr, int sc, int n) {
    int prev = v[sr][sc];
    for (int i = sr; i < sr + n; i++) {
        for (int j = sc; j < sc + n; j++) {
            if (v[i][j] == prev) continue;
            else {
                n /= 2;
                div(v, sr, sc, n);
                div(v, sr, sc + n, n);
                div(v, sr + n, sc, n);
                div(v, sr + n, sc + n, n);
                return;
            }
        }
    }
    if (prev == 0) count0++;
    else count1++;
    return;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<int>> v(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> v[i][j];
        }
    }
    div(v, 0, 0, N);

    cout << count0 << '\n' << count1;

    return 0;
}