#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

static int N;
static vector<int> vec;

void Cantor(int num1, int num2) {
  if (num2 - num1 == 1)
    return;
  int a = ((num2 - num1) / 3) + num1, b = ((num2 - num1) / 3) * 2 + num1;
  for (int i = a; i < b; i++) {
    vec[i] = 0;
  }
  Cantor(num1, a);
  Cantor(b, num2);
  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  while (cin >> N) {
    int N_pow = (int)pow(3, N);
    vec.resize(N_pow, 1);
    Cantor(0, N_pow);

    for (auto x : vec) {
      if (x == 1)
        cout << "-";
      else
        cout << " ";
    }
    cout << "\n";
  }

  return 0;
}