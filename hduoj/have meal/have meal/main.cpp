//
//  main.cpp
//  have meal
//
//  Created by 黄佳睿 on 15/5/18.
//  Copyright (c) 2015年 黄佳睿. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int main(int argc, const char * argv[]) {
    int e[101][101];
    int in[101];
    //freopen("/Users/hjr/Desktop/test/in", "r", stdin);
    //freopen("/Users/hjr/Desktop/test/out", "w", stdout);
    while (!cin.eof()) {
        memset(e, 0,sizeof(e));
        memset(in, 0, sizeof(in));
        int m,n;
        cin>>n>>m;
        while (m > 0) {
            int a,b;
            cin>>a>>b;
            e[b][a]++;
            in[a]++;
            
            m--;
        }
        queue<int> que;
        for (int i = 1; i<=n; i++) {
            if (in[i] == 0) {
                que.push(i);
            }
        }
        while (!que.empty()) {
            int tmp = que.front();
            que.pop();
            for (int i = 1; i<n; i++) {
                if (e[tmp][i] != 0) {
                    in[i] -= e[tmp][i];
                    e[tmp][i] = 0;
                    if (in[i] == 0) {
                        que.push(i);
                    }
                }
            }
        }
        int j;
        for (j =1; j<n;j++) {
            if (in[j] != 0) {
                cout<<"NO"<<endl;
                break;
            }
        }
        if (j>=n) {
            cout<<"YES"<<endl;
        }
        
    }
    return 0;
}
