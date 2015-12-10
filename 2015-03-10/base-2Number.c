#include<stdio.h>
#include<stdlib.h>

struct testcases{
	int dec, base[48],length;
}cases[] = {
	{ 10, { 1,1,1,1,0 } ,5 },
	{ 11, { 1, 1, 1, 1 }, 4 },
	{ 35, {1,1,0,0,1,1,1},7 },
	{ 341, { 1, 0, 1, 0, 1, 0, 1, 0, 1 }, 9 },
	{ 15, { 1, 0, 0, 1, 1 }, 5 },
	{ 40, {1,1,1,1,0,0,0},7 }
};

int compare(int *a, int *b,int l){
	int i;
	for (i = 0; i < l; i++){
		if (a[i] != b[i])
			return 0;
	}
	return 1;	
}

int baseFinder(int num, int *arr){
	int i = 47, temp, count = 0, flag1=0,flag2=0;
	while (num != 0){
		temp = num % 2;
		num = num / 2;
		if (flag1 == 1 && temp == 1 && flag2 == 1){
			arr[i--] = 1;
			flag1 = 1;
		}
		else if (flag1 == 0 && temp == 0){
			arr[i--] = flag2;
			flag2 = 0;
		}
		else if (flag1 == 0 && flag2 == 0){
			arr[i--] = temp;
		}
		else if (flag2 == 0 && temp == 0){
			arr[i--] = flag1;
			flag1 = 0;
		}
		else if (flag1 == 0 && flag2 == 0 && temp == 0)
			arr[i--] = 0;
		else{
			arr[i--] = 0;
			flag1 = 1;
			flag2 = 0;
		}
		if (temp == 1 && count % 2 != 0)
			flag2 = 1;
		count++;
	}
	if (flag1 == 1||flag2==1)
		arr[i--] = 1;
	return i+1;
}

void test(int no_cases){
	int i, arr[48], k;
	for (i = 0; i < no_cases; i++){
		k=baseFinder(cases[i].dec,arr);
		if (compare(arr+k, cases[i].base, cases[i].length))
			printf("PASS\n");
		else
			printf("FAIL\n");
	}
}

int main(){
	test(6);
	getchar();
}