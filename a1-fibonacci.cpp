/*
Write a program non-recursive and recursive program to calculate Fibonacci numbers and analyze their time and space complexity.
*/

#include<bits/stdc++.h>
using namespace std;

int iter_fib(int n, int &cnt){
    int a = 0, b = 1, c;
    for(int i = 2; i < n; i++){
        c = a + b;
        a = b;
        b = c;
        cnt++;
    }
    return c;
}

int rec_fib(int n, int &cnt){
    if(n <= 1)
        return 0;
    if(n == 2) 
        return 1;
    return rec_fib(n - 1, ++cnt) + rec_fib(n - 2, ++cnt);
}

int main(){
    int n, cnt;
    n = 5;

    cnt = 0;
    cout << "Iterative: " << iter_fib(n, cnt);
    cout << "  Count: " << cnt;

    cnt = 0;
    cout << "\nRecursive: " << rec_fib(n, cnt);
    cout << "  Count: " << cnt;

    return 0;
}