#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N, r, c,temp_r, temp_c, sum = 0;
    cin >> N >> r >> c;
    temp_r = r;
    temp_c = c;

    int pN = pow(2, N);
    
    while ((pN /= 2) != 0) {
        temp_r /= pN;
        temp_c /= pN;
        r %= pN;
        c %= pN;

        sum += pN * pN * (temp_r * 2 + temp_c);
        
        temp_r = r;
        temp_c = c;
    }

    cout << sum;
    return 0;
}