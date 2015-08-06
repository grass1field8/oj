//
//  main.cpp
//  pat1001
//
//  Created by 黄佳睿 on 7/29/15.
//  Copyright (c) 2015 黄佳睿. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    freopen("/Users/hjr/Desktop/test/in", "r", stdin);
    freopen("/Users/hjr/Desktop/test/out", "w", stdout);
    int a,b,c;
    char num[10];
    int len=0, flag;
    cin>>a>>b;
    flag = 0;
    c = a + b;
    if(c < 0){
        flag = 1;
        c = -c;
    }
    int digit;
    if (c == 0) {
        cout<<"0";
        return 0;
    }
    while (c != 0) {
        digit = c%10;
        c /=10;
        num[len] = '0'+digit;
        len++;
    }
    int ct;
    ct = (3-len%3)%3;
    if (flag == 1) {
        cout<<"-";
    }
    len--;
    while (len >= 0) {
        if (ct == 3) {
            ct=0;
            cout<<",";
        }
        cout<<num[len];
        ct++;
        len--;
    }
    return 0;
}
