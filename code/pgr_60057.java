/*
    문자열 압축
    https://programmers.co.kr/learn/courses/30/lessons/60057
*/
class Solution {
    String compress(String s, int len)
    {
        StringBuilder result = new StringBuilder();
        String before = "";
        
        int n = 1;
        for(int i=0; i<=s.length(); i+=len) {
            String sliced = s.substring(i, Math.min(i+len, s.length()));
            
            if(sliced.equals(before))
                ++n;
            else{
                if(n != 1) {
                    result.append(n);
                    n = 1;
                }
                result.append(sliced);
                before = sliced;
            }
        }

        return result.toString();
    }
    
    public int solution(String s) {
        int answer = s.length();
        for(int i=1; i<=s.length(); ++i)
            answer = Math.min(answer, compress(s, i).length());
        return answer;
    }
}