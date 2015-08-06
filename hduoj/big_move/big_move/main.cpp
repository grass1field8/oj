//
//  main.cpp
//  big_move
//
//  Created by 黄佳睿 on 15/5/23.
//  Copyright (c) 2015年 黄佳睿. All rights reserved.
//

#include <iostream>
#include <math.h>
#define PI 3.14159265358979323846
using namespace std;
int main(int argc, const char * argv[]) {
    //freopen("/Users/hjr/Desktop/test/in", "r", stdin);
    //freopen("/Users/hjr/Desktop/test/out", "w", stdout);
    int N;
    double n,a,r;
    cin>>N;
    for (int j=1; j<=N; j++) {
        cout<<"Case #"<<j<<":"<<endl;
        cin>>n>>a>>r;
        if (2*tan(PI/n)*r > a) {
            cout<<"I want to kiss you!"<<endl;
        }
        else
            cout<<"Give me a kiss!"<<endl;
    }
    
    return 0;
}
