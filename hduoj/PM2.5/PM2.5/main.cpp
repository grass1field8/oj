//
//  main.cpp
//  PM2.5
//
//  Created by 黄佳睿 on 15/5/22.
//  Copyright (c) 2015年 黄佳睿. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<double, int> pp;
pp ar[10000];
bool grt(const pp &a, const pp &b){
    return a.first>b.first;
}
int main(int argc, const char * argv[]) {
    freopen("/Users/hjr/Desktop/test/in", "r", stdin);
    freopen("/Users/hjr/Desktop/test/out", "w", stdout);
    int n;
    int ok = 0;
    while (!cin.eof()) {
        if (ok == 0) {
            ok=1;
        }
        else
            cout<<endl;
        cin>>n;
        for (int i = 0; i<n; i++) {
            int a,b;
            cin>>a>>b;
            ar[i] = make_pair((abs(a-b)-1.0*b/1000), i);
        }
        stable_sort(ar, ar+n, grt);
        
        for (int i=0; i<n; i++) {
            if (i!=0) {
                cout<<" ";
            }
            cout<<ar[i].second;
        }
    }
    return 0;
}
