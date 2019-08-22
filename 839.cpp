#include <bits/stdc++.h>
using namespace std;
bool balance(int &w)
{
    int wl, dl, wr, dr;
    cin >> wl >> dl >> wr >> dr;
    bool bl = true, br = true;
    if (!wl)
        bl = balance(wl);
    if (!wr)
        br = balance(wr);
    w = wl + wr;
    return bl && br && wl * dl == wr * dr;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, w;
    cin >> T;
    while (T--)
    {
        cout << (balance(w) ? "YES" : "NO") << "\n";
        if (T)
            cout << "\n";
    }
}
