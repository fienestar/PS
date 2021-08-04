/*
    시험 성적
    https://www.acmicpc.net/problem/9498
*/
#include <iostream>

int main()
{
    using namespace std;
    int c;
    cin>>c;
    if(c<60)cout<<"F";
    else if(c==100)cout << "A";
    else cout << char('A'+9-c/10);
}
