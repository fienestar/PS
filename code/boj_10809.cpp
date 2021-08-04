/*
    알파벳 찾기
    https://www.acmicpc.net/problem/10809
*/
#include <iostream>

int main()
{
    char buf[101];
    char cnt[26]={};
    std::cin>>buf;
    for(size_t i=0;buf[i];++i)
        if(!cnt[buf[i]-'a'])
            cnt[buf[i]-'a']=i+1;
    for(size_t i=0;i<26;++i)
        std::cout<<cnt[i]-1 << " ";
}
