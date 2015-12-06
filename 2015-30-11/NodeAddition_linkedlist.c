#include<stdio.h>

struct node{
	int num;
	struct node *next;
};

struct testcases{
	int in[30], key, number, out[60], len1, len2;
}cases[] = {
	{ { 1, 2, 3, 4, 5 }, 3, 7, { 1, 2, 3, 7, 4, 5 }, 5, 6 }, 
	{ { 1, 2, 3, 4, 5 }, 6, 7, { 1, 2, 3, 4, 5 }, 5, 5 }, 
	{ { 1 }, 1, 2, { 1, 2 }, 1, 2 }, 
	{ { 30, 40, 50, 60, 70 }, 30, 10, { 30, 10, 40, 50, 60, 70 }, 5, 6 }, 
	{ { 21, 65, 10, 78, 36, 20, 356 }, 356, 456, { 21, 65, 10, 78, 36, 20, 356, 456 }, 7, 8 }
};

int compare(struct node *head1, struct node *head2){
	struct node *node1, *node2;
	node1 = head1;
	node2 = head2;
	do{
		if (node1->num != node2->num)
			return 0;
		node1 = node1->next;
		node2 = node2->next;
	} while (node1 != head1&&node2 != head2);
	if (node1 ->num== node2->num)
		return 1;
	return 0;
}

struct node * numberToLinkedList(int *N, int len) {
	int i;
	struct node *head, *current,*first;
	int flag = 0;
	head = NULL;
	first = NULL;
	for (i = len-1; i >=0; i--){
		current = (struct node *)malloc(sizeof(struct node));
		current->num = N[i];
		current->next = head;
		head = current;
		if (flag == 0){
			flag = 1;
			first = current;
		}
	}
	first->next = head;
	return head;
}

void addNode(struct node *head,int key,int number){
	struct node *temp,*newnode;
	temp = head;
	do{
		if (temp->num == key){
			newnode = (struct node *)malloc(sizeof(struct node));
			newnode->num = number;
			newnode->next = temp->next;
			temp->next = newnode;
			break;
		}
		temp = temp->next;
	} while (temp != head);
}

int main(){
	int i;
	struct node *temp;
	for (i = 0; i < 5; i++){
		temp = numberToLinkedList(cases[i].in, cases[i].len1);
		addNode(temp, cases[i].key, cases[i].number);
		if (compare(temp, numberToLinkedList(cases[i].out, cases[i].len2)))
			printf("PASS\n");
		else
			printf("FAIL\n");
	}
	getchar();
}