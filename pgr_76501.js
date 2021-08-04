/*
    음양 더하기
    https://programmers.co.kr/learn/courses/30/lessons/76501
*/
function solution(absolutes, signs) {
    return absolutes.map((v,i)=>signs[i]?v:-v).reduce((a,b)=>a+b)
}