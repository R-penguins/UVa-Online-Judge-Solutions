/**
 * AOAPC II Example 5-9 Database
 */
#include <bits/stdc++.h>
using namespace std;
int cnt, n, m, c1, c2, r1, r2;
vector<vector<int>> db;
map<string, int> IDs;
int id(string &s) {
    if (IDs.find(s) != IDs.end())
        return IDs[s];
    return IDs[s] = cnt++;
}
bool pnf() {
    for (c1 = 0; c1 < m; ++c1)
        for (c2 = c1 + 1; c2 < m; ++c2) {
            map<long long, int> checker;
            for (r2 = 0; r2 < n; ++r2) {
                long long num = db[r2][c1] * 1e5 + db[r2][c2];
                if (checker.find(num) != checker.end()) {
                    r1 = checker[num];
                    return false;
                }
                checker[num] = r2;
            }
        }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n >> m) {
        db = vector<vector<int>>(n);
        cnt = 0;
        IDs.clear();
        string cur;
        getline(cin, cur);
        for (auto &row : db)
            for (int c = 0; c < m; ++c) {
                (c == m - 1) ? getline(cin, cur) : getline(cin, cur, ',');
                row.push_back(id(cur));
            }
        if (pnf())
            cout << "YES\n";
        else
            cout << "NO\n" << r1 + 1 << " " << r2 + 1 << "\n" << c1 + 1 << " " << c2 + 1 << "\n";
    }
}
