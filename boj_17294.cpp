/*
    귀여운 수~ε٩(๑> ₃ <)۶з
    https://www.acmicpc.net/problem/17294
*/
#include <iostream>

using namespace std;

int main()
{
    char str[20];
    cin >> str;
    int d=str[0] - str[1];
    for(auto i=1;str[i];++i)
        if(str[i-1] - str[i] != d){
            cout << "흥칫뿡!! <(￣ ﹌ ￣)>";
            return 0;
        }
    cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
}