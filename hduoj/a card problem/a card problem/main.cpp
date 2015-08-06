//
//  main.cpp
//  a card problem
//
//  Created by 黄佳睿 on 15/5/18.
//  Copyright (c) 2015年 黄佳睿. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int a[100001];
int good[100001];
const int m = 1000000007;
const int N = 100000;
int isNotGood[N+1];
int prime[50000];
int prime_num;
int gcd(int a, int b){
    int c;
    if (a<b) {
        c = a;
        a = b;
        b = c;
    }
    while (1) {
        if (a%b == 0) {
            return b;
        }
        else{
            c = a%b;
            a = b;
            b = c;
        }
    }
}
int temp[100000];
int main(int argc, const char * argv[]) {
    //initial
    memset(good, 0, sizeof(good));
    //initial prime
    prime_num = 0;
    memset(isNotGood, 0, sizeof(isNotGood));
    isNotGood[0] = isNotGood[1] = 1;
    for (int i = 2; i<=N; i++) {
        if (!isNotGood[i]) {
            prime[prime_num++] = i;
        }
        for (int j = 0; j<prime_num && prime[j]*i<=N; j++) {
            isNotGood[prime[j]*i] = 1;
            while (i%prime[j] == 0) {
                break;
            }
        }
    }
    
    int pow;
    for (int i =0; i<prime_num; i++) {
        pow = prime[i];
        if (pow*pow>N) {
            break;
        }
        while ((pow *= prime[i]) <= N) {
            isNotGood[pow] = 0;
        }
        
    }
    isNotGood[1] = 0;
    
    
    
    
    
    
    
    
    
    //freopen("/Users/hjr/Desktop/test/in", "r", stdin);
    //freopen("/Users/hjr/Desktop/test/out", "w", stdout);
    while (!cin.eof()) {
        int n;
        int cnt;
        cnt = 0;
        cin>>n;
        for (int i = 1; i<=n; i++) {
            cin>>a[i];
        }
        for (int i = 1; i<n; i++) {
            memcpy(temp, a+i+1, sizeof(int) * (n-i));
            sort(temp, temp+n-i);
            int ct = 0,num=0;
            for (int j = 0; j<n-i; j++) {
                for (int p=1; p<=a[i]; p++) {
                    for (int q = num+1; q<=temp[j]; q++) {
                        //cout<<p<<" "<<q<<endl;
                        int tmp = gcd(p, q);
                        if(!isNotGood[tmp]){
                            ct++;
                            if (ct>=m) {
                                ct-=m;
                            }
                        }
                    }
                }
                num = temp[j];
                cnt += ct;
                if (cnt>=m) {
                    cnt-=m;
                }
            }
        }
        cout<<cnt<<endl;
    }
    
    
    return 0;
}
