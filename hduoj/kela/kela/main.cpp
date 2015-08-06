//
//  main.cpp
//  kela
//
//  Created by 黄佳睿 on 15/5/31.
//  Copyright (c) 2015年 黄佳睿. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int field[1001][1001];
typedef struct ver{
    int u;
    int v;
    int l;
}ver;
ver vert[2000000];
int p[1000001];
int T;
int n,m;
int i,j,k;
int len, point;
int x,y;
int ct;
bool cmp(const ver a, const ver b){
    return a.l<b.l;
}
int fd(int x){ return p[x]==x?x:p[x] = fd(p[x]); }
int main(int argc, const char * argv[]) {
    //freopen("/Users/hjr/Desktop/test/in", "r", stdin);
    //freopen("/Users/hjr/Desktop/test/out", "w", stdout);
    scanf("%d",&T);
    for (k=1; k<=T; k++) {
        printf("Case #%d:\n",k);
        len=0;
        ct=0;
        
        
        scanf("%d%d",&n,&m);
        point = m*n;
        for (i=1; i<=n; i++) {
            for (j=1; j<=m; j++) {
                scanf("%d",&(field[i][j]));
                if (i>1) {
                    vert[len].l = abs(field[i][j] - field[i-1][j]);
                    vert[len].u = (i-1)*m+j;
                    vert[len].v = (i-1-1)*m+j;
                    len++;
                    
                }
                if (j>1) {
                    vert[len].l = abs(field[i][j] - field[i][j-1]);
                    vert[len].u = (i-1)*m+j;
                    vert[len].v = (i-1)*m+j-1;
                    len++;
                }
            }
        }
        for (i = 1; i<=point; i++) {
            p[i] = i;
        }
        sort(vert, vert+len, cmp);
        for (i=0; i<len; i++) {
            //cout<<"vertex: "<<vert[i].l<<" "<<vert[i].u<<" "<<vert[i].v<<endl;
            x = fd(vert[i].u);
            y = fd(vert[i].v);
            if (x != y) {
                ct += vert[i].l;
                p[x] = y;
            }
        }
        printf("%d\n",ct);
        
        
        
    }
    return 0;
}
