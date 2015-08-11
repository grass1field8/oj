//
//  main.cpp
//  Forwards on Weibo
//
//  Created by 黄佳睿 on 8/10/15.
//  Copyright (c) 2015 黄佳睿. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
vector<int> user[1001];
int n, l;
int visit[1001];
int dfs(int node, int level){
    int sum = 1;
    if (level == 0) {
        //cout<<"return : 1"<<endl;
        return 1;
    }
    for (int i = 0; i < (int)user[node].size(); i++) {
        if (visit[user[node][i]] == 0) {
            visit[user[node][i]] = 1;
            //cout<<user[node][i]<<endl;
            sum += dfs(user[node][i],level - 1);
        }
        
    }
    //cout<<"return : "<<sum<<endl;
    return sum;
}

int main(int argc, const char * argv[]) {
    freopen("/Users/hjr/Desktop/test/in", "r", stdin);
    freopen("/Users/hjr/Desktop/test/out", "w", stdout);
    cin>>n>>l;
    for (int i = 1; i <= n; i++) {
        int j;
        cin>>j;
        while (j != 0) {
            int follow;
            cin>>follow;
            user[follow].push_back(i);
            j--;
        }
    }
    int query_l;
    cin>>query_l;
    while (query_l != 0) {
        int node;
        cin>>node;
        memset(visit, 0, sizeof(visit));
        visit[node] = 1;
        cout<<dfs(node, l)-1;
        if((--query_l) != 0)
            cout<<endl;
    }
    return 0;
}
