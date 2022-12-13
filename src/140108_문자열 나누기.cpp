#include <string>
#include <vector>

using namespace std;

/*
* 첫번째 문자와 다음 문자를 Counting해서 같은 문자면 same++ 다르면 diff++ 해서 same, diff 둘이 같으면 answer++하고 초기화 한 뒤 뒤에도 똑같이 반복
*/

int solution(string s) {
    int answer = 0;
    
    // 첫번째 문자 xChar
    char xChar = 0;
    
    int same = 0;
    int diff = 0;
    
    for(int i = 0; i < s.size(); i++) {
        // 현재 char 넣어줌
        char nowChar = s[i];
        
        // 비교할 xChar가 비어있으면 값을 넣어주고 continue.
        if(xChar == 0) {
            same++;
            
            xChar = s[i];
            continue;
        }
        
        
        if(xChar != nowChar) {
            diff++;
        }
        if(xChar == nowChar) {
            same++;
        }
        
        // aCount(비교할 Char 개수)와 bCount(비교하는 Char 개수)이 같으면 : answer++ & 전부 초기화
        if(same == diff) {
            answer++;
            same = 0;
            diff = 0;
            
            xChar = 0;
        }
    }
    
    // 마지막에 남아 있는 문자가 있으면 answer + 1
    if(same != 0) {
        answer++;
    }
    
    return answer;
}