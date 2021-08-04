/*
    최고의 집합
    https://programmers.co.kr/learn/courses/30/lessons/12938
*/
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    int mid = s/n;
    vector<int> answer(n, mid);
    
    if(mid == 0)
        return vector<int>(1,-1);

    fill(answer.end() - s + mid*n,answer.end(), mid+1);
    
    return answer;
}