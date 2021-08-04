/*
    가장 큰 정사각형 찾기
    https://programmers.co.kr/learn/courses/30/lessons/12905
*/
function solution(board)
{
    let rslt = board.some((s)=>s[0]) || board[0].some((s)=>s)
    for(let i = 1; i != board.length; ++i)
        for(let j = 1; j != board[i].length; ++j)
            if(board[i][j])
                rslt = Math.max(rslt,board[i][j] = Math.min(board[i-1][j-1],board[i-1][j],board[i][j-1])+1)
    return rslt*rslt
}