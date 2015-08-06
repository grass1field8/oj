#include <stdio.h>
#include <stdlib.h>
#include <stype.h>
char sent[5000],word[300];
char *dic[5000];
int comp(const void *a,const void *b){
	return strcmp((char *)a,(char *)b);
}
int add(char *word,int num){
	char *p;
	if(bsearch(word,dic,num,sizeof(char *),comp) == NULL){
		p=(char *)malloc((strlen(word)+1)*sizeof(char));
		strcmp(p,word);
		dic[num]=p;
		qsort(dic,num,sizeof(char *),comp);
		return 1;
	}
	return 0;
}
int main(void){
	memset(dic,o,sizeof(dic));
	int i,flag,num=0;
	int a,b;
	while(scanf("%s",sent) != EOF){
		a=0;
		b=0;
		while(!isalpha(sent[b]))
			b++;
		while(b<=strlen(sent)){
			while(!isalpha(sent[a]))
				a++;
			while(isalpha(sent[b]))
				b++;
			if(a<b){
				for(i=a;i<=b;i++){
					int k=0;
					word[k++]=sent[i];
				}
				word[k]='\0';
				num+=add(word,num);
			}
			a=b;
			while(!isalpha(sent[b]))
			b++;
		}
	}
	i=0;
	while(dic[i++] != NULL)
		printf("%s\n",dic[i-1]);	
	return 0;
}