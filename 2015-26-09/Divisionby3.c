#include<stdio.h>
struct testcases{
	char p[10000];
	int rep;
	int ans;
}cases[] = {
	{ "123", 2, 1 },
	{ "123", 4, 1 },
	{ "12345678912345612315378142361725282761", 2, 1 },
	{ "4567234", 2, 0 },
	{ "1111", 10, 0 },
	{ "0111", 100, 1 },
	{ "2", 2, 0 }
};
int division11(char *p, int rep){
	int i = 0, sum = 0;
	if (rep % 3 == 0)
		return 1;
	else{
		while (p[i] != '\0'){
			sum += p[i] - '0';
			i++;
		}
		if (sum % 3 == 0)
			return 1;
		else return 0;
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