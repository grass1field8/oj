#include <stdio.h>
int c,v,k,ct_v[5],ct_c[21];
char trans_v[]={'A','U','E','O','I'};
char trans_c[]={'J','S','B','K','T','C','L','D','M','V','N','W','F','X','G','P','Y','H','Q','Z','R'};
void intial(void){
	int i;
	c=0;
	v=0;
	k=0;
	for(i=0;i<5;i++)
		ct_v[i]=21;
	for(i=0;i<21;i++)
		ct_c[i]=5;
}
int main(void){
	int N,n,rpt,len;
	char out[220];
	scanf("%d",&N);
	for(rpt=1;rpt<=N;rpt++){
		intial();
		scanf("%d",&len);
		while(k < len){
			if(k%2 == 0){
				if(ct_v[v] <= 0)
					v++;
				out[k]=trans_v[v];
				ct_v[v]--;
			}
			else{
				if(ct_c[c] <= 0)
					c++;
				out[k]=trans_c[c];
				ct_c[c]--;
			}
			k++;
		}
		out[k]='\0';
		printf("Case %d: %s\n",rpt,out);
	}
	return 0;
}