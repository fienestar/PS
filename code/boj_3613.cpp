/*
    Java vs C++
    https://www.acmicpc.net/problem/3613
*/
#include <bits/stdc++.h>

using namespace std;

//#define TC

#ifdef TC
#define assert3613(b) if(!(b)){ cout << "Error!"; return -1; }
#define TCS(x) x
#else
void assert3613(bool k)
{
    if(k)return;
    cout << "Error!";
    exit(0);
}
#define TCS(x)
#define TMain main
#endif


int TMain()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Code here!
    string in;
    if(!(cin >> in))
        return -2;

    vector<char> ans;
    int n = 0;
    size_t i;

/*
assert
    [0] 'a' <= input[0] <= 'z'
    [1] input[i] != '_' || input[i+1] != '_'
    [2] not(input endsWith '_')
    [3] input.includes(isupper) xor input.includes('_')
*/
    assert3613('a' <= in[0] && in[0] <= 'z'); // [0]

    for(i=0;in[i];++i){
        if(isupper(in[i])){
            assert3613(n!=2); // [3]
            n = 1;
            ans.push_back('_');
            ans.push_back(in[i]|32);
        }else if(in[i] == '_'){
            assert3613(n!=1); // [3]
            n = 2;
            ++i;
            assert3613(in[i]!='_'); // [1]
            assert3613(in[i]!='\0'); // [2]
            assert3613(in[i]&32); // [3]
            ans.push_back(in[i]&~32);
        }else
            ans.push_back(in[i]);
    }
    //assert3613(n!=0); // [3]
    copy(ans.begin(),ans.end(),ostream_iterator<char>{cout});
    return 0;
}

#ifdef TC
int main()
{
    while(TMain() != -2)cout << "\n";
}
#endif