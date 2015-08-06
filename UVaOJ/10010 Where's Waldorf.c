#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
char grid[50][50];
char word[20],up[20],down[20],left[20],right[20],ur[20],ul[20],dl[20],dr[20];\
int test(int i,int j,int m,int n,int len){
	int a,b,k;
	a=i;
	b=j;
	k=0;      //up
	while(a>=0 && k<len){
		up[k]=grid[a][b];
		a--;
		k++;
	}
	up[k]='\0';
	a=i;b=j;
	k=0;             //down
	while(a<m && k<len){
		down[k]=grid[a][b];
		k++;
		a++;
	}
	down[k]='\0';
	a=i;b=j;
	k=0;                   //right
	while(b<n && k<len){
		right[k]=grid[a][b];
		k++;
		b++;
	}
	right[k]='\0';
	a=i;b=j;
	k=0;                 //left
	while(b>=0 && k<len){
		left[k]=grid[a][b];
		k++;
		b--;
	}
	left[k]='\0';
	a=i;b=j;
	k=0;                 //ur
	while(b<n && a>=0 && k<len){
		ur[k]=grid[a][b];
		k++;
		a--;
		b++;
	}
	ur[k]='\0';
	a=i;b=j;
	k=0;                 //ul
	while(b>=0 && a>=0 && k<len){
		ul[k]=grid[a][b];
		k++;
		a--;
		b--;
	}
	ul[k]='\0';
	a=i;b=j;
	k=0;                 //dr
	while(b<n && a<m && k<len){
		dr[k]=grid[a][b];
		k++;
		a++;
		b++;
	}
	dr[k]='\0';
	a=i;b=j;
	k=0;                 //dl
	while(b>=0 && a<m && k<len){
		dl[k]=grid[a][b];
		k++;
		a++;
		b--;
	}
	dl[k]='\0';
	return 0;
}
int main(void){
	int m,n,repeat,rp,k;
	int i,j;
	scanf("%d",&repeat);
	for(rp=1;rp<=repeat;rp++){
		scanf("%d%d",&m,&n);
		getchar();
		for(i=0;i<m;i++){
			for(j=0;j<n;j++)
				grid[i][j]=tolower(getchar());
			getchar();
		}
		/*for(i=0;i<m;i++){
			for(j=0;j<n;j++)
				printf("%c",grid[i][j]);
			printf("\n");
		}*/
		scanf("%d",&k);
		while(k!=0){
			int a=0,b=0,flag=0;
			k--;
			scanf("%s",word);
			for(i=0;i<m;i++){
				for(j=0;j<n;j++){
					int q;
					test(i,j,m,n,strlen(word));
					for(q=0;q<strlen(word);q++)
						word[q]=tolower(word[q]);
					if(!(strcmp(word,up) && strcmp(word,down) && strcmp(word,left) && strcmp(word,right)  && strcmp(word,ul) && strcmp(word,ur) && strcmp(word,dl) && strcmp(word,dr))){
						a=i;
						b=j;
						flag=1;
						break;
					}

				}
				if(flag==1)
					break;
			}
			printf("%d %d\n",a+1,b+1);		
		}
	}
	/*system("pause");*/
	return 0;
}
