/**
 * AOAPC II Example 6-13 Ancient Messages
 * ICPC WF 2011
 */
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> pic;
const vector<int> dr { -1, 0, 1,  0 },
                  dc {  0, 1, 0, -1 };
int H, W;                  
void paint(int i, int j, int color)
{
    int ori = pic[i][j];
    pic[i][j] = color;
    for (int x = 0; x < 4; ++x)
    {
        int r = i + dr[x], c = j + dc[x];
        if (0 <= r && r <= H + 1 && 0 <= c && c <= W + 1 && pic[r][c] == ori)
            paint(r, c, color);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const vector<vector<int>> conv
    {
        {0, 0, 0, 0},
        {0, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 0, 1, 1},
        {0, 1, 0, 0},
        {0, 1, 0, 1},
        {0, 1, 1, 0},
        {0, 1, 1, 1},
        {1, 0, 0, 0},
        {1, 0, 0, 1},
        {1, 0, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 1, 0},
        {1, 1, 1, 1}
    };
    const string rec = "WAKJSD";
    int K = 1;
    while ((cin >> H >> W) && H && W)
    {
        W *= 4;
        pic = vector<vector<int>>(H + 2);
        pic.front() = pic.back() = vector<int>(W + 2, 0);
        for (int row = 1; row <= H; ++row)
        {
            auto &line = pic[row];
            line.reserve(W + 2);
            line.push_back(0);
            string cur;
            cin >> cur;
            for (char c : cur)
            {
                int id = isdigit(c) ? c - '0' : c - 'a' + 10;
                copy(conv[id].begin(), conv[id].end(), back_inserter(line));
            }
            line.push_back(0);
        }
        paint(0, 0, -1); // background color -1
        int char_color = 2, space_color = -2;
        for (int i = 1; i <= H; ++i)
            for (int j = 1; j <= W; ++j)
                if (pic[i][j] == 1)
                    paint(i, j, char_color++);
                else if (pic[i][j] == 0)
                    paint(i, j, space_color--);
        vector<set<int>> colors(char_color);
        for (int i = 1; i <= H; ++i)
            for (int j = 1; j <= W; ++j)
                if (pic[i][j] >= 2)
                    for (int x = 0; x < 4; ++x)
                    {
                        int r = i + dr[x], c = j + dc[x];
                        if (r >= 1 && r <= H && c >= 1 && c <= W && pic[r][c] < -1)
                            colors[pic[i][j]].insert(pic[r][c]);
                    }
        string ans = "";                    
        for (int i = 2; i < char_color; ++i)
            ans += rec[colors[i].size()];
        sort(ans.begin(), ans.end());
        cout << "Case " << K++ << ": " << ans << "\n";
    }
}
