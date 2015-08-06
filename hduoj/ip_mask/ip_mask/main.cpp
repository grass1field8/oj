//
//  main.cpp
//  ip_mask
//
//  Created by 黄佳睿 on 15/5/23.
//  Copyright (c) 2015年 黄佳睿. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
unsigned int result[1000];
unsigned int ip[1000];
unsigned int mask[50];
int main(int argc, const char * argv[]) {
    //freopen("/Users/hjr/Desktop/test/in", "r", stdin);
    //freopen("/Users/hjr/Desktop/test/out", "w", stdout);
    int N;
    cin>>N;
    unsigned int q,w,e,r;
    for (int k=1; k<= N ;k++) {
        cout<<"Case #"<<k<<":"<<endl;
        int a,b;
        cin>>a>>b;
        for (int i=0; i<a; i++) {
            scanf("%u.%u.%u.%u",&q,&w,&e,&r);
            //cout<<q<<w<<e<<r<<endl;
            ip[i]=r+256*e+65536*w+16777216*q;
        }
        for (int i=0; i<b; i++) {
            scanf("%u.%u.%u.%u",&q,&w,&e,&r);
            //cout<<q<<w<<e<<r<<endl;
            mask[i]=r+256*e+65536*w+16777216*q;
        }
        for (int i=0; i<b; i++) {
            for (int j=0; j<a; j++) {
                result[j] = ip[j]&mask[i];
                //cout<<"ip: "<<ip[j]<<endl;
                //cout<<"mask: "<<mask[i]<<endl;
                //cout<<"result: "<<result[j]<<endl;
            }
            int num=0,cur=0;
            sort(result, result+a);
            for (int p=0; p<a; p++) {
                if (p==0) {
                    cur = result[0];
                    num++;
                }
                else if (result[p]>cur) {
                    cur = result[p];
                    num++;
                }
            }
            cout<<num<<endl;
        }
        
    }
    return 0;
}
