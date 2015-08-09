//
//  main.cpp
//  Broken Keyboard
//
//  Created by 黄佳睿 on 8/8/15.
//  Copyright (c) 2015 黄佳睿. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;
char in[90],out[90];
char visit[40];
int convert_int(char c){
    if(c >= '0' && c<= '9'){
        return c - '0';
    }
    else if(c >= 'a' && c <= 'z'){
        return c - 'a' + 10;
    }
    else if(c >= 'A' && c <= 'Z'){
        return c - 'A' + 10;
    }
    else
        return 36;
}
void check_print(char c){
    if (visit[convert_int(c)] == 0) {
        visit[convert_int(c)] = 1;
        if(c >= 'a' && c <= 'z'){
            c += 'A' - 'a';
        }
        cout<<c;
    }
    else
        return;

}
int main(int argc, const char * argv[]) {
    freopen("/Users/hjr/Desktop/test/in", "r", stdin);
    freopen("/Users/hjr/Desktop/test/out", "w", stdout);
    cin>>in>>out;
    memset(visit, 0, sizeof(visit));
    int inp,outp;
    int inl, outl;
    inl = (int)strlen(in);
    outl = (int)strlen(out);
    inp = outp = 0;
    while (inp < inl) {
        if (outp >= outl) {
            check_print(in[inp]);
            inp++;
        }
        if (in[inp] == out[outp]) {
            inp++;
            outp++;
        }
        else{
            check_print(in[inp]);
            inp++;
        }
    }
    
    
    
    return 0;
}
