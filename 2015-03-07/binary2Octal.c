#include<stdio.h>

struct testcases{
	unsigned int binary[32], length, res;
}cases[] = {
	{ { 1, 1, 1, 0, 1, 0 }, 6, 72 },
	{ { 1, 0, 1, 0, 1, 0, 1, 0 }, 8, 252 },
	{ { 1, 1, 1, 0, 1, 0, 1, 1, 0 }, 9, 726 },
	{ { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, 27, 777777777 },
	{ {1,1,0,1,1,0,1},7,155 },
	{ { 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1 }, 13, 11561 }
};
int power(int a, int b){
	int i,pro=1;
	for (i = 0; i < b; i++)
		pro = pro*a;
	return pro;
}
int octal(int *arr, int l){
	l = l - 1;
	int pro = 0, i = 0;
	while ((l-i) >= 0 && i < 3) {
		if (arr[l-i]!=0)
			pro = pro+arr[l-i]*power(2, i);
		i++;
	}
	return pro;
}
int converter(int *arr, int len){
	int i = 0, pro = 0;;
	while (len >0){
		pro = pro + octal(arr, len )*power(10, i);
		i++;
		len = len - 3 ;
	}
	//printf("%d ", pro);
	return pro;
}
void test(no_cases){
	int i;
	for (i = 0; i < no_cases; i++){
		if (converter(cases[i].binary, cases[i].length) == cases[i].res){
			//printf("%d ", cases[i].res);
			printf("PASS\n");
		}
		else
			printf("FAIL\n");
	}
}
int main(){
	test(6);
	getchar();
}