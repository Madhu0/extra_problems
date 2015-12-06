#include<stdio.h>

struct testcases{
	int in[30], out[30], len1, len2;
}cases[] = {
	{ { 1, 2, 3, 6, 5, 4 }, { 1, 2, 3, 4, 5, 6 }, 6, 6 },
	{ { 1, 2, 3, 5, 4 }, { 1, 2, 3, 4, 5 }, 5, 5 }, 
	{ { 1, 6, 5, 4, 3, 2 }, { 1, 2, 3, 4, 5, 6 }, 6, 6 }, 
	{ { 1, 2, 3, 4, 5, 6 }, { 1, 2, 3, 4, 5, 6 }, 6, 6 },
	{ { 6, 5, 4, 3, 2, 1 }, { 1, 2, 3, 4, 5, 6 },6,6 }
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

struct node * reverse(struct node *head, struct node *current){
	struct node *temp;
	temp = head->next;
	head->next = current;
	current = head;
	head = temp;
	if (head != NULL)
		return reverse(head, current);
	else
		return current;
}

struct node * sortAD(struct node *head){
	struct node *temp,*pos;
	temp = head;
	pos = head;
	while (temp->next != NULL){
		if (temp->num > temp->next->num){
			if (temp == head)
				head = reverse(temp, NULL);
			else
				pos->next = reverse(temp, NULL);
			break;
		}
		pos = temp;
		temp=temp->next;
	}
	return head;
}

int main(){
	int i;
	struct node *temp;
	for (i = 0; i < 5; i++){
		temp = sortAD(numberToLinkedList(cases[i].in, cases[i].len1));
		if (compare(temp, numberToLinkedList(cases[i].out, cases[i].len2)))
			printf("PASS\n");
		else
			printf("FAIL\n");
	}
	getchar();
}