#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v(N), temp(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
        temp[i] = v[i];
    }
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    for (int i = 0; i < N; i++) {
        auto it = lower_bound(temp.begin(), temp.end(), v[i]);
        v[i] = it - temp.begin();
        cout << v[i];
        if (i != N -1) cout << " ";
    }
 
    return 0;
}
