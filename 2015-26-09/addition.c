#include<stdio.h>
#include<stdlib.h>
struct testcases{
	char number1[100], number2[100],result1[101];
	int result;
}cases[] = {
	{"45625354","23","45625377",45625377},
	{ "78452", "999", "79451",79451 },
	{ "999", "1", "1000",1000 },
	{ "999", "999", "1998",1998 },
	{ "568", "759", "1327",1327 }
};
int power(int x, int y){
	int i,pro=1;
	for (i = 0; i < y; i++)
		pro *= x;
	return pro;
}
int adder1(char *num1, char *num2){
	int i=0, j=0,k,sum=0,temp,x=0;
	while (num1[i] != '\0'&&num2[i] != '\0')
		i++;
	j = i;
	while (num1[i] != '\0')
		i++;
	while (num2[j] != '\0')
		j++;
	i--;
	j--;
	if (i > j){
		for (k = j ; k >= 0; k--){
			temp = num1[i] - '0' + num2[k] - '0';
			i--;
			sum += temp*power(10, x);
			x++;
		}
		for (k = i; k >= 0; k--){
			sum += (num1[k] - '0')*power(10, x);
			x++;
		}
	}
	else{
		for (k = i ; k >= 0; k--){
			temp = num1[k] - '0' + num2[j] - '0';
			j--;
			sum += temp*power(10, x);
			x++;
		}
		for (k = j; k >= 0; k--){
			sum += (num2[k] - '0')*power(10, x);
			x++;
		}
	}
	return sum;
}
char *reverse(char *str){
	char a[1000];
	int i=0,j;
	while (str[i] != '\0'){
		a[i] = str[i];
		i++;
	}
	j = i - 1;
	i = 0;
	while (j >= 0){
		str[i++] = a[j--];
	}
	str[i] = '\0';
	return str;
}
char *adder2(char *num1, char *num2){
	int i = 0, j = 0, k, sum = 0, temp, carry=0, pos = 0;
	char *result1;
	result1 = (char *)malloc(100 * sizeof(char));
	while (num1[i] != '\0'&&num2[i] != '\0')
		i++;
	j = i;
	while (num1[i] != '\0')
		i++;
	while (num2[j] != '\0')
		j++;
	i--;
	j--;
	if (i > j){
		for (k = j ; k >= 0; k--){
			temp = num1[i] - '0' + num2[k] - '0'+carry;
			result1[pos++] = temp % 10+'0';
			i--;
			if (temp / 10 > 0)
				carry = 1;
			else
				carry = 0;
		}
		for (k = i; k >= 0; k--){
			temp = num1[k] - '0' + carry;
			result1[pos++] = temp % 10+'0';
			if (temp / 10 > 0)
				carry = 1;
			else
				carry = 0;
		}
		if (carry == 1)
			result1[pos++] = '1';
	}
	else{
		for (k = i ; k >= 0; k--){
			temp = num1[k] - '0' + num2[j] - '0' + carry;
			j--;
			result1[pos++] = temp % 10+'0';
			if (temp / 10 > 0)
				carry = 1;
			else
				carry = 0;
		}
		for (k = j; k >= i; k--){
			temp = num2[k] - '0' + carry;
			result1[pos++] = temp % 10+'0';
			if (temp / 10 > 0)
				carry = 1;
			else
				carry = 0;
		}
		if (carry == 1)
			result1[pos++] = '1';
	}
	result1[pos] = '\0';
	//printf("%s", result1);
	result1 = reverse(result1);
	return result1;
}
int compare(char *a, char *b){
	int i = 0;
	while (a[i] != '\0'){
		if (a[i] != b[i])
			return 0;
		i++;
	}
	if (b[i] != '\0')
		return 0;
	return 1;
}
void test(no_cases){
	int i;
	char *r;
	for (i = 0; i < no_cases; i++){
		if (adder1(cases[i].number1, cases[i].number2) == cases[i].result)
			printf("PASS\n");
		else
			printf("FAIL\n");
		r = adder2(cases[i].number1, cases[i].number2);
		if (compare(cases[i].result1, r))
			printf("PASS\n");
		else
			printf("FAIL\n");
	}
}
int main(){
	test(5);
	getchar();
	return 0;
}