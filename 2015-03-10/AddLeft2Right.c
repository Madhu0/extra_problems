#include<stdio.h>
#include<stdlib.h>

struct testcases{
	char num1[101], num2[100], result1[101];
}cases[] = {
	{ "1234", "7894", "9128" },
	{ "146554", "412345", "558899" },
	{ "111111", "111111", "222222" },
	{ "9999", "9999", "19998" },
	{ "12345", "12345", "24690" },
	{ "1234561234", "9999999999", "11234561233" }
};

int compare(char *a, char *b){
	int i;
	for (i = 0; a[i] != '\0'; i++){
		if (a[i] != b[i])
			return 0;
	}
	if (b[i] != '\0')
		return 0;
	else return 1;
}

void set(char *num, int n, int l, int m){
	int i;
	num[l + 1] = n % 10 + '0';
	for (i = l ; i > m + 1; i--)
		num[i] = '0';
	num[m + 1] = num[m + 1] + 1;
}

char * adder(char *num1, char *num2){
	int i = 0, j = -1, temp;
	char next;
	//result = (char *)malloc(sizeof(char)* 101);
	next = num1[0];
	num1[0] = '0';
	while (next != '\0'){
		temp = next + num2[i] - 2 * '0';
		next = num1[i + 1];
		if (temp > 9){
			set(num1, temp, i, j);
			j = i;
		}
		else if (temp < 9){
			num1[i + 1] = temp + '0';
			j = i;
		}
		else
			num1[i + 1] = '9';
		i++;
	}
	num1[i + 1] = '\0';
	if (num1[0] == '0')
		return num1 + 1;
	//printf("%s", result);
	return num1;
}

void test(int no_cases){
	int i;
	char *result;
	for (i = 0; i < no_cases; i++){
		result = adder(cases[i].num1, cases[i].num2);
		if (compare(result, cases[i].result1))
			printf("PASS\n");
		else
			printf("FAIL\n");
	}
}

int main(){
	test(6);
	getchar();
	return 0;
}