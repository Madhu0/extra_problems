

#include<stdio.h>
struct testcases{
	char date[20], d_words[200];
}cases[] = {
	{ "01/01/2015", "first january of twenty fifteen " },
	{ "11/12/2005", "eleventh december of two thousand five " },
	{ "21/12/1999", "twenty first december of nineteen ninety nine " },
	{ "1/1/10000","first january of ten thousand " },
	{ "12/2/1899", "twelth february of eighteen ninety nine " },
	{ "29/2/1600", "twenty nineth february of one thousand six hundread " },
	{ "29/2/1700", "Invalid date" }, 
	{ "-1/2/2015", "Invalid date" },
	{ "12/-2/2111", "Invalid date" },
	{ "23/3/-1222", "Invalid date" }
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
void concat(char *a, char *b){
	int i = 0,j=0;
	while (a[i] != '\0')
		i++;
	while (b[j] != 0){
		a[i] = b[j];
		i++;
		j++;
	}
	a[i] = '\0';
}
int validate(int dd, int mm, int yy){
	if (yy < 0 || mm <= 0 || dd <= 0)
		return 0;
	else if (mm>12 || dd>31 || yy>10000)
		return 0;
	else if (mm == 2){
		if (yy % 4 == 0 && yy % 100 != 0 && dd > 29)
			return 0;
		else if (yy % 100 == 0 && yy % 400 == 0 && dd > 29)
			return 0;
		else if (yy % 4 != 0 || (yy % 100 == 0 && yy % 400 != 0))
		if (dd>28)
			return 0;
	}
	else if (mm == 4 || mm == 6 || mm == 9 || mm == 11){
		if (dd > 30)
			return 0;
	}
	return 1;
}
void toInteger(char *a, int *x, int *y, int *z){
	int sign,i,n=0;
	if (a[0] == '-')
		sign = 1;
	else
		sign = 0;
	for (i = sign; a[i] != '/'; i++)
		n = n * 10 + a[i] - '0';
	if (sign == 1)
		n = n*-1;
	*x = n;
	n = 0;
	i++;
	if (a[i] == '-'){
		sign = 1;
		i++;
	}
	for (; a[i] != '/'; i++)
		n = n * 10 + a[i] - '0';
	if (sign == 1)
		n = n*-1;
	*y = n;
	n = 0;
	i++;
	if (a[i] == '-'){
		sign = 1;
		i++;
	}
	for (; a[i] != '\0'; i++)
		n = n * 10 + a[i] - '0';
	if (sign == 1)
		n = n*-1;
	*z = n;
}
void dateConvert(char *date,int i){
	int dd, mm, yy,var1,var2;
	char result[200] = "";
	char ones[][20] = { "", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine ","ten ","eleven ","twelve ","thirteen ","fourteen ","fifteen ","sixteen ","seventeen ","eighteen ","nineteen ","twenty " };
	char days[][20] = { "","first ", "second ", "third ", "fourth ", "fifth ", "sixth ", "seventh ", "eigth ", "ninth ", "tenth ", "eleventh ", "twelth ", "thirteen ", "fourteen ", "fifteen ", "sixteen ", "seventeen ", "eighteen ", "nineteen ", "twenteeth ", "twenty first ", "twenty second ", "twenty third ", "twenty fourth ", "twenty fifth ", "twent sixth ", "twenty seventh ", "twenty eigth ", "twenty nineth ", "thirteeth ", "thirty first " };
	char tenmults[][20] = { "", "ten ", "twenty ", "thirty ", "fourty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety " };
	char years[][20] = { "hundread and ", "thousand " };
	char months[][20] = { "","january ", "february ", "march ", "april ", "may ", "june ", "july ", "august ", "september ", "october ", "november ", "december " };
	char year[100] = "";
	//sscanf_s(date, "%d/%d/%d", &dd, &mm, &yy);
	toInteger(date, &dd, &mm, &yy);
	//printf("%d %d %d", dd, mm, yy);
	if (validate(dd, mm, yy)){
		concat(result, days[dd]);
		concat(result, months[mm]);
		concat(result, "of ");
		var1 = yy;
		var1 = var1 / 10;
		var2 = var1 / 10;
		if (var1 % 10 && var2 % 10){
			var1 = yy / 100;
			if (var1 <= 21)
				concat(result, ones[var1]);
			else{
				var2 = var1 / 10;
				concat(result, tenmults[var2]);
				var1 = var1 % 10;
				concat(result, ones[var1]);
			}
		}
		else if (var2 % 10==0&&var1%10!=0){
			concat(result, tenmults[var2/10]);
		}
		else{
			var1 = yy / 1000;
			concat(result, ones[var1]);
			concat(result, years[1]);
			yy = yy % 1000;
			var1 = yy / 100;
			if (var1 != 0){
				concat(result, ones[var1]);
				if (yy % 100 == 0)
					concat(result, "hundread ");
				else
					concat(result, years[0]);
			}
		}
		var1 = yy % 100;
		if (var1 > 20){
			var2 = var1 / 10;
			if (var2 > 0)
				concat(result, tenmults[var2]);
			var2 = var1 % 10;
			if (var2 > 0)
				concat(result, ones[var2]);
		}
		else if (var1 > 0)
			concat(result, ones[var1]);
	}
	else
		concat(result, "Invalid date");
	//printf("%s\n", result);
	if (compare(result, cases[i].d_words))
		printf("PASS\n");
	else
		printf("FAIL\n");
}
void test(int no_cases){
	char *res;
	int i;
	for (i = 0; i < no_cases; i++){
		dateConvert(cases[i].date, i);
	}
}
int main(){
	test(10);
	getchar();
}