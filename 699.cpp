/**
 * AOAPC II Example 6-10 The Falling Leaves
 */
#include <bits/stdc++.h>
using namespace std;
vector<int> sums;
void build(int r)
{
    int v;
    cin >> v;
    if (v <= 0)
        return;
    sums[r] += v;
    build(r - 1);
    build(r + 1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1, v;
    while ((cin >> v) && v > 0)
    {
        sums = vector<int>(100, 0);
        sums[50] = v;
        build(49);
        build(51);
        int pos = 0;
        while (sums[pos] == 0)
            ++pos;
        cout << "Case " << T++ << ":\n"
            << sums[pos++];
        while (sums[pos] > 0)
            cout << " " << sums[pos++];
        cout << "\n\n";
    }
}
