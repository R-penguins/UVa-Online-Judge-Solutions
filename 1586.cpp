/**
 * AOAPC II 3-2 Molar Mass
 * I/O
 * 20+ AC
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    cout << fixed << setprecision(3);
    const map<char, double> m{ {'C', 12.01}, {'H', 1.008}, {'O', 16}, {'N', 14.01} };
    while (T--) {
        string s;
        cin >> s;
        double ans = 0, atom = 0;
        int cur = 0;
        bool one = false;
        for (char c : s) {
            if (isalpha(c)) {
                ans += one ? atom : atom * cur;
                atom = m.at(c);
                cur = 0;
                one = true;
            }
            else {
                cur = cur * 10 + c - '0'; //
                one = false;
            }
        }
        ans += one ? atom : atom * cur;
        cout << ans << '\n';
    }
}