#include <string>
#include <vector>
#include <deque>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    deque<pair<int,int>> que;
    unordered_map<int,int> speedMap;
    
    int len = progresses.size();
    for(int i=0;i<len;++i){
        que.push_back(make_pair(i,progresses[i]));
        speedMap[i] = speeds[i];
    }
    
    while(!que.empty()){
        len = que.size();
        for(int i=0;i<len;++i){
            que[i].second += speedMap[que[i].first];
        }
        
        int cnt = 0;
        while(que.front().second >= 100){
            cnt++;
            que.pop_front();
        }
        if(cnt > 0) answer.push_back(cnt);
    }
    return answer;
}