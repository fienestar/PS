/*
    프린터
    https://programmers.co.kr/learn/courses/30/lessons/42587
*/
function solution(priorities, location) {
    priorities = priorities.map((el,i)=>({value: el}))
    priorities[location].me = true
    let index = 0
    while(priorities.length){
        let front = priorities.shift()
        if(priorities.some(el=>el.value > front.value)){
            priorities.push(front)
            continue
        }
        
        ++index
        
        if(front.me)
            return index
    }
    return answer;
}