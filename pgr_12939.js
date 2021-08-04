/*
    최댓값과 최솟값
    https://programmers.co.kr/learn/courses/30/lessons/12939
*/
function solution(s)
{
    s=s.split(' ').map(v=>+v)
    return `${Math.min.apply(null,s)} ${Math.max.apply(null,s)}`
}