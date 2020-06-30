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

8 4
7 1 1
2 1 1
4 0 1
8 1 1
1 0 1
1 1 1
1 1 1
3 0 0
