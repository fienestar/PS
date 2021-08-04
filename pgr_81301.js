/*
    숫자 문자열과 영단어
    https://programmers.co.kr/learn/courses/30/lessons/81301
*/
let number_table = {
    '0': /zero/g,
    '1': /one/g,
    '2': /two/g,
    '3': /three/g,
    '4': /four/g,
    '5': /five/g,
    '6': /six/g,
    '7': /seven/g,
    '8': /eight/g,
    '9': /nine/g
}

function solution(s) {
    for(let number in number_table)
        s = s.replace(number_table[number], number)
    return parseInt(s)
}