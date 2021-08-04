/*
    땅따먹기
    https://programmers.co.kr/learn/courses/30/lessons/12913
*/
function solution(land) {
    land.unshift([0,0,0,0])
    
    for(let i=1; i!=land.length; ++i)
        for(let j in land[i]){
            let t = land[i-1][j]
            land[i-1][j] = 0
            land[i][j] += Math.max.apply(null, land[i-1])
            land[i-1][j] = t
        }

    return Math.max.apply(null, land.pop());
}