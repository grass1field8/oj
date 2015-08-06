//
//  main.cpp
//  the meal
//
//  Created by 黄佳睿 on 15/5/18.
//  Copyright (c) 2015年 黄佳睿. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int a=0, b=0, c;
    cin>>a>>b;
    c = b%a;
    if (c == 0) {
        cout<<a-1<<endl;
    }
    else
        cout<<c-1<<endl;

    return 0;
}
