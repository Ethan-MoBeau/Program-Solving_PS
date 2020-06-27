#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string,int> data;
    
    for(string name : completion){
        ++data[name];
    }
    for(string name : participant){
        if(data[name] == 0){
            answer = name;
            break;
        }
        --data[name];
    }
    return answer;
}
