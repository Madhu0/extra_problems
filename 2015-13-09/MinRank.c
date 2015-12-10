#include<stdio.h>
#include<stdlib.h>
struct testcases{
	int number, minRank;
}cases[] = {
	{ 213, 2 },
	{ 4213, 20 },
	{ 324561, 273 },
	{2343,1},
	{433122,177},
	{33333,0},
	{12456,0},
	{1221,2}
};
int fact(int n){
	if (n <= 0)
		return 1;
	else
		return n*fact(n - 1);
}
int *minFinder(int *arr, int p){
	int i, count = 0,product=1,*dup_count;
	dup_count = (int *)malloc(sizeof(int)* 11);
	for (i = 0; i < 11; i++)
		dup_count[i] = 0;
	for (i = p - 1; i >= 0; i--){
		if (arr[i] <= arr[p]){
			if (dup_count[arr[i]] < 1)
				count++;
			dup_count[arr[i]] += 1;
		}
	}
	for (i = 0; i < 10; i++){
		if (dup_count[i] != 0)
			product *= fact(dup_count[i]);
		//dup_count[i] = 0;
	}
	//dup_count[10] = count;
	dup_count[10] = product;
	return dup_count;
}
int minRankFun(int num){
	int i = 0, j, a[100], count = 0, pos = 0,*dups,temp=0;
	while (num){
		a[i] = num % 10;
		i++;
		num = num / 10;
	}
	for (j = i - 1; j > 0; j--){
		dups = minFinder(a, j);
		for (i = 0; i < 10; i++){
			if (dups[i] != 0&&i!=a[j])
				temp=temp+ fact(j)*fact(dups[i]) / dups[10];
		}
		temp =temp/ fact(dups[a[j]]+1);
		pos += temp;
		temp = 0;
	}
	//printf("%d", pos);
	return pos;
}
void test(int no_cases){
	int i;
	for (i = 0; i < no_cases; i++){
		if (minRankFun(cases[i].number) == cases[i].minRank)
			printf("PASS\n");
		else
			printf("FAIL\n");
	}
}
int main(){
	test(8);
	getchar();
}