#include<stdio.h>

struct testcases{
	int in[30], out[30], len1, len2;
}cases[] = {
	{ { 1, 5, 3, 4, 2, 6 }, { 1, 2, 3, 4, 5, 6 }, 6, 6 }, 
	{ { 11, 7, 8, 9, 10, 6 }, { 6, 7, 8, 9, 10, 11 }, 6, 6 },
	{ { 2, 4, 8, 6, 10 }, { 2, 4, 6, 8, 10 },5,5 },
	{ { 1, 2, 3, 5, 4 }, { 1, 2, 3, 4, 5 }, 5, 5 },
	{ { 1, 2, 3, 4, 5 }, { 1, 2, 3, 4, 5 }, 5, 5 }
};

struct node {
	int num;
	struct node *next;
};

struct node * numberToLinkedList(int *N, int len) {
	int i;
	struct node *head, *current;
	head = NULL;
	for (i = len - 1; i >= 0; i--){
		current = (struct node *)malloc(sizeof(struct node));
		current->num = N[i];
		current->next = head;
		head = current;
	}
	return head;
}

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

struct node *sort(struct node *head){
	struct node *temp,*first,*second;
	first = NULL;
	second = NULL;
	int n1 = -1, n2 = -1 ;
	temp = head;
	while (temp->next != NULL){
		if (temp->num > temp->next->num){
			if (n1 == -1){
				n1 = temp->num;
				first = temp;
				break;
			}
		}
		temp = temp->next;
	}
	if (n1 == -1)
		return head;
	temp = temp->next;
	while (temp != NULL){
		if (temp->num < n1){
			n2 = temp->num;
			second = temp;
		}
		else
			break;
		temp = temp->next;
	}
	first->num = n2;
	second->num = n1;
	return head;
}

int main(){
	int i;
	struct node *temp;
	for (i = 0; i < 5; i++){
		temp = sort(numberToLinkedList(cases[i].in, cases[i].len1));
		if (compare(temp, numberToLinkedList(cases[i].out, cases[i].len2)))
			printf("PASS\n");
		else
			printf("FAIL\n");
	}
	getchar();
}