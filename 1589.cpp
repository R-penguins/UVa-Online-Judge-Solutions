/**
 * AOAPC II Exercise 4-1 Xiangqi
 * 87 WA
 * 97 WA
 * 107 AC
 */
#include <bits/stdc++.h>
using namespace std;
struct Pos {
    int x, y;
    Pos(int x, int y) : x(x), y(y) {}
};
void mark(vector<string> board, Pos &p, vector<vector<bool>> &mark) {
    switch (board[p.x][p.y]) {
        case 'G':
            for (int r = p.x - 1; r >= 1; --r) {
                if (r <= 3)
                    mark[r][p.y] = false;
                if (board[r][p.y] != ' ')
                    break;
            }
            break;
        case 'R':
            for (int r = p.x - 1; r >= 1; --r) {
                mark[r][p.y] = false;
                if (board[r][p.y] != ' ')
                    break;
            }
            for (int r = p.x + 1; r <= 10; ++r) {
                mark[r][p.y] = false;
                if (board[r][p.y] != ' ')
                    break;
            }
            for (int c = p.y - 1; c >= 1; --c) {
                mark[p.x][c] = false;
                if (board[p.x][c] != ' ')
                    break;
            }
            for (int c = p.y + 1; c <= 9; ++c) {
                mark[p.x][c] = false;
                if (board[p.x][c] != ' ')
                    break;
            }
            break;
        case 'H':
            if (p.x - 2 >= 1 && board[p.x - 1][p.y] == ' ') {
                if (p.y - 1 >= 1)
                    mark[p.x - 2][p.y - 1] = false;
                if (p.y + 1 <= 9)
                    mark[p.x - 2][p.y + 1] = false;
            }
            if (p.x + 2 <= 10 && board[p.x + 1][p.y] == ' ') {
                if (p.y - 1 >= 1)
                    mark[p.x + 2][p.y - 1] = false;
                if (p.y + 1 <= 9)
                    mark[p.x + 2][p.y + 1] = false;
            }
            if (p.y - 2 >= 1 && board[p.x][p.y - 1] == ' ') {
                if (p.x - 1 >= 1)
                    mark[p.x - 1][p.y - 2] = false;
                if (p.x + 1 <= 10)
                    mark[p.x + 1][p.y - 2] = false;
            }
            if (p.y + 2 <= 9 && board[p.x][p.y + 1] == ' ') {
                if (p.x - 1 >= 1)
                    mark[p.x - 1][p.y + 2] = false;
                if (p.x + 1 <= 10)
                    mark[p.x + 1][p.y + 2] = false;
            }
        case 'C':
            bool start = false;
            for (int r = p.x - 1; r >= 1; --r)
                if (board[r][p.y] != ' ')
                    if (!start)
                        start = true;
                    else {
                        mark[r][p.y] = false;
                        break;
                    }
                else if (start)
                    mark[r][p.y] = false;
            start = false;
            for (int r = p.x + 1; r <= 10; ++r)
                if (board[r][p.y] != ' ')
                    if (!start)
                        start = true;
                    else {
                        mark[r][p.y] = false;
                        break;
                    }
                else if (start)
                    mark[r][p.y] = false;
            start = false;
            for (int c = p.y - 1; c >= 1; --c)
                if (board[p.x][c] != ' ')
                    if (!start)
                        start = true;
                    else {
                        mark[p.x][c] = false;
                        break;
                    }
                else if (start)
                    mark[p.x][c] = false;
            start = false;
            for (int c = p.y + 1; c <= 9; ++c)
                if (board[p.x][c] != ' ')
                    if (!start)
                        start = true;
                    else {
                        mark[p.x][c] = false;
                        break;
                    }
                else if (start)
                    mark[p.x][c] = false;
            break;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, gx, gy;
    while ((cin >> n >> gx >> gy) && n) {
        vector<string> board(11, string(10, ' '));
        vector<Pos> pieces;
        vector<vector<bool>> oks(11, vector<bool>(10, true));
        char cc;
        int cx, cy;
        while (n--) {
            cin >> cc >> cx >> cy;
            board[cx][cy] = cc;
            pieces.push_back(Pos(cx, cy));
        }
        for (Pos p : pieces)
            mark(board, p, oks);
        bool check = false;
        for (int r = gx; r <= 10; ++r)
            if (board[r][gy] == 'G') {
                check = true;
                break;
            }
            else if (board[r][gy] != ' ')
                break;
        if (check) {
            cout << "NO\n";
            continue;
        }
        if (gx - 1 >= 1 && oks[gx - 1][gy]) {
            cout << "NO\n";
            continue;
        }
        if (gy + 1 <= 6 && oks[gx][gy + 1]) {
            cout << "NO\n";
            continue;
        }
        if (gx + 1 <= 3 && oks[gx + 1][gy]) {
            cout << "NO\n";
            continue;
        }
        if ((gy - 1) >= 4 && oks[gx][gy - 1]) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
}
