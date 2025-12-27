#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool prime (int m) {
    int count = 0;
    
    for (int i = 1; i <= m; i++){
        if (m % i == 0) count++;
    }
    if (count == 2) return true;
    else return false;
}

int main() {
    int N;
    int num, count = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num;
        if (prime(num)) count++;
    }
    
    cout << count << endl;

    return 0;
}
