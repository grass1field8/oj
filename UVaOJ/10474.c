#include <stdio.h>
#include <string.h>
int rank[10001],num[10001];
int main(void){
	int in,out,i,temp;
	for(;;){
		 scanf("%d%d",&in,&out);
		 if(in==0 && out==0)
		 	break;
		 memset(rank,0,sizeof(rank));
		 memset(num,0,sizeof(num));
		 printf("CASE# 1:\n");
		 while(in){
		 	scanf("%d",&temp);
		 	num[temp]++;
		 	if(num[temp]==1){
		 		for(i=temp-1;i>0;i--)
		 			if(num[i]){
		 				rank[temp]=rank[i]+num[i];
		 				break;
		 			}
		 		if(i<=0)
		 			rank[temp]=1;
		 	}	
		 	for(i=temp+1;i<=10000;i++)
		 		if(num[i])
		 			rank[i]++;		
		 	in--;
		 }
		 while(out){
		 	scanf("%d",&temp);
		 	if(num[temp])
		 		printf("%d found at %d\n",temp,rank[temp]);
		 	else
		 		printf("%d not found\n",temp);
		 	out--;
		 }	 
	}
	return 0;
}