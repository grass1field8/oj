#include <stdio.h>
int main(void){
	long long op1,op2,result;
	char oper;
	while(scanf("%lld%c%lld",&op1,&oper,&op2) != EOF){
		if(op1!=0 && (op1>>32)!=0)
			printf("first number too big\n");
		else if(op2!=0 && (op2>>32)!=0)
			printf("second number too big\n");
		printf("%lld\n",op1);
		if(oper == '+')
			result=op1+op2;
		else if(oper == '*')
			result=op1*op2;
		if(result!=0 && (result>>32)!=0)
			printf("result too big\n");
	}
	return 0;
}