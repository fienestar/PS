/*
    단어 정렬
    https://www.acmicpc.net/problem/1181
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    size_t N;
    cin >> N;

    set<string> s;
    vector<string> v;
    string S;
    while(N--){
        cin >> S;
        if(s.find(S) == s.end()){
            v.push_back(S);
            s.insert(S);
        }
    }

    sort(v.begin(),v.end(),[](string a,string b){
        if(a.size() != b.size())
            return a.size() < b.size();
        return a < b;
    });

    for(auto& e:v)
        cout << e << "\n";
}