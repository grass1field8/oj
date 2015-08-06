//
//  main.cpp
//  bd_query
//
//  Created by 黄佳睿 on 15/5/30.
//  Copyright (c) 2015年 黄佳睿. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
typedef struct node{
    int data;
    struct node *next;
}
node;
int T, ca;
char cmd[10];
int num;
int head,rear;
node *mid;
node *ar[100000];

node *list = NULL;
node *tmp, *del,*p,*q;



int main(int argc, const char * argv[]) {
    //freopen("/Users/hjr/Desktop/test/in", "r", stdin);
    //freopen("/Users/hjr/Desktop/test/out", "w", stdout);
    ca=1;
    
    while (!cin.eof()) {
        scanf("%d",&T);
        printf("Case #%d:\n", ca);
        
        head = 0;
        rear = 0;
        mid = NULL;
        tmp = list;
        while (tmp != NULL) {
            del = tmp;
            tmp = tmp->next;
            free(del);
        }
        list = NULL;
        
        
        while ((T--) != 0) {
            scanf("%s", cmd);
            if (strcmp(cmd, "query") == 0) {
                
                
            }
            else if(strcmp(cmd, "in") == 0){
                scanf("%d",&num);
                tmp = new node;
                tmp->data = num;
                p = list;
                if (p==NULL) {
                    list = tmp;
                    mid = tmp;
                }
                else{
                    q=NULL;
                    while (p!=NULL) {
                        if (p->data < tmp->data) {
                            q=p;
                        }
                        else
                            break;
                    }
                    if(q == NULL){
                        tmp->next = list;
                        list = tmp;
                    }
                    else{
                        tmp->next = q->next;
                        q->next = tmp;
                    }
                }
                
                
                
                
                ar[rear] = tmp;
                rear++;
            }
            else if(strcmp(cmd, "out") == 0){
                head ++;
                
            }
        }
        
        
        
        
        
        ca++;
    }
    return 0;
}
