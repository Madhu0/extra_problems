#include<stdio.h>
struct testcasess{
	int x, y, z;
}cases[] = {
	{23,2,46},
	{12,12,144},
	{-45,90,-4050},
	{-89,-67,5963},
	{9,-7,-63},
	{-19,0,0}
};
void toBinary(int a, int b,int *a_array,int *b_array,int *alen,int *blen){
	int i = 0, j = 0;
	while (a&&b){
		a_array[i] = a % 2;
		a = a / 2;
		b_array[i] = b % 2;
		b = b / 2;
		i++;
	}
	j = i;
	if (a != 0){
		while (a){
			a_array[i] = a % 2;
			a = a / 2;
			i++;
		}
	}
	*alen = i;
	if (b != 0){
		while (b){
			b_array[j] = b % 2;
			b = b / 2;
			j++;
		}
	}
	*blen = j;
}
int add(int *r1, int *a1, int len, int sp){
	int i, flag=0;
	for (i = 0; i < len; i++){
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
	if (flag == 1){
		r1[i + sp] = 1;
		return i + sp + 1;
	}
	else
		return i + sp;
}
int mul(int x, int y){
	int a_array[35] = { 0 }, b_array[35] = { 0 }, result[35] = { 0 },n=1;
	int a_len, b_len,i,r_len,res=0,sign=0;
	if (x < 0 && y < 0)
		sign = 0;
	else if (x < 0 || y < 0)
		sign = 1;
	if (x < 0)
		x *= -1;
	if (y < 0)
		y *= -1;
	toBinary(x, y, a_array, b_array,&a_len,&b_len);
	r_len = a_len;
	for (i = 0; i < b_len; i++){
		if (b_array[i] == 1)
			r_len=add(result, a_array, a_len, i);
	}
	for (i = 0; i < r_len; i++){
		res += result[i] * n;
		n = n * 2;
	}
	if (sign == 1)
		res *= -1;
	//printf("%d", res);
	return res;
}
void test(no_cases){
	int i;
	for (i = 0; i < no_cases; i++){
		if (mul(cases[i].x, cases[i].y) == cases[i].z)
			printf("PASS\n");
		else
			printf("FAIL\n");
	}
}
int main(){
	test(6);
	getchar();
}