#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
long long tr_sum(const vector<int>& tree, int h) {
    long long sum = 0;
    for (auto it = tree.rbegin() ; it != tree.rend(); ++it) {
        if (h >= *it) break;
        sum += (long long)(*it - h);
    }
    return sum;
}

int main() {
    ios:: sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int H;
    cin >> N >> H;
    vector<int> tree(N);
    
    for (int i = 0; i < N; i++) 
        cin >> tree[i];

    sort(tree.begin(), tree.end());
    
    int a = 0, b = tree[N - 1], mid = 0;
    long long sum = 0;
    while (a != b) {
        if (mid == (a + b) / 2) {
            if (sum > H) b = mid;
            else a = mid;
        }
        mid = (a + b) / 2;
        sum = tr_sum(tree, mid);
        if (sum > H) a = mid;
        else if (sum < H) b = mid;
        else break;
    }
    cout << mid;
    return 0;
}
