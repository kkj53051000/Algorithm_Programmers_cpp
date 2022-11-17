#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    
    int answer = 0;
    int scoreSize = score.size();
    
    sort(score.rbegin(), score.rend());
    
    vector<int> mArr;
    
    for(int i = 0; i < scoreSize; i++) {
        if(mArr.size() == m) {
            answer += mArr[m-1] * m;
            
            mArr = {};
        }
        
        mArr.push_back(score[i]);
    }
    
    if(mArr.size() == m) {
        answer += mArr[m-1] * m;
    }
    

    return answer;
}