/*
    N과 M (1)
    https://www.acmicpc.net/problem/15649
*/
#include <iostream>
#include <cstdint>
#include <vector>

static size_t N,M;
static std::vector<size_t> v,visited;

void make(size_t idx)
{
    if(idx == M){
	for(auto& i:v)printf("%d ",i+1);
	puts("");
	return;
    }
    for(size_t i=0;i!=N;++i){
	if(!visited[i]){
	     visited[i]=1;
	     v[idx] = i;
	     make(idx+1);
	     visited[i]=0;
	}
    }
}

int main()
{
    using namespace std;
    cin>>N>>M;
    v.resize(M);
    visited.resize(N);
    make(0);
}