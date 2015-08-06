#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int node[26][26],deg_in[26],deg_out[26];
int visit[26];
char temp_word[1001];
int dfs(int head){
	int i,num=1;
	for(i=0;i<26;i++)
		if(node[head][i] && !visit[i]){
			visit[i]=1;
			num+=dfs(i);
		}
	return num;	
}
int main(void){
	int T,repeat,N,i,j;
	int head,rear,wrong,num;
	scanf("%d",&T);
	for(repeat=1;repeat<=T;repeat++){
		scanf("%d",&N);
		memset(node,0,sizeof(node));
		memset(deg_in,0,sizeof(deg_in));
		memset(deg_out,0,sizeof(deg_out));
		memset(visit,0,sizeof(visit));
		for(i=0;i<N;i++){
			scanf("%s",temp_word);
			head=temp_word[0]-'a';
			rear=temp_word[strlen(temp_word)-1]-'a';
			node[head][rear]+=1;
			//printf("temp: %s %d %d\n",temp_word,head,rear);
		}
		for(i=0;i<26;i++)
			for(j=0;j<26;j++){
				deg_out[i]+=node[i][j];
				deg_in[j]+=node[i][j];
			}
		for(i=0;i<26;i++)
			if(!deg_in[i] && deg_out[i])
				break;
		if(i >= 26)
			for(i=0;i<26;i++)
				if(deg_out[i])
					break;
		head=i;
		num=0;		
		for(i=0;i<26;i++)
			if(deg_in[i] || deg_out[i])
				num++;
		if(num != dfs(head)){
			//printf("not connected!\n");
			printf("The door cannot be opened.\n");
			continue;
		}
		wrong=0;
		for(i=0;i<26;i++)
			if(deg_in[i] != deg_out[i])
				wrong++;
		if(wrong > 2){
			printf("The door cannot be opened.\n");
			continue;
		}			
		printf("Ordering is possible.\n");
	}
	return 0;
}
