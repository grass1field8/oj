//
//  main.cpp
//  Count PAT's
//
//  Created by 黄佳睿 on 8/4/15.
//  Copyright (c) 2015 黄佳睿. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;
char in[100001];
int main(int argc, const char * argv[]) {
    
    freopen("/Users/hjr/Desktop/test/in", "r", stdin);
    freopen("/Users/hjr/Desktop/test/out", "w", stdout);
    
    long long p, pa, pat;
    cin>>in;
    p = 0;
    pa = 0;
    pat = 0;
    for (int i = 0; i < strlen(in); i++) {
        if (in[i] == 'P') {
            p++;
            p = p%1000000007;
        }
        else if(in[i] == 'A'){
            pa += p;
            pa = pa%1000000007;
        }
        else if(in[i] == 'T'){
            pat += pa;
            pat = pat%1000000007;
        }
    }
    cout<<pat%1000000007;
    return 0;
}
