#include <stdio.h>
#include <string.h>
int main(void){
	char mirror[35],word[30];
	int i,fr,fm;
	memset(mirror,0,sizeof(mirror));
	mirror[9]='A';
	mirror[9+'E'-'A']='3';
	mirror[9+'H'-'A']='H';
	mirror[9+'I'-'A']='I';
	mirror[9+'J'-'A']='L';
	mirror[9+'L'-'A']='J';
	mirror[9+'M'-'A']='M';
	mirror[9+'O'-'A']='O';
	mirror[9+'S'-'A']='2';
	mirror[9+'T'-'A']='T';
	mirror[9+'U'-'A']='U';
	mirror[9+'V'-'A']='V';
	mirror[9+'W'-'A']='W';
	mirror[9+'X'-'A']='X';
	mirror[9+'Y'-'A']='Y';
	mirror[9+'Z'-'A']='5';
	mirror[0]='1';
	mirror[0-'1'+'2']='S';
	mirror[0-'1'+'3']='E';
	mirror[0-'1'+'5']='Z';
	mirror[0-'1'+'8']='8';
	while(scanf("%s",word) != EOF){
		int len,x;
		char mirr;
		fr=1;
		fm=1;
		len=strlen(word);
		for(i=0;i<=(len+1)/2-1;i++){
			if(word[i]>='1' && word[i]<='9')
				mirr=mirror[word[i]-'1'];
			else if(word[i]>='A' && word[i]<='Z')
				mirr=mirror[word[i]-'A'+9];
			if(word[len-1-i] != mirr)
				fm=0;
			if(word[len-1-i] != word[i])
				fr=0;
			if(fm==0 && fr==0)
				break;						
		}
		if(fm==0 && fr==0)
			printf("%s -- is not a palindrome.\n\n",word);
		else if(fm==0 && fr!=0)
			printf("%s -- is a regular palindrome.\n\n",word);
		else if(fm!=0 && fr==0)
			printf("%s -- is a mirrored string.\n\n",word);
		else
			printf("%s -- is a mirrored palindrome.\n\n",word);
	}
	return 0;
}