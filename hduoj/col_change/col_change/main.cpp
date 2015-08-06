//
//  main.cpp
//  col_change
//
//  Created by 黄佳睿 on 15/5/23.
//  Copyright (c) 2015年 黄佳睿. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
char ar[100001];
char tmp[100001];
int main(int argc, const char * argv[]) {
    //freopen("/Users/hjr/Desktop/test/in", "r", stdin);
    //freopen("/Users/hjr/Desktop/test/out", "w", stdout);
    int N;
    int k;
    int len;
    int row_max,rem;
    string s;
    cin>>N;
    for (int j = 1; j<=N; j++) {
        cout<<"Case #"<<j<<":"<<endl;
        cin.ignore();
        cin.getline(tmp, 100001);
        cin>>k;
        len = (int)strlen(tmp);
        //cout<<"test"<<len<<" "<<k<<endl;
        ar[len]='\0';
        row_max = len / k;
        rem = len % k;
        if (rem != 0) {
            row_max++;
        }
        int row=0,col=0;
        //cout<<"row_max"<<row_max<<endl<<"rem"<<rem<<endl;
        for (int i = 0; i<len; i++) {
            ar[k*row + col] = tmp[i];
            //cout<<"row and col"<<row<<" "<<col<<" set"<<tmp[i]<<endl;
            row++;
            if (row>=row_max) {
                row = 0;
                col++;
                if (col == rem) {
                    row_max--;
                    //cout<<"row_max changed"<<endl;
                }
            }
            
        }
        printf("%s\n", ar);
        
        
        
    }
    return 0;
}
