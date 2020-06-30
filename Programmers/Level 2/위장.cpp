#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string,int> data;
    for(vector<string> cloth: clothes){
        data[cloth[1]]++;
    }
    
    for(pair<string,int> cloth: data){
        answer *= cloth.second+1;
    }
    return answer-1;
}