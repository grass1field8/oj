#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void){
	char input[200],sum[200],temp[200];
	int s,i,t,ct,num;
	memset(sum,0,sizeof(sum));
	sum[0]='\0';
	for(;;){
		scanf("%s",input);
		if(input[0]=='0' && strlen(input)==1){
			if(strlen(sum)==0){
				printf("0");
				break;
			}
			printf("%s",sum);
			break;
		}
		s=strlen(sum)-1;
		i=strlen(input)-1;
		t=s;
		if(s<i)
			t=i;
		temp[t+1]='\0';
		ct=0;
		while(s>=0 && i>=0){
			num=sum[s]-'0'+input[i]-'0'+ct;
			temp[t]=num%10+'0';
			ct=num/10;
			s--;
			t--;
			i--;
		}
		if(s>=0)
			while(s>=0){
				num=sum[s]-'0'+ct;
				temp[t]=num%10+'0';
				ct=num/10;
				t--;
				s--;
			}
		else if(i>=0)
			while(i>=0){
				num=input[i]-'0'+ct;
				temp[t]=num%10+'0';
				ct=num/10;
				t--;
				i--;
			}
		strcpy(sum,temp);	
	}
	return 0;
}
