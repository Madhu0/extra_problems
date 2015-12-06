#include<stdio.h>
#include<stdlib.h>

struct node {
	int num;
	struct node *next;
};

struct node * numberToLinkedList(int *N,int len) {
	int i;
	struct node *head, *current;
	head = NULL;
	for (i = 0; i < len;i++){
		current = (struct node *)malloc(sizeof(struct node));
		current->num = N[i];
		current->next = head;
		head = current;
	}
	return head;
}

struct testcases{
	int in[30],len;
	float out;
}cases[] = {
	{ { 1, 2, 3, 4, 5 }, 5, 3 },
	{ { 1 }, 1, 1 },
	{ { 2, 2, 2, 2, 2, 2, 2, 2 }, 8, 2 },
	{ { 3, 4, 5, 6, 7, 8, 9, 10 }, 8, 6.5 },
	{ { 20, 25, 38, 41, 49, 52 }, 6, 39.5 },
	{ { 2, 2 }, 2, 2 }
};

float median_LinkedList(struct node *head){
	int count = 0,i;
	struct node *temp1,*temp2;
	temp1 = head;
	temp2 = head;
	while (temp1->next != NULL){
		if (temp2->next != NULL&&temp2->next->next != NULL){
			temp2 = temp2->next->next;
			temp1 = temp1->next;
		}
		else if (temp2->next == NULL)
			return temp1->num ;
		else
			return (temp1->num + temp1->next->num) / 2;;
	}
}

int main(){
	int i;
	for (i = 0; i < 6; i++){
		if (median_LinkedList(numberToLinkedList(cases[i].in, cases[i].len)))
			printf("PASS\n");
		else
			printf("FAIL\n");
	}
	getchar();
}