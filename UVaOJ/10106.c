#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[260],b[260],muti[600];
char aa[260],bb[260];
int main(void){
	int la,lb,i,j,k;
	while(scanf("%s%s",aa,bb) != EOF){
		memset(muti,0,sizeof(muti));
		la=strlen(aa);
		lb=strlen(bb);
		if(la==1 && aa[0]=='0' || lb==1 && bb[0]=='0'){
			printf("0\n");
			continue;
		}
		for(i=la-1;i>=0;i--)
			a[la-1-i]=aa[i]-'0';
		for(i=lb-1;i>=0;i--)
			b[lb-1-i]=bb[i]-'0';
		for(i=0;i<la;i++)
			for(j=0;j<lb;j++){
				k=i+j;
				muti[k]+=a[i]*b[j];
				while(muti[k]>=10){
					muti[k+1]+=muti[k]/10;
					muti[k]%=10;
					k++;
				}
			}
		k=599;	
		while(k>=0){
			if(muti[k])
				break;
			k--;
		}
		while(k>=0){
			printf("%d",muti[k]);
			k--;
		}
		printf("\n");
	}
	return 0;
}