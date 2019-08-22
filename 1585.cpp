/**
 * AOAPC II 3-1
 * I/O
 * 3:17 AC
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int score = 0, cur = 0;
        for (char c : s)
            (c == 'O') ? score += ++cur : cur = 0;
        cout << score << '\n';
    }
}