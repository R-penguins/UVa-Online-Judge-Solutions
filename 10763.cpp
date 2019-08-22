/**
 * AOAPC II Exercise 5-4 Foreign Exchange
 * 11 WA 20 AC // use multiset
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while ((cin >> n) && n)
    {
        multiset<pair<int, int>> tar_ori;
        while(n--)
        {
            int ori, tar;
            cin >> ori >> tar;
            multiset<pair<int, int>>::iterator iter;
            if ((iter = tar_ori.find({tar, ori})) != tar_ori.end())
                tar_ori.erase(iter);
            else
                tar_ori.insert({ori, tar});
        }
        cout << (tar_ori.empty() ? "YES" : "NO") << "\n";
    }
}
