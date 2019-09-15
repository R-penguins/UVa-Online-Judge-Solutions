/**
 * Krypton Factor
 */
#include <bits/stdc++.h>
using namespace std;
int n, L, cnt;
bool dfs(string ans)
{
    if (cnt++ == n)
    {
        for (int i = 0; i < ans.size(); ++i)
        {
            if (i && i % 64 == 0)
                cout << "\n";
            else if (i && i % 4 == 0)
                cout << " ";
            cout << ans[i];
        }
        cout << "\n"
             << ans.size() << "\n";
        return true;
    }
    ans.append(" ");
    for (char c = 'A'; c < 'A' + L; ++c)
    {
        ans.back() = c;
        bool ok = true;
        for (int len = 1; 2 * len <= ans.size(); ++len)
            if (equal(ans.end() - len, ans.end(), ans.end() - 2 * len))
            {
                ok = false;
                break;
            }
        if (ok && dfs(ans))
            return true;
    }
    return false;
}
int main()
{
    while ((cin >> n >> L) && n)
    {
        string ans = "";
        cnt = 0;
        dfs(ans);
    }
}
