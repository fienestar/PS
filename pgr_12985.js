/*
    예상 대진표
    https://programmers.co.kr/learn/courses/30/lessons/12985
*/
function solution(n,a,b)
{
    return (Math.log2((a-1) ^ (b-1)) | 0) + 1
}