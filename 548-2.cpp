/**
 * AOAPC II Example 6-8 Tree
 * Smart pointer based.
 */
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int v = 0;
    shared_ptr<Node> left = nullptr, right = nullptr;
    Node(int v) : v(v) { }
};
vector<int> in, post;
int sum, sum_pos;
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
shared_ptr<Node> build(int in_beg, int in_end, int post_beg, int post_end, int cur_sum)
{
    if (in_beg >= in_end)
        return nullptr;
    auto u = make_shared<Node>(post[post_end - 1]);
    int pos = in_beg;
    while (in[pos] != u->v)
        ++pos;
    int left_size = pos - in_beg;
    cur_sum += u->v;
    u->left = build(in_beg, pos, post_beg, post_beg + left_size, cur_sum);
    u->right = build(pos + 1, in_end, post_beg + left_size, post_end - 1, cur_sum);
    if (!u->left && !u->right && (cur_sum < sum || cur_sum == sum && u->v < sum_pos))
    {
        sum = cur_sum;
        sum_pos = u->v;
    }
    return u;
}
int main()
{
    while (read(in))
    {
        read(post);
        sum = numeric_limits<int>::max();
        build(0, in.size(), 0, in.size(), 0);
        cout << sum_pos << "\n";
    }
}
