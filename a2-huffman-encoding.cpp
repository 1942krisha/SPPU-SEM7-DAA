/*
Write a program to implement Huffman Encoding using a greedy strategy.
*/

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    char c;
    int f;
    node *l, *r;

    node(char ch, int fr)
    {
        c = ch;
        f = fr;
        l = NULL;
        r = NULL;
    }
};

class CompareNode
{
    public:
    bool operator()(node *l, node *r)
    {
        return l->f > r->f;
    }
};

class Huffman
{
    node *root;
    unordered_map<char, int> mp;
    priority_queue<node *, vector<node *>, CompareNode> pq;
    unordered_map<char, string> codes;
public:
    Huffman(string s)
    {
        for(char i:s)
        {
            mp[i]++;
        }
        for(auto i:mp)
        {
            node *n = new node(i.first, i.second);
            pq.push(n);
        }
    }

    node* genTree()
    {
        while(pq.size()>1)
        {
            node *left = pq.top();
            pq.pop();
            node *right = pq.top();
            pq.pop();
            node *n = new node('$', left->f + right->f);
            n->l = left;
            n->r = right;
            pq.push(n);
        }
        root = pq.top();
        return root;
    }

    void display(node *r)
    {
        if(r==NULL)
            return;
        cout << r->c << ":" << r->f << endl;
        display(r->l);
        display(r->r);
    }

    void genCode(node *rt, string code)
    {
        if(rt->c != '$')
            codes[rt->c] = code;
        if(rt->l != NULL)
            genCode(rt->l, code + "0");
        if(rt->r != NULL)
            genCode(rt->r, code + "1");
    }

    void displayCode()
    {
        cout << "CODES: " << endl;
        for(auto i:codes)
        {
            cout << i.first << ":" << i.second << endl;
        }
    }
};

int main()
{
    string s = "aabccccc";
    Huffman h(s);
    node *root = h.genTree();
    h.display(root);
    h.genCode(root, "");
    h.displayCode();
    return 0;
}