/**
 * AOAPC II Example 5-8 Unix ls
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n) {
        vector<string> names(n);
        int m = 0;
        for (string &s : names) {
            cin >> s;
            m = max(m, (int) s.length());
        }
        sort(names.begin(), names.end());
        int col = 62 / (m + 2), row = (n - 1) / col + 1;
        cout << string(60, '-') << "\n";
        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                int ind = r + c * row;
                if (ind < n) {
                    if (c)
                        cout << "  ";
                    cout << setw(m) << left << names[ind];
                }
                else
                    break;
            }
            cout << "\n";
        }
    }
}
