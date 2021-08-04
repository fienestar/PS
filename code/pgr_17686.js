/*
    [3차] 파일명 정렬
    https://programmers.co.kr/learn/courses/30/lessons/17686
*/
function normalize(name)
{
    if(name.normalized)
        return name.normalized
    name = name.match(/([^0-9]+)(\d{0,5})(.*)/)
    name[1] = name[1].toLowerCase()
    name[2] = name[2].padStart(5,'0')
    return name.normalized=name
}

function compare(a,b)
{
    return ([a,b].sort()[0] == a) ? -1 : 1
}

function solution(files) {
    return files.sort((a,b)=>{
        a = normalize(a)
        b = normalize(b)
        for(let i=1;i!=3;++i)
            if(a[i] != b[i])
                return compare(a[i],b[i])
        return 0
    })
}