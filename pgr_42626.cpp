/*
    더 맵게
    https://programmers.co.kr/learn/courses/30/lessons/42626
*/
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    for(auto& c:scoville) c = -c;
    priority_queue<int,vector<int>> pq(scoville.begin(), scoville.end());

    size_t time = 0;
    while(-pq.top() < K){
        if(pq.size() == 1)
            return -1;
        
        auto a = pq.top();
        pq.pop();
        auto b = pq.top();
        pq.pop();
        
        pq.push(b*2 + a);
        ++time;
    }
    
    return time;
}