/**
 * AOAPC 3.7 DNA Consensus String
 * ICPC Seoul 2006
 * stats
 * 67 AC
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const map<char, int> pMap { {'A', 0}, {'C', 1}, {'G', 2}, {'T', 3} };
    const string nMap = "ACGT";
    int T;
    cin >> T;
    while (T--) {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> freq(n, vector<int>(4, 0));
        for (int i = 0; i < m; ++i) {
            string cur;
            cin >> cur;
            for (int c = 0; c < n; ++c)
                ++freq[c][pMap.at(cur[c])];
        }
        string ans = "";
        int ce = 0;
        for (auto i : freq) {
            auto pos = max_element(i.begin(), i.end());
            ans += nMap[pos - i.begin()];
            ce += m - *pos;
        }
        cout << ans << '\n';
        cout << ce << '\n';
    }
}