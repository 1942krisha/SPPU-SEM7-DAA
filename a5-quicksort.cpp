/*
Write a program for  analysis of quicksort by using deterministic and randomized variant.
*/

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &v, int l, int h)
{
    int p = v[h];
    int i = l;
    for (int k = l; k < h; k++)
    {
        if(v[k] < p)
        {
            swap(v[i], v[k]);
            i++;
        }
    }
    swap(v[i], v[h]);
    return i;
}

int rpartition(vector<int> &v, int l, int h)
{
    int p = rand() % (h - l + 1) + l;
    swap(v[p], v[h]);
    partition(v, l, h);
}

void quicksort(vector<int> &v, int l, int h)
{
    if(l < h)
    {
        int p = partition(v, l, h);
        quicksort(v, l, p - 1);
        quicksort(v, p + 1, h);
    }
}

void rquicksort(vector<int> &v, int l, int h)
{
    if(l < h)
    {
        int p = rpartition(v, l, h);
        rquicksort(v, l, p - 1);
        rquicksort(v, p + 1, h);
    }
}

int main()
{
    vector<int> v = {4, 2, 3, 1, 6, 8, 7, 5};
    int n = v.size();
    quicksort(v, 0, n);
    for(int i:v)
    {
        cout << i << "  ";
    }
    return 0;
}