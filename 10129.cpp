/**
 * AOAPC II Example 6-16 Play on Words
 */
#include <bits/stdc++.h>
using namespace std;
vector<int> uf(26), sz(26);
int rt;
int root(int a)
{
    while (a != uf[a])
        a = uf[a] = uf[uf[a]];
    return a;
}
void uni(int a, int b)
{
    int ra = root(a), rb = root(b);
    if (ra != rb)
    {
        if (sz[ra] > sz[rb])
            swap(ra, rb);
        uf[ra] = rb;
        sz[rb] += sz[ra];
        rt = rb;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> o_degs(26, 0), i_degs(26, 0);
        iota(uf.begin(), uf.end(), 0);
        fill(sz.begin(), sz.end(), 1);
        while (n--)
        {
            string cur;
            cin >> cur;
            int from = cur.front() - 'a', to = cur.back() - 'a';
            ++o_degs[from];
            ++i_degs[to];
            uni(from, to);
        }
        int num = 0, n_beg = 0, n_end = 0;
        bool ok = true;
        for (int i = 0; i < 26; ++i)
            if (o_degs[i] || i_degs[i])
            {
                ++num;
                int diff = o_degs[i] - i_degs[i];
                if (diff == 1)
                    ++n_beg;
                else if (diff == -1)
                    ++n_end;
                else if (diff != 0)
                {
                    ok = false;
                    break;
                }
            }
        if (num == sz[rt] && ok && n_beg == n_end && (n_beg == 0 || n_beg == 1))
            cout << "Ordering is possible.\n";
        else
            cout << "The door cannot be opened.\n";
    }
}
