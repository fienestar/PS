/*
    실패율
    https://programmers.co.kr/learn/courses/30/lessons/42889
*/
function solution(N, stages) {
    let answer = [];
    let reached_level_count = [];

    for(let i=0; i<= N+1; ++i)
        reached_level_count.push(0)
    
    for(let stage of stages)
        ++reached_level_count[stage]

    for(let i = N; i >= 1; --i){
        let cleared = reached_level_count[i+1];
        let reached = reached_level_count[i] += cleared;
        answer.push({value: cleared/reached, index: i})
    }
    
    return answer.reverse().sort((a,b)=>a.value-b.value).map(v=>v.index)
}