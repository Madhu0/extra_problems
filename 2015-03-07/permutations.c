#include <stdio.h>
#include <conio.h>

void swap(char *x, char *y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
void permutations(char *a, int l, int r)
{
	int i;
	if (l == r){
		printf("%s\n", a);
	}
	else
	{
		for (i = l; i <= r; i++)
		{
			swap((a + l), (a + i));
			permutations(a, l + 1, r);
			swap((a + l), (a + i)); 
		}
	}
}

int main()
{
	int num,i=7;
	char arr[9];
	printf("Enter a number: ");
	scanf_s("%d", &num);
	arr[8] = '\0';
	while (num != 0){
		arr[i] = num % 10+'0';
		i--;
		num = num / 10;
	}
	permutations(arr, i+1, 7);
	_getch();
	return 0;
}