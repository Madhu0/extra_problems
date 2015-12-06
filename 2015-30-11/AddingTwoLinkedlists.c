#include<stdio.h>

struct testcases{
	int in1[30],in2[30], out[30], len1, len2,len3;
}cases[] = {
	{ { 3, 5, 6, 8, 9 }, { 1, 2, 3, 4, 5 }, { 4, 8, 0, 3, 4 }, 5, 5, 5 }, 
	{ { 1, 2, 3, 4, 5, 6 }, { 1, 2, 3, 4 }, { 1, 2, 4, 6, 9, 0 }, 6, 4, 6 }, 
	{ { 9, 9, 9 }, { 9, 9, 9 }, { 1, 9, 9, 8 }, 3, 3, 4 },
	{ { 1 }, { 9 }, {1,0},1,1,2 }
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

struct node *add(struct node *head1, struct node *head2){
	head1 = reverse(head1, NULL);
	head2 = reverse(head2, NULL);
	int carry=0,sum;
	struct node *temp1, *temp2,*newnode,*previous;
	previous = NULL;
	temp1 = head1;
	temp2 = head2;
	while (temp1 != NULL&&temp2!=NULL){
		if (temp1->next == NULL)
			previous = temp1;
		sum = (temp1->num + temp2->num + carry);
		if (sum >= 10)
			carry = 1;
		else
			carry = 0;
		temp1->num = sum % 10;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	if (temp2 != NULL){
		temp1 = temp2;
		temp1->num = temp1->num + 1;
	}
	else if (carry == 1){
		newnode = (struct node *)malloc(sizeof(struct node));
		newnode->num = 1;
		newnode->next = NULL;
		previous->next = newnode;
	}
	return head1;
}

int main(){
	struct node *temp;
	int i;
	for (i = 0; i < 4; i++){
		temp = add(numberToLinkedList(cases[i].in1, cases[i].len1), numberToLinkedList(cases[i].in2, cases[i].len2));
		temp = reverse(temp, NULL);
		if (compare(temp, numberToLinkedList(cases[i].out, cases[i].len3)))
			printf("PASS\n");
		else
			printf("FAIL\n");
	}
	getchar();
}