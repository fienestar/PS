/*
    베스트앨범
    https://programmers.co.kr/learn/courses/30/lessons/42579
*/
function compare(a,b)
{
    if(Number.isInteger(a))
        return a-b
    else
        return [a,b].sort()[0] == a ? 1 : -1
}

function sort_helper(container1, container2, indexs)
{
    for(let i in indexs)
        if(container1[indexs[i]] != container2[indexs[i]])
            return compare(container1[indexs[i]], container2[indexs[i]])
    return 0
}

function set_default(obj,idx,val)
{
    return obj[idx] = obj[idx] || val
}

function solution(genres, plays) {
    let musics = genres.map((genre,index)=>({genre, index, play: -plays[index]}))
    genres = {}
    for(let i in musics){
        let genre = set_default(genres,musics[i].genre,{})
        set_default(genre,'name',musics[i].genre)
        set_default(genre,'musics',[]).push(musics[i])
        set_default(genre,'play',0)
        genre.play+=musics[i].play
    }
    let sorted_genre = []
    for(let i in genres)
        sorted_genre.push(genres[i])
    sorted_genre.sort((a,b)=>a.play-b.play)
    
    let result = []
    for(let i in sorted_genre){
        sorted_genre[i].musics.sort((a,b)=>sort_helper(a,b,['play','index']))
        let sliced = sorted_genre[i].musics.slice(0,2)
        for(let i in sliced)
            result.push(sliced[i].index)
    }
    return result
}