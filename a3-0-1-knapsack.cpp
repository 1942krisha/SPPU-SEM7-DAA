/*
Write a program to solve a 0-1 Knapsack problem using dynamic programming or branch and bound strategy.
*/

#include <bits/stdc++.h>
using namespace std;

int dynamic(int n, int mx, vector<int> p, vector<int> wt)
{
    vector<vector<int>> dp(n + 1, vector<int>(mx + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= mx; j++)
        {
            if (wt[i] <= j)
                dp[i][j] = max(dp[i - 1][j], p[i]+dp[i-1][j-wt[i]]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][mx];
}

int main()
{
    int n = 4;
    vector<int> p = {13, 14, 46, 23};
    vector<int> wt = {32, 12, 46, 32};
    int mx = 65;
    cout << dynamic(n, mx, p, wt);
    return 0;
}