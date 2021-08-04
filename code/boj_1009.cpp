/*
    분산처리
    https://www.acmicpc.net/problem/1009
*/
#include <iostream>

#define MOD 10

int pow(int a,int b)
{
    if(!b)return 1;
    if(b&1)
        return (a * pow(a,b-1)) % MOD;
    else{
        int rslt = pow(a,b>>1);
        return (rslt * rslt) % MOD;
    }
}

int main()
{
    using namespace std;
    size_t N,a,b;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    while(N--){
        cin >> a >> b;
        int rslt = pow(a,b);
        if(rslt)cout << rslt << "\n";
        else cout << 10 << "\n";
    }

}
