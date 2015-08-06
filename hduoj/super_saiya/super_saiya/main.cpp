//
//  main.cpp
//  super_saiya
//
//  Created by 黄佳睿 on 15/5/30.
//  Copyright (c) 2015年 黄佳睿. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
long long pw[10001];
long long exp;
int T;
int n,m,k,p,i;
int main(int argc, const char * argv[]) {
    //freopen("/Users/hjr/Desktop/test/in", "r", stdin);
    //freopen("/Users/hjr/Desktop/test/out", "w", stdout);
    cin>>T;
    
    for (p=1; p<=T; p++) {
        cout<<"Case #"<<p<<":"<<endl;
        scanf("%d %d %d",&n, &m, &k);
        for (i=1; i<=n; i++) {
            scanf("%lld",pw+i);
        }
        sort(pw+1, pw+n+1);
        
        exp = m;
        
        pw[n+1]=0;
        for (i=1; i<=n; i++) {
            if (pw[i]>exp) {
                break;
            }
            else if ( pw[i+1] > exp ) {
                exp = pw[i]+k;
                k--;
            }
            
            
        }
        if (i<=n) {
            printf("madan!\n");
        }
        else
            printf("why am I so diao?\n");
        
    }
    
    return 0;
}
