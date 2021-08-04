/*
    PPAP
    https://www.acmicpc.net/problem/16120
*/
#include <bits/stdc++.h>

using namespace std;

void np()
{
    cout << "NP";
    exit(0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string ppap;

    cin >> ppap;

    stack<char> s;
    for(size_t i=0; i!=ppap.size(); ++i){
        if(ppap[i] == 'A'){
            if(s.size() < 2 || i+1 == ppap.size())
                np();
            for(size_t i=0; i!=2; ++i){
                char c = s.top();
                s.pop();
                if(c != 'P')
                    np();
            }
            if(ppap[i+1] != 'P')
                np();
        }else
            s.push(ppap[i]);
    }

    if(s.size() != 1)
        np();
    else
        cout << "PPAP";
}