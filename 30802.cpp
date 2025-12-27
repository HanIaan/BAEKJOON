#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int N;
    vector<int> s = {0, 0, 0, 0, 0, 0};
    int T, P;
    int min_T, min_P, sum = 0;

    cin >> N;
    for (auto it = s.begin(); it != s.end(); ++it)
        cin >> *it;
    cin >> T >> P;

    for (auto it = s.begin(); it != s.end(); ++it)
        sum += (*it % T == 0) ? *it / T : *it / T + 1;

    cout << sum << endl;
    cout << N / P << " " << N % P;
    return 0;
}
