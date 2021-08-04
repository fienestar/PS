/*
    벌집
    https://www.acmicpc.net/problem/2292
*/
#include <iostream>

using namespace std;

int main()
{
    int n,i=0,t=0;
    cin>>n;
    --n;
    for(;;){
        if(n<=t)break;
        t+=(i+=6);
    }
    cout << i/6+1;
}
