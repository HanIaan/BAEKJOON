#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> v(N + 1);
    vector<long long> sum(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
        sum[i] = v[i] + sum[i - 1];
    }
    while(M-- > 0) {
        int start, end;
        cin >> start >> end;
    
        cout << sum[end] << " - " << sum[start - 1] << ": " << sum[end] - sum[start - 1] << endl;
    }
    return 0;
}
