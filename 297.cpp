/**
 * AOAPC II Example 6-11 Quadtrees
 */
#include <bits/stdc++.h>
using namespace std;
string tree;
int cnt;
auto img = vector<vector<bool>>(32, vector<bool>(32, false));
void draw(int &pos, int r, int c, int w)
{
    char cur = tree[pos++];
    if (cur == 'p')
    {
        draw(pos,         r, c + w / 2, w / 2);
        draw(pos,         r,         c, w / 2);
        draw(pos, r + w / 2,         c, w / 2);
        draw(pos, r + w / 2, c + w / 2, w / 2);
    }
    else if (cur == 'f')
        for (int i = r; i < r + w; ++i)
            for (int j = c; j < c + w; ++j)
                if (!img[i][j])
                {
                    img[i][j] = true;
                    ++cnt;
                }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int k = 0; k < T; ++k)
    {
        if (k)
            for (auto &line : img)
                fill(line.begin(), line.end(), false);
        cnt = 0;
        for (int i = 0; i < 2; ++i)
        {
            cin >> tree;
            int pos = 0;
            draw(pos, 0, 0, 32);
        }
        cout << "There are " << cnt << " black pixels.\n";
    }
}
