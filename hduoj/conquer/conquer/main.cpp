//
//  main.cpp
//  conquer
//
//  Created by 黄佳睿 on 15/5/31.
//  Copyright (c) 2015年 黄佳睿. All rights reserved.
//

#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
int T;
int n,m,g;
int i,j,k;
int city[502][502];
int x,y;
int xxx,yyy;
int ct;
int change[4][4] = {{1,-1},{1,1},{-1,1},{-1,-1}};
int xx,yy;
queue<pair<int, int> > que;
pair<int, int> p;
int main(int argc, const char * argv[]) {
    //freopen("/Users/hjr/Desktop/test/in", "r", stdin);
    //freopen("/Users/hjr/Desktop/test/out", "w", stdout);
    scanf("%d",&T);
    for (k=1; k<=T; k++) {
        printf("Case #%d:\n",k);
        while (!que.empty()) {
            que.pop();
        }
        ct=0;
        memset(city, 0, sizeof(city));
        scanf("%d%d",&n,&m);
        scanf("%d",&g);
        for (i=1; i<=g; i++) {
            scanf("%d%d",&x,&y);
            if(city[x][y] == 0){
                city[x][y]=1;
                que.push(make_pair(x, y));
                //cout<<"x,y: "<<x<<" "<<y<<endl;
                ct++;
            }
            
        }
        while (!que.empty()) {
            p = que.front();
            que.pop();
            for (i=0; i<4; i++) {
                
                xx = p.first + change[i][0];
                yy = p.second + change[i][1];
                if (xx>=1 && xx<=n && yy>=1 && yy<=m) {
                    if (city[xx][yy] == 1) {
                        xxx = p.first + change[i][0];
                        yyy = p.second;
                        if (city[xxx][yyy] == 0) {
                            city[xxx][yyy] = 1;
                            que.push(make_pair(xxx, yyy));
                            //cout<<"x,y: "<<xxx<<" "<<yyy<<endl;
                            ct++;
                        }
                        
                        xxx = p.first;
                        yyy = p.second + change[i][1];
                        if (city[xxx][yyy] == 0) {
                            city[xxx][yyy] = 1;
                            que.push(make_pair(xxx, yyy));
                            //cout<<"x,y: "<<xxx<<" "<<yyy<<endl;
                            ct++;
                        }
                    }
                }
            }
        }
        printf("%d\n",ct);
        
    }
    return 0;
}
