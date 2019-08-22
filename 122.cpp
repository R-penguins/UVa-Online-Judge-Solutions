/**
 * AOAPC II Exmaple 6-7 Trees on Level
 * Smart pointer based implementation of binary tree.
 */
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int v = 0;
    shared_ptr<Node> left = nullptr, right = nullptr;
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string nd;
    while (cin >> nd)
    {
        bool error = false;
        auto root = make_shared<Node>();
        while (nd != "()")
        {
            auto sep = nd.find(',');
            int v = stoi(nd.substr(1, sep - 1));
            auto u(root);
            for (char c : nd.substr(sep + 1))
                if (c == 'L')
                {
                    if (u->left == nullptr)
                        u->left = make_shared<Node>();
                    u = u->left;       
                }
                else if (c == 'R')
                {
                    if (u->right == nullptr)
                        u->right = make_shared<Node>();
                    u = u->right;
                }
            if (u->v)
                error = true;
            u->v = v;
            cin >> nd;
        }
        if (error)
        {
            cout << "not complete\n";
            continue;
        }
        vector<int> ans;
        queue<shared_ptr<Node>> q;
        q.push(root);
        while (!q.empty())
        {
            auto u = q.front();
            q.pop();
            if (u->v == 0)
            {
                error = true;
                break;
            }
            ans.push_back(u->v);
            if (u->left)
                q.push(u->left);
            if (u->right)
                q.push(u->right);
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
