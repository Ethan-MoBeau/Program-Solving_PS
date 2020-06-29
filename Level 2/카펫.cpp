#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int total = brown + yellow;
    int sum = (brown+4)/2;
    
    for(int i=3;i<=sum/2;++i){
        if(yellow == (i-2)*(sum-i-2)){
            answer.push_back(sum-i);
            answer.push_back(i);
            break;
        }
    }
    return answer;
}