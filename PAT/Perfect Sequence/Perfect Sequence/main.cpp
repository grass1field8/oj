//
//  main.cpp
//  Perfect Sequence
//
//  Created by 黄佳睿 on 8/8/15.
//  Copyright (c) 2015 黄佳睿. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int n,p;
int in[100000];
int bfind(int first,int last, int num){
    int mid;
    mid = (first + last)/2+1;
    if (first == last) {
        return first;
    }
    else if(in[mid] > num){
        return bfind(first, mid-1, num);
    }
    else{
        return bfind(mid, last, num);
    }
}
int main(int argc, const char * argv[]) {
    freopen("/Users/hjr/Desktop/test/in", "r", stdin);
    freopen("/Users/hjr/Desktop/test/out", "w", stdout);
    cin>>n>>p;
    for (int i = 0; i < n; i++) {
        cin>>in[i];
    }
    sort(in, in+n);
    int len = 1;
    int pos;
    int index;
    for (index = 0; index < n - len; index++) {
        pos = bfind(index, n-1, in[index]*p);
        if (pos - index + 1 > len) {
            len = pos - index + 1;
        }
    }
    cout<<len;
    return 0;
}
