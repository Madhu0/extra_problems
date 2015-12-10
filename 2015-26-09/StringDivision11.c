#include<stdio.h>
struct testcases{
	char in[1000];
	int ans;
}cases[] = {
	{ "12115456845698746546523", 0 },
	{ "564879432454587", 0 },
	{ "111111111111", 1 },
	{ "22",1 },
	{ "682",1 },
	{ "451",1 }
};
int adder(char *arr, int s){
	int i,sum=0;
	for (i = s; arr[i] != '\0'; i = i + 2)
		sum += arr[i] - '0';
	return sum;
}
int divisability1(char *arr){
	int oddsum, evensum;
	oddsum = adder(arr, 0);
	evensum = adder(arr, 1);
	if (oddsum == evensum)
		return 1;
	else
		return 0;
}
void test(int no_cases){
	int i;
	for (i = 0; i < no_cases; i++){
		if (divisability1(cases[i].in) == cases[i].ans)
			printf("PASS\n");
		else
			printf("FAIL\n");
	}
}
int main(){
	test(6);
	getchar();
}