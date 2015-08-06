#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
	char name[76];
	int num;
}node;
node *list[2000];
int cmp(const void *a,const void *b){
	return strcmp(((node *)a)->name,((node *)b)->name);
}
int main(void){
	node *p;
	char rub[76];
	int i;
	char temp[76];
	int tot=0;
	int repeat,N;
	scanf("%d",&N);
	for(repeat=1;repeat<=N;repeat++){
		scanf("%s",temp);
		printf("temp:%s\n",temp);
		gets(rub);
		printf("rub:%s\n",rub);
		for(i=0;i<tot;i++)
			if(strcmp(list[i]->name,temp) == 0){
				list[i]->num++;
				break;
			}
		if(i>=tot){
			p=(node *)malloc(sizeof(node));
			strcpy(p->name,temp);
			p->num=1;
			list[tot]=p;
			tot++;
		}
	}
    qsort(list,tot,sizeof(node *),cmp);
    for(i=0;i<tot;i++)
    	printf("%s %d\n",list[i]->name,list[i]->num);
    return 0;
}
