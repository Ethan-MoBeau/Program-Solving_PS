#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    stack<char> stk;
    
    int len = arrangement.length();
    for(int i=0;i<len;++i){
        if(arrangement[i] == '('){
            if(i+1 < len && arrangement[i+1] == ')'){
                answer += stk.size();
                i++;
            }
            else{
                stk.push('(');
            }
        }
        else{
            stk.pop();
            answer++;
        }
    }
    return answer;
}