#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

static int globalCount = 0, globalTarget, K;

void count(int target) {
    globalCount++;
    if (globalCount == K) {
        globalTarget = target;
    }
}

void merge (vector<int> &A, int p, int q, int r) {
    int i = p, j = q + 1, t = 0;
    vector<int> temp(r - p + 1);
    while (i <= q && j <= r) {
        if (A[i] <= A[j]) {
            temp[t] = A[i++];
            count(temp[t++]);
        }
        else {
            temp[t] = A[j++];
            count(temp[t++]);
        }
    }
    while (i <= q) {
        temp[t] = A[i++];
        count(temp[t++]);
    }
    
    while (j <= r) {
        temp[t] = A[j++];
        count(temp[t++]);
    }
    
    i = p;
    t = 0;
    while (i <= r) 
        A[i++] = temp[t++];
}

void merge_sort(vector<int> &A, int p, int r) {
    if (p < r) {
        int mid = (p + r) / 2;
        int q = ((mid % 1) == 0) ? mid : (p + r + 1) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, n;
    cin >> N >> K;
    n = N;
    vector<int> A(N+1);
    int i = 0;
    while (N--) {
        cin >> A[i++];
    }

    merge_sort(A, 0, n - 1);
    
    if (globalCount < K) 
        cout << -1 << "\n";
    else
        cout << globalTarget << "\n";

    for(int j = 0; j < n; j++)
        cout << A[j] << " ";

    return 0;
}