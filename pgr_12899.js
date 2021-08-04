/*
    124 나라의 숫자
    https://programmers.co.kr/learn/courses/30/lessons/12899
*/
function solution(n)
{
    n = n.toString(3).split('')
    
    for(let i = n.length; --i; ){
        n[i] = +n[i]
        if(n[i] <= 0){
            let need = Math.ceil((1-n[i])/3)
            n[i-1] -= need
            n[i] += need*3
        }
    }
    
    return n.map(v=>" 124"[v]).join('').trim()
}