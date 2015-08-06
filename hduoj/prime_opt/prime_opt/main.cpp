//
//  main.cpp
//  prime_opt
//
//  Created by 黄佳睿 on 15/5/18.
//  Copyright (c) 2015年 黄佳睿. All rights reserved.
//

#include <iostream>
using namespace std;
int isNotPrime[100001];
int prime[50000];
int prime_len = 0;
int main(int argc, const char * argv[]) {
    int n = 100000;
    //freopen("/Users/hjr/Desktop/test/in", "r", stdin);
    freopen("/Users/hjr/Desktop/test/out", "w", stdout);
    memset(isNotPrime, 0, sizeof(isNotPrime));
    isNotPrime[0] = isNotPrime[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!isNotPrime[i]) {
            prime[prime_len++] = i;
        }
        for (int j = 0; j<prime_len && prime[j]*i<=n; j++) {
            isNotPrime[prime[j]*i] = 1;
            if (i%prime[j] == 0) {
                break;
            }
        }
    }
    cout<<prime_len<<endl;
    for (int i = 0 ; i<prime_len; i++) {
        cout<<prime[i]<<endl;
        
    }
    return 0;
}

