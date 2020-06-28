#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool comp(pair<int,int> a,pair<int,int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string,int> sumPlays;
    unordered_map<string,vector<pair<int,int>>> matchSongs;

    int len = genres.size();
    for(int i=0;i<len;++i){
        sumPlays[genres[i]] += plays[i];
        matchSongs[genres[i]].push_back(make_pair(i,plays[i]));
    }

    while(!sumPlays.empty()){
        int max = 0;
        string max_genre;
        for(pair<string,int> genre: sumPlays){
            if(max < genre.second){
                max = genre.second;
                max_genre = genre.first;
            }
        }
        sumPlays.erase(max_genre);

        vector<pair<int,int>> songs = matchSongs[max_genre];
        sort(songs.begin(),songs.end(),comp);
        
        
        answer.push_back(songs[0].first);
        
        if(songs.size() != 1){
            answer.push_back(songs[1].first);
        }
        
    }

    return answer;
}