#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string,int> data;
    
    for(string num: phone_book){
        int len = num.length();
        for(int i=1;i<len;++i){
            ++data[num.substr(0,i)];
        }
    }
    
    for(string num: phone_book){
        if(data[num] > 0){
            answer = false;
            break;
        }
    }
    return answer;
}