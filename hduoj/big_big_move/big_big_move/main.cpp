//
//  main.cpp
//  big_big_move
//
//  Created by 黄佳睿 on 15/5/23.
//  Copyright (c) 2015年 黄佳睿. All rights reserved.
//

#include <iostream>
using namespace std;
unsigned long long n,ct;
unsigned long long ar[1000001];
int main(int argc, const char * argv[]) {
    //freopen("/Users/hjr/Desktop/test/in", "r", stdin);
    //freopen("/Users/hjr/Desktop/test/out", "w", stdout);
    //memset(ar, 0, sizeof(ar));
    ar[1]=1;
    ar[2]=2;
    ct=3;
    while (ct!=1000001) {
        ar[ct] = (ar[ct-1]+((ct-1)*ar[ct-2])%1000000007)%1000000007;
        ct++;
    }
    int T;
    cin>>T;
    for (int i=1; i<=T; i++) {
        cout<<"Case #"<<i<<":\n";
        cin>>n;
        cout<<ar[n]<<endl;
    }
    return 0;
}
