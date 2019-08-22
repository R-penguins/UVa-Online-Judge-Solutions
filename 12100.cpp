/**
 * AOAPC II Exercise 5-7 Printer Queue
 * 25 AC
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> jobs(n);
        vector<int> nums(10, 0);
        for (int &i : jobs)
        {
            cin >> i;
            ++nums[i];
        }
        int priority = 9, i = 0, t = 0;
        while (true)
        {
            while (nums[priority] == 0)
                --priority;
            if (jobs[i] == priority)
            {
                jobs[i] = 0;
                ++t;
                --nums[priority];
                if (i == m)
                    break;
            }
            i = (i + 1) % n;
        }
        cout << t << "\n";
    }
}
