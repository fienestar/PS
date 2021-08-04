/*
    맥주 99병
    https://www.acmicpc.net/problem/17293
*/
#include <iostream>

using namespace std;

int main()
{
    size_t n,m;
    cin >> n;
    m = n;
    if(n==1){
        cout << R"(1 bottle of beer on the wall, 1 bottle of beer.
Take one down and pass it around, no more bottles of beer on the wall.

No more bottles of beer on the wall, no more bottles of beer.
Go to the store and buy some more, 1 bottle of beer on the wall.)";
        return 0;
    }
    for(;n!=2;--n)
        cout << n << R"( bottles of beer on the wall, )" << n << R"( bottles of beer.
Take one down and pass it around, )" << n-1 << R"( bottles of beer on the wall.

)";
    cout << R"(2 bottles of beer on the wall, 2 bottles of beer.
Take one down and pass it around, 1 bottle of beer on the wall.

1 bottle of beer on the wall, 1 bottle of beer.
Take one down and pass it around, no more bottles of beer on the wall.

No more bottles of beer on the wall, no more bottles of beer.
Go to the store and buy some more, )" << m << R"( bottles of beer on the wall.)";
}