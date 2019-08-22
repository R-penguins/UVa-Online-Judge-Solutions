/**
 * AOAPC II Example 6-17 Under the Trees
 */
#include <bits/stdc++.h>
using namespace std;
vector<string> graph;
void draw(int r, int c)
{
    cout << graph[r][c] << "(";
    if (r + 1 < graph.size() && graph[r + 1][c] == '|')
    {
        int i = c;
        while (0 <= i - 1 && graph[r + 2][i - 1] == '-')
            --i;
        for (; i < graph[r + 3].size() && graph[r + 2][i] == '-'; ++i)
            if (graph[r + 3][i] != ' ')
                draw(r + 3, i);
    }
    cout << ")";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    string line;
    getline(cin, line);
    while (T--)
    {
        graph.clear();
        while (getline(cin, line) && line[0] != '#')
            graph.push_back(line);
        cout << "(";
        if (graph.size())
            draw(0, graph[0].find_first_not_of(' '));
        cout << ")\n";    
    }
}
