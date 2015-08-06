//
//  main.cpp
//  chess
//
//  Created by 黄佳睿 on 15/5/23.
//  Copyright (c) 2015年 黄佳睿. All rights reserved.
//

#include <iostream>
#include <math.h>
int board[1001][1001];
using namespace std;
int n,m,k;
void jump(int i,int j, int prei,int  prej) {
    if(i <= 0 || i > n || j <= 0 || j > m)return;
    if(board[prei][prej] + 1 >= board[i][j] && board[i][j] > 0)
        return;
    board[i][j] = board[prei][prej] + 1;
    if (board[i][j] > k) {
        return;
    }
    jump(i+1, j+2, i, j);
    jump(i+1, j-2, i, j);
    jump(i-1, j+2, i, j);
    jump(i-1, j-2, i, j);
    jump(i+2, j+1, i, j);
    jump(i+2, j-1, i, j);
    jump(i-2, j+1, i, j);
    jump(i-2, j-1, i, j);
}
int main(int argc, const char * argv[]) {
    //freopen("/Users/hjr/Desktop/test/in", "r", stdin);
    //freopen("/Users/hjr/Desktop/test/out", "w", stdout);
    int T;
    cin>>T;
    for (int q=1; q<=T; q++) {
        cout<<"Case #"<<q<<":"<<endl;
        cin>>n>>m>>k;
        int kx,ky,ntx,nty;
        cin>>kx>>ky>>ntx>>nty;
        if (abs(kx-ntx)/3 > k ||abs(ky-nty)/3 > k) {
            cout<<"OH,NO!"<<endl;
            continue;
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                board[i][j] = 0;
            }
        }
        int min=k+2;
        jump(ntx, nty, ntx, nty);
        for (int i = kx-k>0?kx-k:1 ; i<=kx+k && i<=n; i++) {
            for (int j=ky-k?ky-k:1; j<=ky+k && j<=m; j++) {
                //cout<<i<<" "<<j<<" "<<board[i][j]<<endl;
                if (board[i][j] != 0 && board[i][j]<=k+1 && (abs(kx-i)<=board[i][j]-1&&abs(ky-j)<=board[i][j]-1)) {
                    min=board[i][j];
                }
            }
        }
        if (min<=k+1) {
            cout<<min-1<<endl;
        }
        else
            cout<<"OH,NO!"<<endl;
    }
    return 0;
}
