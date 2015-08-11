//
//  main.cpp
//  Reversing Linked List
//
//  Created by 黄佳睿 on 8/9/15.
//  Copyright (c) 2015 黄佳睿. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;
typedef struct node{
    int data;
    int next;
}node;
node add[100000];
int n,k;
int head;
int rev(int start,int len, int *news){
    int p1,p2,p3 = -1;
    p1 = start;
    p2 = add[start].next;
    while (len != 1) {
        p3 = add[p2].next;
        //cout<<"loop"<<p1<<" "<<p2<<" "<<p3<<endl;
        add[p2].next = p1;
        p1 = p2;
        p2 = p3;
        len--;
    }
    add[start].next = p3;
    *news = start;
    return p1;
}
int main(int argc, const char * argv[]) {
    memset(add, -1, sizeof(add));
    freopen("/Users/hjr/Desktop/test/in", "r", stdin);
    freopen("/Users/hjr/Desktop/test/out", "w", stdout);
    cin>>head>>n>>k;
    int travel;
    int tadd, tdata,tnext;
    for (int i = 0; i<n; i++) {
        cin>>tadd>>tdata>>tnext;
        add[tadd].data = tdata;
        add[tadd].next = tnext;
    }
    
    
    
    int ct;
    ct = n/k;
    int headout;
    headout = head;
    int start;
    int news;
    start = head;
    int flag = 0;
    int rear = -1;
    while (ct != 0) {
        if (flag == 0) {
            headout = rev(start, k, &news);
            flag = 1;
            rear = news;
        }
        else{
            //cout<<"rear is: "<<rear<<endl;
            add[rear].next = rev(start, k, &news);
            rear = news;
        }
        start = add[news].next;
        //cout<<"news: "<<news<<endl;
        ct--;
    }
    
    travel = headout;
    while (travel >= 0) {
        if(add[travel].next >= 0)
            printf("%05d %d %05d\n",travel,add[travel].data, add[travel].next);
        else
            printf("%05d %d %d\n",travel,add[travel].data, add[travel].next);
        travel = add[travel].next;
    }
    return 0;
}
