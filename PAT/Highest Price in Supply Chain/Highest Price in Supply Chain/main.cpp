//
//  main.cpp
//  Highest Price in Supply Chain
//
//  Created by 黄佳睿 on 8/6/15.
//  Copyright (c) 2015 黄佳睿. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;
int tree[100000];
int num;
double price, rate;
int main(int argc, const char * argv[]) {
    freopen("/Users/hjr/Desktop/test/in", "r", stdin);
    freopen("/Users/hjr/Desktop/test/out", "w", stdout);
    cin>>num>>price>>rate;
    for (int i = 0; i < num; i++) {
        cin>>tree[i];
    }
    int number, depth;
    depth = 0;
    number = 0;
    for (int i = 0; i < num; i++) {
        int dep = 0;
        int j = i;
        while (tree[j] != -1) {
            j = tree[j];
            dep++;
        }
        if (dep > depth) {
            depth = dep;
            number = 1;
        }
        else if(dep == depth){
            number++;
        }
    }
    double res = price * pow(1+rate/100, depth);
    printf("%.2f",res);
    cout<<" "<<number;
    return 0;
}
