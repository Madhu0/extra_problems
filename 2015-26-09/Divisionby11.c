#include<stdio.h>
struct testcases{
	char p[10000];
	int rep;
	int ans;
}cases[] = {
	{ "123", 2, 1 },
	{ "123", 3, 0 },
	{ "1234567891234561231537814236172528276", 2, 1 },
	{ "4567234", 2, 1 },
	{ "1111", 10, 1 },
	{ "011",1,1 },
	{ "2",2,1 }
};
int division11(char *p, int rep){
	int i=0, evensum=0, oddsum=0,length,a,b;
	while (p[i] != '\0'){
		i++;
	}
	length = i;
	for (i = 0; i < length; i = i + 2)
		oddsum += p[i] - '0';
	for (i = 1; i < length; i = i + 2)
		evensum += p[i]-'0';
	if (length % 2 == 0){
		if ((oddsum - evensum)%11==0)
			return 1;
		else
			return 0;
	}
	else{
		if (rep % 2 == 0)
			return 1;
		else{
			a = oddsum;
			b = evensum;
			evensum = b*((rep + 1) / 2) + a*((rep - 1) / 2);
			oddsum = a*((rep + 1) / 2) + b*((rep - 1) / 2);
			if( (oddsum - evensum) % 11 == 0)
				return 1;
			else
				return 0;
		}
	}
}
void test(no_cases){
	int i;
	for (i = 0; i < no_cases; i++){
		if ((division11(cases[i].p, cases[i].rep) == cases[i].ans))
			printf("PASS\n");
		else
			printf("FAIL\n");
	}
}
int main(){
	test(7);
	getchar();
	return 0;
}