/**
 * AOAPC II Example 5-12 Urban Elevation
 */
#include <bits/stdc++.h>
using namespace std;
struct Building
{
    int id;
    double x1, y, x2, h;
    bool operator<(const Building &rhs) const
    {
        return x1 < rhs.x1 || (x1 == rhs.x1 && y < rhs.y);
    }
};
vector<Building> bulds;
vector<double> pts;
bool vis(Building &buld)
{
    for (double pt : pts)
        if (buld.x1 <= pt && pt <= buld.x2)
        {
            bool ok = true;
            for (Building &cur_buld : bulds)
                if (cur_buld.x1 <= pt && pt <= cur_buld.x2 && cur_buld.y < buld.y && cur_buld.h >= buld.h)
                {
                    ok = false;
                    break;
                }
            if (ok)
                return true;
        }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, kase = 0;
    while ((cin >> n) && n)
    {
        int cur_id = 1;
        bulds = vector<Building>(n);
        set<double> segs;
        for (Building &buld : bulds)
        {
            double dep, wid;
            cin >> buld.x1 >> buld.y >> wid >> dep >> buld.h;
            buld.id = cur_id++;
            buld.x2 = buld.x1 + wid;
            segs.insert(buld.x1);
            segs.insert(buld.x2);
        }
        sort(bulds.begin(), bulds.end());
        pts.clear();
        double l = 0;
        for (double d : segs)
        {
            pts.push_back((l + d) / 2);
            l = d;
        }
        if (kase++)
            cout << "\n";
        cout << "For map #" << kase << ", the visible buildings are numbered as follows:\n"
             << bulds.front().id;
        for_each(bulds.begin() + 1, bulds.end(), [](Building &buld){
            if (vis(buld))
                cout << " " << buld.id;
        });
        cout << "\n";
    }
}
