//
//  main.cpp
//  prime
//
//  Created by 黄佳睿 on 15/5/18.
//  Copyright (c) 2015年 黄佳睿. All rights reserved.
//

#include <iostream>
int isprime[100001];
int prime[50000];
int prime_len = 1;
int main(int argc, const char * argv[]) {
    freopen("/Users/hjr/Desktop/test/in", "r", stdin);
    freopen("/Users/hjr/Desktop/test/out", "w", stdout);
    memset(isprime, 1, sizeof(isprime));
    prime[0] = 1;
    isprime[0] = 0;
    isprime[1] = 0;
    for (int i = 2; i<=100000; i++) {
        if (isprime[i] != 0) {
            prime[prime_len++] = i;
            if (i < 46341)
                for (int j = i*i; j<=100000; j+=i) {
                    isprime[j] = 0;
                }
        }
    }
    return 0;
}
