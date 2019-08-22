/**
 * AOAPC II Exercise 6-4 Knight Moves
 * 40 AC;
 */
#include <bits/stdc++.h>
using namespace std;
struct Pt
{
    int x, y;
    Pt(int x, int y) : x(x), y(y) { }
    bool operator==(const Pt &rhs)
    {
        return x == rhs.x && y == rhs.y;
    }
    Pt operator+(const Pt &rhs)
    {
        return Pt(x + rhs.x, y + rhs.y);
    }
    bool valid()
    {
        return 0 <= x && x <= 7 && 1 <= y && y <= 8;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const vector<Pt> DIRS {{ 1, 2}, { 2, -1}, { 2, 1}, { 1, -2},
                           {-1, 2}, {-2, -1}, {-2, 1}, {-1, -2}};
    string xx, yy;
    while (cin >> xx >> yy)
    {
        Pt from(xx[0] - 'a', xx[1] - '0'), to(yy[0] - 'a', yy[1] - '0');
        vector<Pt> q {from};
        int len = 0;
        bool found = from == to;
        while (!found)
        {
            ++len;
            vector<Pt> next;
            for (Pt &pt : q)
            {
                for (const Pt &dir : DIRS)
                {
                    Pt pos = pt + dir;
                    if (pos.valid())
                        if (pos == to)
                        {
                            found = true;
                            break;
                        }
                        else
                            next.push_back(pos);
                }
                if (found)
                    break;
            }
            q = next;
        }
        cout << "To get from " << xx << " to " << yy << " takes " << len << " knight moves.\n";
    }
}
