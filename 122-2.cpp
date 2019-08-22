/**
 * AOAPC II Example 6-7 Trees on the Level
 * Array implementation of binary tree.
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string nd;
    while (cin >> nd)
    {
        bool error = false;
        int root = 1, cnt = 1;
        vector<int> left { 0, 0 }, right { 0, 0 }, val { 0, 0 };
        while (nd != "()")
        {
            auto sep = nd.find(',');
            int v = stoi(nd.substr(1, sep - 1));
            int u = root;
            for (char c : nd.substr(sep + 1))
                if (c == 'L')
                {
                    if (left[u] == 0)
                    {
                        left[u] = ++cnt;
                        left.push_back(0); right.push_back(0); val.push_back(0);
                    }
                    u = left[u];       
                }
                else if (c == 'R')
                {
                    if (right[u] == 0)
                    {
                        right[u] = ++cnt;
                        left.push_back(0); right.push_back(0); val.push_back(0);
                    }
                    u = right[u];
                }
            if (val[u])
                error = true;
            val[u] = v;
            cin >> nd;
        }
        if (error)
        {
            cout << "not complete\n";
            continue;
        }
        vector<int> ans;
        queue<int> q;
        q.push(root);
        while (!q.empty())
        {
            auto u = q.front();
            q.pop();
            if (val[u] == 0)
            {
                error = true;
                break;
            }
            ans.push_back(val[u]);
            if (left[u])
                q.push(left[u]);
            if (right[u])
                q.push(right[u]);
        }
        if (error)
            cout << "not complete\n";
        else
        {
            for (int i = 0; i < ans.size() - 1; ++i)
                cout << ans[i] << " ";
            cout << ans.back() << "\n";
        }
    }
}
