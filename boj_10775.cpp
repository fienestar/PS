/*
    공항
    https://www.acmicpc.net/problem/10775
*/
// 사용된 알고리즘: union-find
// R: X
// T: 0

// 답 보고 함..

// 집합 식별자를 해당 집합내의 엘리먼트에 도킹하려했을때
// 가장 좋은 도킹 장소로 정한다.
// 1,2,3중 하나에 도킹할 수 있을때 3에 도킹하는게 가장 좋음은 자명하므로 모든 집합은 기본적으로 자기자신을 식별자로 하고, 채워지고나면 그의 -1인곳에 도킹하는것이 낫다.

// 빈자리를 찾다가 결국 맨 첫번째 인덱스보다 앞으로 가려할경우, 빈자리가 없다.

// 교훈: 유니온 파인드를 할때는 식별자에 정보를 둘 수 있다.
// 교훈2: 그저 최상위임을 예약하는 방식의 경우 0 혹은 max + 1로 잡을 수 있다.
// ex) 최상위 노드가 5일때, 5에는 최상위 식별자 c를 넣어둔다. root[5] == c 이고 해당 집합의 모든 엘리먼트 k는 root[k] == 5이다.

#include <bits/stdc++.h>

using namespace std;

#ifndef LOCAL
#define LOCAL(x) ((void)0)
#endif
#define endl "\n"
#define elif else if
#define ifn(v) if(v);else
#define elifn(v) else ifn(v)

vector<size_t> uf;

size_t root(size_t X)
{
    if(uf[X]==X)
        return X;
    return uf[X]=root(uf[X]);
}

void merge(size_t A,size_t B)
{
    uf[root(A)]=root(B); // 어차피 항상 최솟값으로 흐른다.
}

int main()
{
    //LOCAL(OUTPUT_TO_FILE);
    LOCAL(INPUT_FROM_FILE);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Code here!
    size_t G,P,gi,cnt=0;
    cin>>G>>P;
    uf.resize(++G); // 1 ~ G

    while(--G)
        uf[G]=G;

    while(P--){
        cin>>gi;
        if(gi=root(gi)) // root(gi)가 도킹 위치
            merge(gi,gi-1); // 해당 집합의 도킹위치를 앞 집합의 도킹위치로 바꾼다.
        else // root 가 0이 됐음(도킹 자리 없음)
            break;
        ++cnt;
    }
    cout << cnt;
}