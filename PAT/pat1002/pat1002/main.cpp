//
//  main.cpp
//  pat1002
//
//  Created by 黄佳睿 on 7/29/15.
//  Copyright (c) 2015 黄佳睿. All rights reserved.
//

#include <iostream>
using namespace std;
typedef struct num{
    int index;
    double data;
}num;
num a[10],b[10],c[20];
int la, lb, lc;
int main(int argc, const char * argv[]) {
    freopen("/Users/hjr/Desktop/test/in", "r", stdin);
    freopen("/Users/hjr/Desktop/test/out", "w", stdout);
    int k;
    cin>>k;
    la = k;
    int j=0;
    while (k!=0) {
        k--;
        cin>>a[j].index>>a[j].data;
        j++;
    }
    cin>>k;
    lb = k;
    j=0;
    while (k!=0) {
        k--;
        cin>>b[j].index>>b[j].data;
        j++;
    }
    
    int pa,pb,pc;
    pa = pb = pc = 0;
    while (pa <  la && pb<la) {
        if (a[pa].index == b[pb].index) {
            c[pc].index = a[pa].index;
            c[pc].data =a[pa].data + b[pb].data;
            pa++;
            pb++;
            pc++;
        }
        else if(a[pa].index > b[pb].index){
            c[pc].index = a[pa].index;
            c[pc].data =a[pa].data;
            pc++;
            pa++;
        }
        else{
            c[pc].index = b[pb].index;
            c[pc].data =b[pb].data;
            pc++;
            pb++;
        }
    }
    while (pa<la) {
        c[pc].index = a[pa].index;
        c[pc].data =a[pa].data;
        pc++;
        pa++;
    }
    while (pb<lb) {
        c[pc].index = b[pb].index;
        c[pc].data =b[pb].data;
        pc++;
        pb++;
    }
    lc = pc;
    
    cout<<lc;
    double db;
    pc=0;
    while (pc<lc) {
        cout<<" "<<c[pc].index;
        db = c[pc].data;
        if (db - (int)db == 0) {
            cout<<" "<<db;
        }
        else
            printf(" %.1f",c[pc].data);
        pc++;
    }
    
    return 0;
}
