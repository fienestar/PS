/*
    별 찍기 - 1
    https://www.acmicpc.net/problem/2438
*/
#include <iostream>

using namespace std;

int main()
{
    size_t N;
    cin>>N;
    for(size_t i=0;i!=N;++i){
        for(size_t j=0;j!=i+1;++j)
            cout << "*";
        cout << "\n";
    }
}
