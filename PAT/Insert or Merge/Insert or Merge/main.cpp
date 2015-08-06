//
//  main.cpp
//  Insert or Merge
//
//  Created by 黄佳睿 on 8/6/15.
//  Copyright (c) 2015 黄佳睿. All rights reserved.
//

#include <iostream>
using namespace std;
int org[100], sorted[100], res[100];
int len, maxas;
int asc(const int *a, int start, int t){
    int cur = a[start];
    for (int i = 0; i < t; i++) {
        if (a[i+start] >= cur) {
            cur = a[i+start];
        }
        else
            return 1;
    }
    return 0;
}
int main(int argc, const char * argv[]) {
    freopen("/Users/hjr/Desktop/test/in", "r", stdin);
    freopen("/Users/hjr/Desktop/test/out", "w", stdout);
    
    cin>>len;
    for (int i; i<len; i++) {
        cin>>org[i];
    }
    for (int i; i<len; i++) {
        cin>>sorted[i];
    }
        return 0;
}
