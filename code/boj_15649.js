/*
    N과 M (1)
    https://www.acmicpc.net/problem/15649
*/
let input=require('fs').readFileSync('/dev/stdin').toString().split(' ').join('\n').split('\n')
let nextStr=()=>input.splice(0,1)[0]
let nextInt=()=>parseInt(nextStr())
let print=(str)=>console.log(str)
let N=nextInt()
let M=nextInt()
let Stack=[]
let V=[]
let Visited={}
Stack.unshift({idx:0,i:0}) // 더미
Stack.unshift({idx:0,i:0})
let releaseStack = ()=>{
    Stack.shift()
    Visited[Stack[0].i]=false // 더미가 있어서 체크 안해도됨
    ++Stack[0].i
}

while(Stack.length != 1) // 더미 개수
{
    with(Stack[0]){
        if(idx==M){
            print(V.join(" "))
            releaseStack()
            continue
        }

        if(i==N){
            releaseStack()
            continue
        }
    
        if(Visited[i]){
            ++i
            continue
        }

        Visited[i]=true
        V[idx]=i+1
        Stack.unshift({idx:idx+1,i:0})
    }
}