/**
 * AOAPC II 3-3 Digit Counting
 * Table lookup
 * 10 AC
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const int maxN = 10005;
    vector<vector<int>> t(maxN, vector<int>(maxN));
    for (int i = 1; i < maxN; ++i) {
        copy(t[i - 1].begin(), t[i - 1].end(), t[i].begin());
        int x = i;
        while (x > 0) {
            ++t[i][ x % 10 ];
            x /= 10;
        }
    }
    int N;
    cin >> N;
    while (N--) {
        int d;
        cin >> d;
        cout << t[d][0];
        for (int i = 1; i < 10; ++i)
            cout << " " << t[d][i];
        cout << '\n';
    }
}