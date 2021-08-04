/*
    삼각 달팽이
    https://programmers.co.kr/learn/courses/30/lessons/68645
*/
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer(n*(n+1)/2);
    
    auto at = [&](size_t x, size_t y)->int&{
        return (answer[x*(x+1)/2+y]);
    };

    size_t k = 0;
    int dx[] = {1,0,-1};
    int dy[] = {0,1,-1};
    
    int c = 1;
    size_t x = -1, y = 0;
    size_t end = n*(n+1)/2;
    while(c <= end){
        size_t my = y + dy[k];
        size_t mx = x + dx[k];
        if(mx >= n || my > mx || at(mx,my)){
            k = (k+1)%3;
            continue;
        }
        
        at(mx,my) = c++;
        x = mx;
        y = my;
    }
    
    return answer;
}