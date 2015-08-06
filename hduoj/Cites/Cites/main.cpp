//
//  main.cpp
//  Cites
//
//  Created by 黄佳睿 on 15/5/17.
//  Copyright (c) 2015年 黄佳睿. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int v[2001][2001];
int weight[2001][2001];
int visit[2001];

int main(int argc, const char * argv[]) {
    int T;
    cin>>T;
    memset(v, -1, sizeof(v));
    memset(weight, -1, sizeof(weight));
    memset(visit, 0, sizeof(visit));
    while (T > 0) {
        int N, K;
        cin>>N>>K;
        for (int i = 0; i < N-1; i++) {
            int a, b, c;
            cin>>a>>b>>c;
            //initial
            v[a][b] = v[b][a] = c;
            weight[a][a] = weight[b][b] = 0;
            weight[a][b] = weight[b][a] = c;
        }
        
        //topo
        queue<int> que;
        que.push(1);
        visit[1] = 1;
        while (!que.empty()) {
            int tmp = que.front();
            que.pop();
            for (int i = 1; i<=N; i++) {
                if (v[tmp][i] > 0 && visit[i] == 0) {
                    que.push(i);
                    for (int j = 1; j<=N; j++) {
                        if (visit[j] == 1) {
                            weight[j][i] = weight[i][j] = weight[tmp][i] + weight[tmp][j];
                        }
                    }
                    visit[i] = 1;
                }
            }
        }
        
        
        //iter every i in N as source
        int min_exp = 100000000;
        memset(visit, 0, sizeof(visit));
        for (int i = 1; i<=N; i++) {
            visit[i] = 1;
            
        }
        
        
        
        
        
        
        
        
        
        
        T--;
    }
}
