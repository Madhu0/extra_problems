#include<stdio.h>
#include<stdlib.h>

struct node {
	int num;
	struct node *next;
};

struct node * numberToLinkedList(int *N, int len) {
	int i;
	struct node *head, *current;
	head = NULL;
	for (i = len-1; i >= 0; i--){
		current = (struct node *)malloc(sizeof(struct node));
		current->num = N[i];
		current->next = head;
		head = current;
	}
	return head;
}

struct testcases{
	int in1[30],in2[30],out[60], len1,len2,len3;
}cases[] = {
	{ { 1, 2, 3, 4 }, { 5, 6, 7 }, { 1, 2, 3, 4, 5, 6, 7 }, 4, 3, 7 }, 
	{ { 1, 3, 5, 7, 9 }, { 2, 4, 6, 8 }, { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, 5, 4, 9 }, 
	{ { 5, 6, 7 }, { 1, 2, 3, 4 }, { 1, 2, 3, 4, 5, 6, 7 }, 3, 4, 7 }, 
	{ { 1, 2, 3, 4 }, { 1, 2, 3 }, { 1, 1, 2, 2, 3, 3, 4 }, 4, 3, 7 },
	{ { 1, 10 }, { 2, 3, 4, 5 }, { 1, 2, 3, 4, 5, 10 }, 2, 4, 6 }
};

int compare(struct node *head1, struct node *head2){
	struct node *node1, *node2;
	node1 = head1;
	node2 = head2;
	while (node1 != NULL&&node2 != NULL){
		if (node1->num != node2->num)
			return 0;
		node1 = node1->next;
		node2 = node2->next;
	}
	if (node1 != node2)
		return 0;
	return 1;
}

struct node * merging_LinkedLists(struct node *head1, struct node *head2){
	int count = 0, i;
	struct node *node1, *node2, *result, *current;
	node1 = head1;
	node2 = head2;
	if (head1->num < head2->num){
		result = head1;
		node1 = head1->next;
		current = result;
	}
	else{
		result = head2;
		node2 = head2->next;
		current = result;
	}
	while (node1 != NULL&&node2 != NULL){
		if (node1->num < node2->num){
			current->next = node1;
			node1 = node1->next;
			current = current->next;
		}
		else{
			current->next = node2;
			node2 = node2->next;
			current = current->next;
		}
	}
	if (node1 != NULL)
		current->next = node1;
	else if (node2 != NULL)
		current->next = node2;
	return result;
}

int main(){
	int i;
	struct node *temp1, *temp2;
	for (i = 0; i < 5; i++){
		temp1 = numberToLinkedList(cases[i].in1, cases[i].len1);
		temp2 = numberToLinkedList(cases[i].in2, cases[i].len2);
		if (compare(merging_LinkedLists(temp1,temp2),numberToLinkedList(cases[i].out,cases[i].len3)))
			printf("PASS\n");
		else
			printf("FAIL\n");
	}
	getchar();
}