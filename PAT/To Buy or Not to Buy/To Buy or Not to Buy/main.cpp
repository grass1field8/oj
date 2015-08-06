//
//  main.cpp
//  To Buy or Not to Buy
//
//  Created by 黄佳睿 on 8/3/15.
//  Copyright (c) 2015 黄佳睿. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

char shop[1000],me[1000];
int main(int argc, const char * argv[]) {
    
    freopen("/Users/hjr/Desktop/test/in", "r", stdin);
    freopen("/Users/hjr/Desktop/test/out", "w", stdout);
    
    cin>>shop>>me;
    
    sort(shop,shop + strlen(shop));
    sort(me, me + strlen(me));
    //cout<<shop<<endl;
    //cout<<me<<endl;
    int need = 0;
    int pshop=0,pme=0;
    pshop = 0;
    pme = 0;
    while (pshop < strlen(shop) && pme < strlen(me) ) {
        if (me[pme] > shop[pshop]) {
            pshop++;
            //cout<<"1";
        }
        else if(me[pme] == shop[pshop]) {
            pme++;
            pshop++;
            //cout<<"0";
        }
        else{
            need++;
            pme++;
            //cout<<"2";
        }
    }
    if (pme < strlen(me)) {
        need += strlen(me) - pme;
    }
    if (need == 0) {
        cout<<"Yes"<<" "<<strlen(shop)-strlen(me);
    }
    else{
        cout<<"No"<<" "<<need;
    }
}
