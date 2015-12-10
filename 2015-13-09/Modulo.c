#include<stdio.h>
#include<math.h>
#include<conio.h>
struct testcases{
	unsigned int x, y, a, result;
}cases[] = {
	{4,2,7,2},
	{32,5,17,2},
	{61,7,21,19},
	{121,12,41,37}
};
int modulo(int x, int y, int a){
	int r,i,mod,temp,res=1;
	mod = x%a;
	r = y;
	temp = r % 2;
	if (temp == 1)
		res *= mod;
	r = r / 2;
	while (r){
		temp = r % 2;
		mod = (mod*mod)%a;
		if (temp == 1){
			res *= mod;
		}
		r = r / 2;
	}
	return res%a;
}
void test(no_cases){
	int i;
	for (i = 0; i < no_cases; i++){
		if (modulo(cases[i].x, cases[i].y, cases[i].a) == cases[i].result)
			printf("PASS\n");
		else
			printf("FAIL\n");
	}
}
int main(){
	test(4);
	getchar();
}