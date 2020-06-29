#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <iostream>

using namespace std;

int prime[10000010];
map<int, int> result;

void solve(string num, int chk[], int len, int curr){
    if(!prime[curr]){
        result[curr]++;
    }

    for(int i=0;i<len;++i){
        if(!chk[i]){
            chk[i] = 1;
            solve(num,chk,len,curr*10+num[i]-'0');
            chk[i] = 0;
        }
    }
}

void chk_prime(int n){
    int max = 1;
    while(n > 0){
        n--;
        max *= 10;
    }

    prime[1] = 1;
    for(int i=2;i<=sqrt(max);++i){
        if(prime[i] == 0){
            for(int j=2;i*j<=max;++j) prime[i*j] = 1;
        }
    }

    return;
}

int solution(string numbers) {
    int answer = 0;
    int len = numbers.length();

    chk_prime(len);
    for(int i=0;i<len;++i){
        int chk[7]={0,};
        if(numbers[i] != '0'){
            chk[i] = 1;
            solve(numbers,chk,len,numbers[i]-'0');
        }
    }

    answer = result.size();
    return answer;
}