//
//  main.cpp
//  The Largest Generation
//
//  Created by 黄佳睿 on 8/3/15.
//  Copyright (c) 2015 黄佳睿. All rights reserved.
//

#include <iostream>
#include <queue>
#include <stdlib.h>
#include <string.h>
using namespace std;
int max_layer;
int max_num;
int cur_layer;
int cur_num;
struct child{
    int index;
    struct child *next;
};
child *people[101];
queue<int> q1,q2;
queue<int> *cur,*nex,*tmp;
void addchild(int parent,int child){
    struct child *p;
    p = people[parent];
    if (p == NULL) {
        people[parent] = new struct child;
        people[parent]->index = child;
        //cout<<"parent "<<parent<<" add child "<<child<<endl;
        people[parent]->next = NULL;
    }
    else{
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = new struct child;
        p->next->index = child;
        //cout<<"parent "<<parent<<" add child "<<child<<endl;
        p->next->next = NULL;
    }
}
int main(int argc, const char * argv[]) {
    
    //freopen("/Users/hjr/Desktop/test/in", "r", stdin);
    //freopen("/Users/hjr/Desktop/test/out", "w", stdout);
    
    memset(people, 0, sizeof(people));
    
    int M,N,K;
    int parent,child;
    cin>>N>>M;
    while (M != 0) {
        M--;
        cin>>parent>>K;
        while (K != 0) {
            K--;
            cin>>child;
            addchild(parent, child);
        }
    }
    max_layer = 1;
    cur_layer = 1;
    max_num = 1;
    cur = &q1;
    nex = &q2;
    nex->push(1);
    while (!nex->empty()) {
        tmp = cur;
        cur = nex;
        nex = tmp;
        cur_layer++;
        while (!cur->empty() ) {
            parent = cur->front();
            //cout<<"pop parent: "<<parent<<endl; ///////
            cur->pop();
            struct child *p;
            struct child *del;
            p = people[parent];
            while (p != NULL) {
                nex->push(p->index);
                //cout<<"push child: "<<p->index<<endl;///////
                del = p;
                p = p->next;
                delete del;
            }
        }
        if (nex->size() > max_num) {
            max_num = (int)nex->size();
            max_layer = cur_layer;
        }
    }
    cout<<max_num<<" "<<max_layer;
    int test;
    cin>>test;
    return 0;
}
