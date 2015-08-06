//
//  main.cpp
//  Harry and Magical Computer
//
//  Created by 黄佳睿 on 15/5/18.
//  Copyright (c) 2015年 黄佳睿. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int main(int argc, const char * argv[]) {
    freopen("/Users/hjr/Desktop/test/in", "r", stdin);
    freopen("/Users/hjr/Desktop/test/out", "w", stdout);
    int e[101][101];
    int visit[101];
    int bad=0;
    while (!cin.eof()) {
        bad = 0;
        int N, M;
        cin>>N>>M;
        memset(e, 0, sizeof(e));
        memset(visit, 0, sizeof(visit));
        for (int i = 0; i<M; i++) {
            int a,b;
            cin>>a>>b;
            e[b][a] = 1;
            if(a == b)
                bad =1;
        }
        
        for (int k = 1; k<=N; k++) {
            if (visit[k] == 0) {
                queue<int> que;
                que.push(k);
                while (!que.empty()) {
                    int tmp = que.front();
                    que.pop();
        
                    visit[tmp] = k;
                    for (int i = 1; i<=N; i++) {
                        if (e[tmp][i] == 1) {
                            if (visit[i] == k) {
                                bad=1;
                                break;
                            }
                            else{
                                que.push(i);
                            }
                            
                                
                        }
                        
                    }
                    if(bad == 1)
                        break;
                }
                if (bad==1)
                    break;
            }
        }
        if (bad == 0) {
            cout<<"YES"<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
