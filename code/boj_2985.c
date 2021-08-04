/*
    세 수
    https://www.acmicpc.net/problem/2985
*/
#define p(e,k)if(e)printf(k,a,b,c),exit(0);
#define s(d)p(a d b==c,"%d"#d"%d=%d")p(a==b d c,"%d=%d"#d"%d")
main(a,b,c){scanf("%d%d%d",&a,&b,&c);s(+)s(-)s(*)s(/)}