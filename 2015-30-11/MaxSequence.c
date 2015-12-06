#include<stdio.h>
struct testcases{
	int a[100], len, index1, index2,sum;
}cases[] = {
	{ { -1, -2, -3, 1, 2, 3, 4, 5, -1, 9, -5, 8 }, 12, 3, 11,26 },
	{ { 1, 2, 3, -1, 9, -3, -34, 9, 10, 2 }, 10, 7, 9 ,21},
	{ { 1, 2, 34, 5, 67, 9, 0, 1, 2, 3 }, 10, 0, 9 ,124},
	{ { -1, -2, -3, -4, 0, -6, -4, -3 }, 8, 4, 4 ,0},
	{ { -90, -80, -70, -50, -55, -23, -99, -87, -1, -3 }, 10, 8, 8,-1},
	{ { 0, -1, -2, -3, -4, -5, -6, -7, -8, -9 }, 10, 0, 0 ,0},
	{ { -1, -2, -3, 4, 5, -6, -7, 8, 9 }, 9, 7, 8 ,17}
};
int *maxSubArraySum(int *a, int size)
{
	int max1 = 0, max2 = 0;
	static int arr[3] = { 0, -1,0 };
	int i, j = 0, start = 0, end = -1; 
	for (i = 0; i < size; i++)
	{
		max1 = max1 + a[i];
		if (max1 < 0){
			max1 = 0;
			j = i + 1;
		}
		if (max2 < max1){
			max2 = max1;
			start = j;
			end = i;
		}
	}
	if (start <= end&&start>=0 && end>=0){
		arr[0] = start;
		arr[1] = end;
		arr[2] = max2;
	}
	else{
		int max = a[0];
		arr[0] = 0;
		arr[1] = 0;
		for (i = 1; i < size; i++){
			if (max < a[i]){
				max = a[i];
				arr[0] = i;
				arr[1] = i;
			}
		}
		arr[2] = max;
	}
	return arr;
}
void test(int no_cases){
	int i, *ar;
	for (i = 0; i < no_cases; i++){
		ar = maxSubArraySum(cases[i].a, cases[i].len);
		//printf("%d %d", cases[i].index1, cases[i].index2);
		//printf("%d %d", ar[0], ar[1]);
		if ((ar[0] == cases[i].index1)&&(ar[1] == cases[i].index2)&&(ar[2]==cases[i].sum))
			printf("PASS\n");
		else
			printf("FAIL\n");
	}
}
int main(){
	test(7);
	getchar();
}