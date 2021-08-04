/*
    문자열 반복
    https://www.acmicpc.net/problem/2675
*/
#include <iostream>

using namespace std;

void PutChars(char c,size_t n){
    while(n--)cout << c;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    char buf[21];
    size_t T,R;
    cin>>T;
    while(T--){
        cin>>R>>buf;
        for(size_t i=0;buf[i];++i)
            PutChars(buf[i],R);
        cout << "\n";
    }
}
