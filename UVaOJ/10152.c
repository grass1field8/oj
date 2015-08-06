#include <stdio.h>
#include <string.h>
int main(void){
	char org[200][20],std[200][20];
	int work[201];
	work[200]=-1;
	int K,N,i,j,temp,max;
	scanf("%d",&K);
	while(K--){
		scanf("%d",&N);
		getchar();
		for(i=0;i<N;i++)
			gets(org[i]);
		for(i=0;i<N;i++)
			gets(std[i]);
		for(i=0;i<N;i++)
			for(j=0;i<N;j++)
				if(!strcmp(org[i],std[j])){
					work[i]=j;
					break;
				}
		for(;;){
			max=200;
			for(i=0;i<N;i++)
				for(j=0;j<i;j++)
					if(work[j] > work[i])
						if(work[i] > work[max])
							max=i;
			if(max == 200)
				break;
			printf("%s\n",std[max]);
			temp=work[max];
			for(i=max;i>0;i--)
				work[i]=work[i-1];
			work[0]=temp;
		}
	}
	return 0;
}