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

// 정랼 => m개씩 mArr에 넣어서 mArr.size() == m 일때 mArr 마지막 값(제일 작은) * m => 마지막에 반복문 안에서 검사 못했을 경우 때문에 한번 더 검사해줌.

// 성공

// 시간 복잡도 : O(n)