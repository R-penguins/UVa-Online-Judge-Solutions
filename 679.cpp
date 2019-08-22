/**
 * AOAPC II Example 6-6 Dropping Balls
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int D, I;
        cin >> D >> I;
        int b = 1;
        for (int i = 0; i < D - 1; ++i)
            if (I % 2)
            {
                b *= 2;
                I = (I + 1) / 2;
            }
            else
            {
                b = b * 2 + 1;
                I /= 2;
            }
        cout << b << "\n";
    }
}
