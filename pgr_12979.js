/*
    기지국 설치
    https://programmers.co.kr/learn/courses/30/lessons/12979
*/
function solution(n, stations, w) {
    let result = 0
    let need_begin = 1
    stations.push(n + w + 1)
    for(let i in stations){
        result += Math.ceil((stations[i] - w - need_begin)/(w*2+1))
        need_begin = stations[i] + w + 1
    }
    return result
}