#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string line;
    while (cin >> line)
    {
        list<char> ans;
        bool back = true;
        auto pos = ans.begin();
        for (char c : line)
            if (c == '[')
            {
                back = false;
                pos = ans.begin();
            }
            else if (c == ']')
                back = true;
            else if (back)
                ans.push_back(c);
            else
                pos = ++ans.insert(pos, c);
        for (char c : ans)
            cout << c;
        cout << "\n";
    }
}
