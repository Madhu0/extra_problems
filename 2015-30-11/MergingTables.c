#include<stdio.h>

struct testcases{
	int n1, n2, r, out;
}cases[] = {
	{ 3, 5, 5, 10 },
	{ 6, 9, 10, 42 }, 
	{ 4, 8, 9, 36 }, 
	{ 4, 10, 12, 40 }, 
	{2, 11, 5, 10}, 
	{ 12, 18, 8, 72 }
};

int gcd(int x, int y){
	if (y == 0)
		return x;
	else
		return gcd(y, x%y);
}

int merger(int n1, int n2, int r){
	int div, nums,com_series[100],i,a,b,rem=0;
	div = gcd(n1, n2);
	if (div == n1 || div == n2){
		return r*div;
	}
	nums = (n1 + n2 - 2*div ) / div;
	a = n1;
	b = n2;
	for (i = 0; i < nums; i++){
		if (a < b){
			com_series[i] = a;
			a = a + n1;
		}
		else if (a>b){
			com_series[i] = b;
			b = b + n2;
		}
	}
	a = r / (nums+1);
	b = (n1*n2) / div;
	rem = r%(nums+1);
	if (rem != 0)
		return (a*b) + com_series[r%nums - 1];
	else if (rem == 0)
		return a*b;
}

int main(){
	int i;
	for (i = 0; i < 6; i++){
		if (merger(cases[i].n1, cases[i].n2, cases[i].r) == cases[i].out)
			printf("PASS\n");
		else
			printf("FAIL\n");
	}
	getchar();
}