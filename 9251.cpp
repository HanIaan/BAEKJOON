#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int count = 0;
    int a_len = a.length(), b_len = b.length();
    vector<vector<int>> v(a_len + 1, vector<int> (b_len + 1, 0));

    for (int i = 1; i <= a_len; i++) {
        for (int j = 1; j <= b_len; j++) {
            if (a[i - 1] == b[j - 1]) 
                v[i][j] = v[i - 1][j - 1] + 1;
            else
                v[i][j] = max(v[i - 1][j], v[i][j - 1]);
        }
    }
    cout << v[a_len][b_len];
    return 0;
}