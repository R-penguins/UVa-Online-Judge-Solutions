/**
 * AOAPC II Exercise 5-2 Ducci Sequence
 * ICPC Seoul 2009
 * 21 WA
 * 24 AC
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        deque<int> nums(n);
        for (int &i : nums)
            cin >> i;
        bool zeros = false;
        for (int i = 0; i < 1005; ++i)
        {
            if (all_of(nums.begin(), nums.end(), [](int a){ return a == 0; }))
            {
                zeros = true;
                break;
            }
            int bk = nums.back();
            adjacent_difference(nums.begin(), nums.end(), nums.begin(), [](int a, int b)
            {
                return abs(a - b);
            });
            nums.push_back(abs(bk - nums.front()));
            nums.pop_front();
        }
        cout << (zeros ? "ZERO" : "LOOP") << "\n";
    }
}
