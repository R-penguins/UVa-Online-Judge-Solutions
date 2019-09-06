/**
 * Prime Ring Problem
 */
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> arr;
set<int> primes {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
vector<bool> vis;
void dfs(int cur)
{
    if (cur == n && primes.count(1 + arr.back()))
    {
        for (int i = 0; i < n - 1; ++i)
            cout << arr[i] << " ";
        cout << arr.back() << "\n";
    }
    else
        for (int i = 2; i <= n; ++i)
            if (!vis[i] && primes.count(i + arr[cur - 1]))
            {
                arr[cur] = i;
                vis[i] = true;
                dfs(cur + 1);
                vis[i] = false;
            }
}
int main()
{
    int T = 0;
    while (cin >> n)
    {
        if (T)
            cout << "\n";
        cout << "Case " << ++T << ":\n";
        arr = vector<int>(n);
        arr[0] = 1;
        vis = vector<bool>(n + 1, false);
        dfs(1);
    }
}
