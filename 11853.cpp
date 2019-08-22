/**
 * AOAPC II Example 6-21 Paintball
 */
#include <bits/stdc++.h>
using namespace std;
struct Circle
{
    double x, y, r;
    bool vis = false;
    Circle(double x, double y, double r) : x(x), y(y), r(r) { }
};
vector<Circle> cs;
double start, finish;
bool dfs(Circle &cur)
{
    if (cur.vis)
        return false;
    cur.vis = true;
    if (cur.y - cur.r <= 0)
        return true;
    for (Circle &c : cs)
        if ((cur.x - c.x) * (cur.x - c.x) + (cur.y - c.y) * (cur.y - c.y) <= (cur.r + c.r) * (cur.r + c.r) && dfs(c))
            return true;
    if (cur.x - cur.r <= 0)
        start = min(start, cur.y - sqrt(cur.r * cur.r - cur.x * cur.x));
    if (cur.x + cur.r >= 1000)
        finish = min(finish, cur.y - sqrt(cur.r * cur.r - (1000 - cur.x) * (1000 - cur.x)));
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(2);
    int n;
    while (cin >> n)
    {
        cs.clear();
        start = finish = 1000;
        while (n--)
        {
            double x, y, r;
            cin >> x >> y >> r;
            cs.push_back(Circle(x, y, r));
        }
        bool connected = false;
        for (Circle &c : cs)
            if (c.y + c.r >= 1000 && dfs(c))
            {
                connected = true;
                break;
            }
        if (!connected)
            cout << "0.00 " << start << " 1000.00 " << finish << "\n";
        else
            cout << "IMPOSSIBLE\n";
    }
}
