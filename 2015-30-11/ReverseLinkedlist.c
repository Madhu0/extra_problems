#include<stdio.h>

struct testcases{
	int in[30], out[30], len1, len2;
}cases[] = {
	{ { 1, 2, 3, 4, 5, 6 }, { 6, 5, 4, 3, 2, 1 }, 6, 6 },
	{ { 1, 2 }, { 2, 1 }, 2, 2 },
	{ { 12, 23, 3, 4, 5, 6 }, {6,5,4,3,23,12},6,6 },
	{ { 1 }, {1},1,1 }
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

struct node * reverse(struct node *head,struct node *current){
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

int main(){
	struct node *temp,*rev;
	int i;
	for (i = 0; i < 4; i++){
		rev = NULL;
		temp = numberToLinkedList(cases[i].in, cases[i].len1);
		rev=reverse(temp, rev);
		if (compare(rev, numberToLinkedList(cases[i].out, cases[i].len2)))
			printf("PASS\n");
		else
			printf("FAIL\n");
	}
	getchar();
}