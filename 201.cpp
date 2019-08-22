/**
 * AOAPC II Exercise 4-2 Squares
 * 55 AC
 * Use Union-Find to store horizontal and vertical connectivity, 
 * query every dot as the upper-left corner of the square.
 * O(n^3) for the query part
 */
#include <bits/stdc++.h>
using namespace std;
int num(int n, int r, int c) {
    return (r - 1) * n + c;
}
int root(vector<int> &par, int a) {
    while (par[a] != a)
        a = par[par[a]];
    return a;
}
void uni(vector<int> &par, int a, int b) {
    int rb = root(par, b);
    if (root(par, a) != rb)
        par[rb] = a;
}
bool con(vector<int> &par, int a, int b) {
    return root(par, a) == root(par, b);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, pn = 0;
    while (cin >> n >> m) {
        vector<int> parH(n * n + 1), parV(n * n + 1);
        iota(parH.begin(), parH.end(), 0);
        iota(parV.begin(), parV.end(), 0);
        while (m--) {
            char ori;
            int i, j;
            cin >> ori >> i >> j;
            if (ori == 'H')
                uni(parH, num(n, i, j), num(n, i, j + 1));
            else
                uni(parV, num(n, j, i), num(n, j + 1, i));    
        }
        vector<int> sz(n + 1, 0);
        for (int r = 1; r <= n; ++r)
            for (int c = 1; c <= n; ++c)
                for (int s = 1; s + r <= n; ++s)
                    if (con(parH, num(n, r, c), num(n, r, c + s)) &&
                        con(parV, num(n, r, c), num(n, r + s, c)) &&
                        con(parV, num(n, r, c + s), num(n, r + s, c + s)) &&
                        con(parH, num(n, r + s, c), num(n, r + s, c + s)))
                        ++sz[s];
        if (pn)
            cout << "\n**********************************\n\n";
        cout << "Problem #" << ++pn << "\n\n";
        bool no = true;
        for (int size = 1; size <= n; ++size)
            if (sz[size]) {
                cout << sz[size] << " square (s) of size " << size << "\n";
                no = false;
            }
        if (no)
            cout << "No completed squares can be found.\n";
    }
}
