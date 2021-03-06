/**
 * AOAPC II Example 6-14 Abbott's Revenge
 * ICPC WF 2000
 * Array based
 */
#include <bits/stdc++.h>
using namespace std;
struct Dir
{
    int r, c, dir;
    Dir(int r = 0, int c = 0, int dir = 0) : r(r), c(c), dir(dir) { }
};
Dir walk(Dir &ori, int turn)
{
    static const vector<int> dr { -1, 0, 1,  0 },
                             dc {  0, 1, 0, -1 };
    int dir = ori.dir;
    if (turn == 1)
        dir = (dir + 3) % 4;
    else if (turn == 2)
        dir = (dir + 1) % 4;
    return Dir(ori.r + dr[dir], ori.c + dc[dir], dir);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const string dirs = "NESW", turns = "FLR";
    string name;
    while ((cin >> name) && name != "END")
    {
        auto oks = vector<vector<vector<vector<bool>>>>(10, vector<vector<vector<bool>>>(10, vector<vector<bool>>(4, vector<bool>(3, false))));
        int entr_r, entr_c, goal_r, goal_c;
        char entr_dir_char;
        cin >> entr_r >> entr_c >> entr_dir_char >> goal_r >> goal_c;
        int pos_r, pos_c, entr_dir = dirs.find(entr_dir_char);
        while ((cin >> pos_r) && pos_r)
        {
            cin >> pos_c;
            string sign;
            while ((cin >> sign) && sign != "*")
            {
                auto &pos = oks[pos_r][pos_c][dirs.find(sign.front())];
                for (char c : sign.substr(1))
                    pos[turns.find(c)] = true;
            }
        }
        Dir beg_pos = Dir(entr_r, entr_c, entr_dir);
        Dir pos1 = walk(beg_pos, 0);
        auto p = vector<vector<vector<Dir>>>(10, vector<vector<Dir>>(10, vector<Dir>(4)));
        // p[pos1.r][pos1.c][pos1.dir] = beg_pos;
        auto vis = vector<vector<vector<bool>>>(10, vector<vector<bool>>(10, vector<bool>(4, false)));
        vis[pos1.r][pos1.c][pos1.dir] = true;
        queue<Dir> q;
        q.push(pos1);
        bool found = false;
        Dir fin;
        if (pos1.r == goal_r && pos1.c == goal_c)
        {
            found = true;
            fin = pos1;
        }
        while (!q.empty() && !found)
        {
            Dir cur = q.front();
            q.pop();
            auto &cur_pos = oks[cur.r][cur.c][cur.dir];
            for (int turn = 0; turn < 3; ++turn)
                if (cur_pos[turn])
                {
                    Dir res = walk(cur, turn);
                    if (1 <= res.r && res.r <= 9 && 1 <= res.c && res.c <= 9 && !vis[res.r][res.c][res.dir])
                    {
                        p[res.r][res.c][res.dir] = cur;
                        if (res.r == goal_r && res.c == goal_c)
                        {
                            fin = res;
                            found = true;
                            break;
                        }
                        vis[res.r][res.c][res.dir] = true;
                        q.push(res);
                    }
                }
        }
        cout << name;
        if (!found)
        {
            cout << "\n  No Solution Possible\n";
            continue;
        }
        vector<Dir> stk;
        while (true)
        {
            stk.push_back(fin);
            if (fin.r == pos1.r && fin.c == pos1.c && fin.dir == pos1.dir)
                break;
            fin = p[fin.r][fin.c][fin.dir];
        }
        stk.push_back(beg_pos);
        int cnt = 0;
        for (int i = stk.size() - 1; i >= 0; --i)
        {
            if (cnt++ % 10 == 0)
                cout << "\n ";
            cout << " (" << stk[i].r << "," << stk[i].c  << ")";
        }
        cout << "\n";
    }
}
