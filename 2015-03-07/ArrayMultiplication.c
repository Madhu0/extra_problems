#include<stdio.h>

struct testcases{
	int a[10], b[5], res[15];
}cases[] = {
	{ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 10 }, { 0, 0, 0, 0, 10 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100 } },
	{ { 0, 0, 0, 0, 0, 0, 0, 0, 10, 10 }, { 0, 0, 0, 10, 10 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 200, 100 } },
	{ { 456, 123, 12, 3, 1, 2, 12, 4, 5, 123456 }, { 0, 2, 0, 5, 4 }, { 0, 0, 912, 246, 2304, 2445, 554, 67, 41, 22, 78, 246980, 41, 617300, 493824 } }
};
int compare(int *a, int *b){
	int i;
	for (i = 0; i < 15; i++){
		if (a[i] != b[i])
			return 0;
	}
	return 1;

}
void toBinary(int x, int *arr, int strt){
	int i=0;
	if (x == 0){
		while (i < 32){
			arr[strt++] = 0;
			i++;
		}
	}
	else{
		while (x != 0){
			arr[strt++] = x % 2;
			x = x / 2;
			i++;
		}
		while (i < 32){
			arr[strt++] = 0;
			i++;
		}
	}
}

int toDecimal(int *arr, int ind){
	int i = 0, sum = 0, n = 1;
	while (i < 32){
		sum += arr[ind++] * n;
		n = n * 2;
		i++;
	}
	return sum;
}
void add(int *r1, int *a1, int len, int sp){
	int i, flag = 0;
	for (i = 0; i <len ; i++){
		if (r1[i + sp] && a1[i]){
			if (flag){
				r1[i + sp] = 1;
				flag = 1;
			}
			else{
				r1[i + sp] = 0;
				flag = 1;
			}
		}
		else if (r1[i + sp] || a1[i]){
			if (flag){
				r1[i + sp] = 0;
				flag = 1;
			}
			else{
				r1[i + sp] = 1;
				flag = 0;
			}
		}
		else{
			r1[i + sp] = flag;
			flag = 0;
		}
	}
	if (flag == 1)
		r1[i + sp] = 1;
}
void multiplier(int *arr1, int *arr2,int *res){
	int i, num1_bin[320], num2_bin[160], result[480] = { 0 };
	for (i = 9; i >= 0; i--)
		toBinary(arr1[i], num1_bin, (9-i) * 32);
	for (i =4; i>=0 ; i--)
		toBinary(arr2[i], num2_bin, (4-i) * 32);
	for (i = 0; i<160 ; i++) {
		if (num2_bin[i] == 1)
			add(result, num1_bin, 320, i);
	}
	for (i = 0; i < 15; i++){
		res[i] = toDecimal(result, 448 - (i * 32));
		printf("%d ", res[i]);
	}
}
void test(no_cases){
	int i, result[15];
	for (i = 0; i < no_cases; i++){
		multiplier(cases[i].a, cases[i].b, result);
		//printf("%d", result[14]);
		if (compare(result, cases[i].res))
			printf("PASS\n");
		else
			printf("FAIL\n");
	}
}
int main(){
	test(3);
	getchar();
}