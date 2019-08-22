/**
 * AOAPC II Exercise 5-1 Alignment of Code
 * ICPC NEERC 2010
 * 13 AC
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> len(190, 0);
    vector<vector<string>> lines;
    string line;
    while (getline(cin, line))
    {
        lines.push_back(vector<string>());
        stringstream ss(line);
        string word;
        int i = 0;
        while (ss >> word)
        {
            lines.back().push_back(word);
            len[i] = max(len[i], (int) word.length());
            ++i;
        }
    }
    cout << left;
    for (auto &line : lines)
    {
        for (int i = 0; i < line.size() - 1; ++i)
            cout << setw(len[i] + 1) << line[i];
        cout << line.back() << "\n";
    }
}
