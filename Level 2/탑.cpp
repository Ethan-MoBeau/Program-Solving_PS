#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> heights) {
    int len = heights.size();
    vector<int> answer(len,0);
    stack<pair<int,int>> stk;
    
    stk.push(make_pair(len-1,heights[len-1]));
    
    for(int i=len-2;i>=0;--i){
        pair<int,int> top = stk.top();
        while(top.second < heights[i]){
            answer[top.first] = i+1;
            stk.pop();
            if(stk.empty()) break;
            else top = stk.top();
        }
        stk.push(make_pair(i,heights[i]));
    }
    
    return answer;
}