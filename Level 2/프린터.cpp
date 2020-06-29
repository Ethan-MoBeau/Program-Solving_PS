#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int,int>> que;
    
    int len = priorities.size();
    for(int i=0;i<len;++i){
        que.push(make_pair(i,priorities[i]));
    }
    
    sort(priorities.begin(),priorities.end());
    
    while(!que.empty()){
        int currMax = priorities.back();
        priorities.pop_back();
        
        while(1){
            pair<int,int> front = que.front();
            que.pop();
            if(front.second == currMax){
                answer++;
                if(front.first == location) return answer;
                break;
            }
            que.push(front);
        }
    }
    
    return answer;
}