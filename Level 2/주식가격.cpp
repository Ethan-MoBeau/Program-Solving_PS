#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices){
    stack<pair<int,int>> stk;
    stk.push(make_pair(prices[0],0));
    
    int len = prices.size();
    vector<int> answer(len);
    
    for(int i=1;i<len;++i){
        pair<int,int> top = stk.top();
        while(top.first > prices[i]){
            answer[top.second] = i - top.second;
            stk.pop();
            if(stk.empty()) break;
            top = stk.top();
        }
        stk.push(make_pair(prices[i],i));
    }
    
    while(!stk.empty()){
        pair<int,int> top = stk.top();
        answer[top.second] = len-1 - top.second;
        stk.pop();
    }
    return answer;
}