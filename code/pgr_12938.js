/*
    최고의 집합
    https://programmers.co.kr/learn/courses/30/lessons/12938
*/
function solution(n, s) {
    let mid = (s / n) | 0
    let answer = "*".repeat(n).split('').map(v=>mid)

    if(mid == 0)
        return [-1]

    let i = n
    while(mid*n < s){
        ++answer[--i]
        --s
    }

    return answer;
}