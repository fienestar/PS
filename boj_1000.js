/*
    A+B
    https://www.acmicpc.net/problem/1000
*/
let input=require('fs').readFileSync('/dev/stdin').toString().split(' ').join('\n').split('\n')
let nextStr=()=>input.splice(0,1)[0]
let nextInt=()=>parseInt(nextStr())
console.log(nextInt()+nextInt())