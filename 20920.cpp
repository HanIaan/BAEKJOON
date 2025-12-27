#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  string word;
  map<string, int> wordMap;
  cin >> N >> M;

  while (N--) {
    cin >> word;
    if (word.size() >= M) { // 단어가 M보다 긴 문자만
      auto it = wordMap.find(word);
      if (it != wordMap.end()) { // 단어가 이미 존재하면 count++
        wordMap[word]++;
      } else
        wordMap.insert({word, 1}); // 존재 안하면 map에 추가
    }
  }
  vector<pair<string, int>> wordVec(wordMap.begin(),
                                    wordMap.end()); // map -> vector

  sort(wordVec.begin(), wordVec.end(), [](auto &a, auto &b) {
    if (a.second != b.second)
      return a.second > b.second; // 1순위 빈도
    if (a.first.size() != b.first.size())
      return a.first.size() > b.first.size(); // 2순위 길이
    return a.first < b.first;                 // 3순위 순서
  });

  for (auto &x : wordVec) {
    cout << x.first << "\n";
  }

  return 0;
}