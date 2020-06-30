#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int,vector<int>,greater<int>> heap;
    
    int len = scoville.size();
    for(int i=0;i<len;++i){
        heap.push(scoville[i]);
    }
    
    int cnt = 0;
    while(heap.size() >= 2 && heap.top() < K){
        int min_1 = heap.top();
        heap.pop();
        int min_2 = heap.top();
        heap.pop();
        heap.push(min_1+min_2*2);
        
        cnt++;
    }
    
    int answer;
    if(heap.top() < K) answer = -1;
    else answer = cnt;
    
    return answer;
}