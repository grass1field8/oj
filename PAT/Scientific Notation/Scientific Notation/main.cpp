//
//  main.cpp
//  Scientific Notation
//
//  Created by 黄佳睿 on 8/9/15.
//  Copyright (c) 2015 黄佳睿. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
char in[100000], ab[100000], fra[100000];
int sign1;
int fraction;
int main(int argc, const char * argv[]) {
    freopen("/Users/hjr/Desktop/test/in", "r", stdin);
    freopen("/Users/hjr/Desktop/test/out", "w", stdout);
    cin>>in;
    int len;
    len = (int)strlen(in);
    if (in[0] == '+') {
        sign1 = 0;
        //cout<<'+';
    }
    else{
        sign1 = 1;
        cout<<'-';
    }
    int pos;
    for (int i = 1; i < len; i++) {
        if (in[i] == 'E') {
            pos = i;
            break;
        }
    }
    
    in[pos] = '\0';
    ab[0] = in[1];
    strcpy(ab + 1, in + 3);
    strcpy(fra, in + pos + 1);
    sscanf(fra, "%d",&fraction);
    //cout<<sign1<<endl<<ab<<endl<<fraction<<endl;
    int point = 1;
    point += fraction;
    int abslen;
    abslen = (int)strlen(ab);
    if (point <= 0) {
        cout<<"0.";
        for (int i=0; i < -point; i++) {
            cout<<'0';
        }
        cout<<ab;
    }
    else if(point > 0 && point < abslen){
        for (int i = 0; i < point; i++) {
            cout<<ab[i];
        }
        cout<<'.';
        for (int i = point; i<abslen; i++) {
            cout<<ab[i];
        }
    }
    else{
        cout<<ab;
        for (int i = 0; i < point - abslen; i++) {
            cout<<'0';
        }
    }
    
    
    
    
    return 0;
}
