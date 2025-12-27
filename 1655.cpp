#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {
    int N, count = 0;
    multiset<int> ms;
    cin >> N;
    while(N-- > 0) {
        int input, output;
        cin >> input;
        ms.insert(input);
        count++;
        if (count % 2 == 0) {
            auto x1 = next(ms.begin(), count / 2 - 1);
            auto x2 = next(ms.begin(), count / 2);
            output = min(*x1, *x2);
        }
        else {
            auto x1 = next(ms.begin(), ((count + 1) / 2) - 1);
            output = *x1;
        }
        cout << output << '\n';
    }
    return 0;
}