#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

static vector<vector<int>> vec;
void star(int i_num1, int i_num2, int j_num1, int j_num2) {
  int i_a = (i_num2 - i_num1) / 3 + i_num1,
      i_b = ((i_num2 - i_num1) / 3) * 2 + i_num1;
  int j_a = (j_num2 - j_num1) / 3 + j_num1,
      j_b = ((j_num2 - j_num1) / 3) * 2 + j_num1;

  for (int i = i_a; i < i_b; i++) {
    for (int j = j_a; j < j_b; j++) {
      vec[i][j] = 0;
    }
  }

  if (i_num2 - i_num1 == 3)
    return;

  star(i_num1, i_a, j_num1, j_a);
  star(i_a, i_b, j_num1, j_a);
  star(i_b, i_num2, j_num1, j_a);
  star(i_num1, i_a, j_a, j_b);
  star(i_b, i_num2, j_a, j_b);
  star(i_num1, i_a, j_b, j_num2);
  star(i_a, i_b, j_b, j_num2);
  star(i_b, i_num2, j_b, j_num2);

  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  vec.resize(N, vector<int>(N, 1));
  star(0, N, 0, N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (vec[i][j] == 1)
        cout << "*";
      else
        cout << " ";
    }
    cout << "\n";
  }
  return 0;
}