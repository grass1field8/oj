//
//  main.cpp
//  Tree Traversals Again
//
//  Created by 黄佳睿 on 8/9/15.
//  Copyright (c) 2015 黄佳睿. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string.h>
using namespace std;
string in;
int n;
int N;
int l[31],r[31];
int realroot = 0;
stack<int> s;

void posorder(int root){
    
    if (l[root] != 0) {
        posorder(l[root]);
    }
    if (r[root] != 0) {
        posorder(r[root]);
    }
    cout<<root;
    if (root != realroot) {
        cout<<" ";
    }

}
int main(int argc, const char * argv[]) {
    freopen("/Users/hjr/Desktop/test/in", "r", stdin);
    freopen("/Users/hjr/Desktop/test/out", "w", stdout);
    cin>>N;
    int ct = N;
    int flag;//-1 none, 0 push, 1 pop
    flag = -1;
    int root = -1;
    
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
    while (ct != 0) {
        cin>>in;

        if (in == "Push") {
            cin>>n;
            s.push(n);
            if (flag == -1) {
                root = n;
                realroot = n;
            }
            else if(flag == 0){
                l[root] = n;
                root = n;
            }
            else{
                r[root] = n;
                root = n;
            }
            flag = 0;
        }
        else{
            root = s.top();
            s.pop();
            flag = 1;
            ct--;
        }
    }
    
    posorder(realroot);
    
    return 0;
}
