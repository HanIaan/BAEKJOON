#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, x, freqValue, sum = 0, maxCount = 0, count = 0;
    multiset<int> ms_num;
    cin >> N;
    int freq[8001] = {0};

    while (N--) {
        cin >> x;
        ms_num.insert(x);
        sum += x;
        freq[x + 4000]++;
    }

    for (int i = 0; i < 8001; i++) {
        if (freq[i] > maxCount) 
            maxCount = freq[i];
    }
    for (int i = 0; i < 8001; i++) {
        if (freq[i] == maxCount) {
            freqValue = i - 4000;
            count++;
        }
        if (count == 2)
            break;
    }

    int max = *ms_num.rbegin(), min = *ms_num.begin();
    auto mid = next(ms_num.begin(), (ms_num.size() + 1) / 2 - 1);
    int size = ms_num.size();
    int avg = round((double)sum / size);
    
    cout << (avg == 0 ? 0 : avg) << "\n";
    cout << *mid << "\n";
    cout << freqValue << "\n";
    cout << max - min;

    return 0;
}