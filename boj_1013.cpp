/*
    Contact
    https://www.acmicpc.net/problem/1013
*/
#include <bits/stdc++.h>
using namespace std;main(){cmatch m;char i[999];cin>>i;while(cin>>i){cout<<4*regex_match(i,m,regex("(100+1+|01)+"))+"NO\n\0YES\n";}}