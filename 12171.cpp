/**
 * AOAPC II Example 6-18 Sculpture
 * ICPC NWERC 2008
 */
#include <bits/stdc++.h>
using namespace std;
struct Cell
{
    int x, y, z;
    Cell(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) { }
};
void elim(vector<int> &vec)
{
    vec.push_back(0);
    vec.push_back(1100);
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
}
int main()
{                                                    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);                                //     4 0
    int T;                                           //     |/
    cin >> T;                                        // 3 -- --> 1
    const array<int, 8> dx {  0, 1, 0, -1,  0, 0 },  //    /|
                        dy {  0, 0, 0,  0, -1, 1 },  //   L v
                        dz { -1, 0, 1,  0,  0, 0 };  //  2  5
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> xs, ys, zs, x0s(n), x1s(n), y0s(n), y1s(n), z0s(n), z1s(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> x0s[i] >> y0s[i] >> z0s[i] >> x1s[i] >> y1s[i] >> z1s[i];
            x1s[i] += x0s[i];
            y1s[i] += y0s[i];
            z1s[i] += z0s[i];
            xs.push_back(x0s[i]);
            xs.push_back(x1s[i]);
            ys.push_back(y0s[i]);
            ys.push_back(y1s[i]);
            zs.push_back(z0s[i]);
            zs.push_back(z1s[i]);
        }
        elim(xs);
        elim(ys);
        elim(zs);
        int nx = xs.size(), ny = ys.size(), nz = zs.size();
        auto boxes = vector<vector<vector<bool>>>(nx, vector<vector<bool>>(ny, vector<bool>(nz, false)));
        auto vis = vector<vector<vector<bool>>>(nx, vector<vector<bool>>(ny, vector<bool>(nz, false)));
        for (int i = 0; i < n; ++i)
        {
            int x0_pos = lower_bound(xs.begin(), xs.end(), x0s[i]) - xs.begin(),
                x1_pos = lower_bound(xs.begin(), xs.end(), x1s[i]) - xs.begin(),
                y0_pos = lower_bound(ys.begin(), ys.end(), y0s[i]) - ys.begin(),
                y1_pos = lower_bound(ys.begin(), ys.end(), y1s[i]) - ys.begin(),
                z0_pos = lower_bound(zs.begin(), zs.end(), z0s[i]) - zs.begin(),
                z1_pos = lower_bound(zs.begin(), zs.end(), z1s[i]) - zs.begin();
            for (int x = x0_pos; x < x1_pos; ++x)
                for (int y = y0_pos; y < y1_pos; ++y)
                    for (int z = z0_pos; z < z1_pos; ++z)
                        boxes[x][y][z] = true;
        }
        int volume = 1100 * 1100 * 1100, area = 0;
        queue<Cell> q;
        q.push(Cell());
        vis[0][0][0] = true;
        while (!q.empty())
        {
            Cell cur = q.front();
            q.pop();
            int lx = (xs[cur.x + 1] - xs[cur.x]), ly = (ys[cur.y + 1] - ys[cur.y]), lz = (zs[cur.z + 1] - zs[cur.z]);
            volume -= lx * ly * lz;
            for (int i = 0; i < 6; ++i)
            {
                Cell next(cur.x + dx[i], cur.y + dy[i], cur.z + dz[i]);
                if (0 <= next.x && next.x < nx - 1 && 0 <= next.y && next.y < ny - 1 && 0 <= next.z && next.z < nz - 1)
                    if (boxes[next.x][next.y][next.z])
                        if (dx[i])
                            area += ly * lz;
                        else if (dy[i])
                            area += lx * lz;
                        else
                            area += lx * ly;
                    else if (!vis[next.x][next.y][next.z])
                    {
                        q.push(next);
                        vis[next.x][next.y][next.z] = true;
                    }
            }
        }
        cout << area << " " << volume << "\n";
    }
}
