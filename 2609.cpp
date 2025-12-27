#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b, mx, mn;
    cin >> a >> b;

    for (int i = min(a, b); i > 0; i--) {
        if (a % i == 0 && b % i == 0) {
            mx = i;
            break;
        }
    }
    a /= mx;
    b /= mx;

    mn = mx;
    int i = 2;
    while (a != 1 || b != 1) {
        if (a % i == 0 && b % i == 0) {
            mn *= i;
            a /= i;
            b /= i;
            i--;
        } else if (a % i == 0) {
            mn *= i;
            a /= i;
            i--;
        } else if (b % i == 0) {
            mn *= i;
            b /= i;
            i--;
        }
        i++;
    }
    cout << mx << endl;
    cout << mn;
    return 0;
}