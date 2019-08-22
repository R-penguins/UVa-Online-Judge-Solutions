/**
 * AOAPC II Example 6-8 Tree
 * Array based.
 */
#include <bits/stdc++.h>
using namespace std;
vector<int> in, post, L, R;
int sum, sum_pos;
int build(int in_beg, int in_end, int post_beg, int post_end)
{
    if (in_beg >= in_end)
        return 0;
    int root = post[post_end - 1];
    int pos = in_beg;
    while (in[pos] != root)
        ++pos;
    int left_size = pos - in_beg;
    L[root] = build(in_beg, pos, post_beg, post_beg + left_size);
    R[root] = build(pos + 1, in_end, post_beg + left_size, post_end - 1);
    return root;
}
bool read(vector<int> &tar)
{
    tar.clear();
    string line;
    if (!getline(cin, line))
        return false;
    stringstream ss(line);
    int i;
    while (ss >> i)
        tar.push_back(i);
    return tar.size();
}
void dfs(int u, int cur_sum)
{
    cur_sum += u;
    if (!L[u] && !R[u] && (cur_sum < sum || cur_sum == sum && u < sum_pos))
    {
        sum = cur_sum;
        sum_pos = u;
        return;
    }
    if (L[u])
        dfs(L[u], cur_sum);
    if (R[u])
        dfs(R[u], cur_sum);
}
int main()
{
    while (read(in))
    {
        read(post);
        L = vector<int>(10000 + 10, 0);
        R = vector<int>(10000 + 10, 0);
        int n = in.size(), root = build(0, n, 0, n);
        sum = numeric_limits<int>::max();
        dfs(root, 0);
        cout << sum_pos << "\n";
    }
}
