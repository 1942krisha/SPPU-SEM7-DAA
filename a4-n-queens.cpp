/*
Design n-queens matrix having first Queen placed. Use backtracking to place remaining Queens to generate the final n-queen
*/

#include <bits/stdc++.h>
using namespace std;

class nqueen
{
    int n;
    vector<string> board;
    vector<vector<string>> ans;

public:
    nqueen(int x)
    {
        n = x;
        string s(x, '.');
        for (int i = 0; i < x; i++)
        {
            board.push_back(s);
        }
    }

    bool safe(int row, int col)
    {
        int r, c;
        //UD
        r = row;
        c = col;
        while(c>=0 && r>=0)
        {
            if(board[r][c] == 'Q')
                return false;
            r--;
            c--;
        }

        //LD
        r = row;
        c = col;
        while(c>=0 && r<n)
        {
            if(board[r][c] == 'Q')
                return false;
            r++;
            c--;
        }

        //HR
        r = row;
        c = col;
        while(c>=0)
        {
            if(board[r][c] == 'Q')
                return false;
            c--;
        }
        return true;
    }

    void solve(int col)
    {
        if(col >= board.size())
        {
            ans.push_back(board);
            return;
        }
        for (int r = 0; r < n; r++)
        {
            if(safe(r, col))
            {
                board[r][col] = 'Q';
                solve(col + 1);
                board[r][col] = '.';
            }
        }
    }

    void display()
    {
        for (auto i:ans)
        {
            for(auto j:i)
                cout << j << endl;
            cout <<endl;
        }
    }
};

int main()
{
    int n = 4;
    nqueen q(n);
    q.solve(0);
    q.display();
    return 0;
}