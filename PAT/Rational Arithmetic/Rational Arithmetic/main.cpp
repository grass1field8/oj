//
//  main.cpp
//  Rational Arithmetic
//
//  Created by 黄佳睿 on 8/6/15.
//  Copyright (c) 2015 黄佳睿. All rights reserved.
//

#include <iostream>
using namespace std;
struct ration {
    int a;
    int b;
    int c;
    int sign;
};
int a1,b1,a2,b2,a3,b3;
ration r1,r2,r3;
ration trans(int a, int b){
    ration r;
    if (a*b < 0) {
        r.sign = 1;
        if(a<0)
            a = -a;
        if (b<0)
            b = -b;
    }
    else
        r.sign = 0;
    r.c = a/b;
    a = a%b;
    int a1,b1,c1;
    r.a = a;
    r.b = b;
    
    if (a!=0) {
        a1 = a, b1 = b;
        while (b1%a1 != 0) {
            c1 = a1;
            a1 = b1%a1;
            b1 = c1;
        }
        
        r.a = a/a1;
        r.b = b/a1;
    }
    
    return r;
}
void print(ration r){
    if (r.c == 0 && r.a == 0) {
        cout<<"0";
        return;
    }
    if(r.sign == 1){
        r.sign = 0;
        cout<<"(-";
        print(r);
        cout<<")";
        return;
    }
    if (r.c != 0) {
        cout<<r.c;
        if (r.a != 0) {
            cout<<" ";
        }
    }
    if (r.a != 0) {
        cout<<r.a<<'/'<<r.b;
    }
    return;
}

int main(int argc, const char * argv[]) {
    freopen("/Users/hjr/Desktop/test/in", "r", stdin);
    freopen("/Users/hjr/Desktop/test/out", "w", stdout);
    scanf("%d/%d %d/%d", &a1,&b1,&a2,&b2);
    r1 = trans(a1, b1);
    r2 = trans(a2, b2);
    //sum
    a3 = a1*b2 + a2*b1;
    b3 = b1*b2;
    r3 = trans(a3, b3);
    print(r1);
    cout<<" + ";
    print(r2);
    cout<<" = ";
    print(r3);
    
    cout<<endl;
    //diff
    a3 = a1*b2 - a2*b1;
    b3 = b1*b2;
    r3 = trans(a3, b3);
    print(r1);
    cout<<" - ";
    print(r2);
    cout<<" = ";
    print(r3);
    cout<<endl;
    
    //prod
    a3 = a1*a2;
    b3 = b1*b2;
    r3 = trans(a3, b3);
    print(r1);
    cout<<" * ";
    print(r2);
    cout<<" = ";
    print(r3);
    cout<<endl;
    
    //quo
    if (a2 == 0) {
        print(r1);
        cout<<" / ";
        print(r2);
        cout<<" = Inf";
    }
    else{
        a3 = a1*b2;
        b3 = b1*a2;
        r3 = trans(a3, b3);
        print(r1);
        cout<<" / ";
        print(r2);
        cout<<" = ";
        print(r3);
    }
    
    
}
