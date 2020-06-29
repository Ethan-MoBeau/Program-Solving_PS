#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    int que_sum = 0;
    int time = 0;
    deque<pair<int,int>> que;

    while(!que.empty() || !truck_weights.empty()){
        if(!truck_weights.empty() && que_sum + truck_weights[0] <= weight){
            que_sum += truck_weights[0];
            que.push_back(make_pair(truck_weights[0],0));
            truck_weights.erase(truck_weights.begin());
        }
        int len = que.size();

        for(int i=0;i<len;++i){
            que[i].second++;
        }

        if(que[0].second == bridge_length){
            que_sum -= que[0].first;
            que.pop_front();
        }
        answer++;
    }
    return answer+1;
}