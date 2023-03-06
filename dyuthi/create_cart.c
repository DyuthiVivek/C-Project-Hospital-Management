#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STR_SIZE 100

struct node{
	char med[STR_SIZE];
	struct node* next;
};

struct node *new_node(char med[STR_SIZE])
{
	//check medicine
	struct node *t;
	t = (struct node*)malloc(sizeof(struct node));
	strcpy(t->med,med);
	t->next = NULL;
	return t;
}

void print_cart(struct node *t)
{
	if(!t)
		return;
	printf("%s\n",t->med);
	print_cart(t->next);
}

void print_presc_names(char name[STR_SIZE])
{
	char str[STR_SIZE];
	char cmd[STR_SIZE];
#ifdef __linux__
	sprintf(cmd,"ls %s_*",name);
#elif _WIN32
	sprintf(cmd,"dir %s_*",name);
#endif
	FILE *fp=popen(cmd,"r");
	while(fgets(str,STR_SIZE,fp)) {
		printf("%s",str);
	}
	pclose(fp);

}

struct node *add_medicine_from_presc(struct node *head)
{
	char presc_name[STR_SIZE];
	char med[STR_SIZE];
	FILE *fp;
	printf("Enter name of prescription you want to use\n");
	fgets(presc_name,STR_SIZE,stdin);
	presc_name[strlen(presc_name)-1]=0;

	fp = fopen(presc_name,"r");
	if(!fp)
		return NULL;

	struct node *t = head;
	while(fgets(med,STR_SIZE,fp))
	{
		//check medicine
		med[strlen(med)-1]=0;
		printf("%s\n",med);
		if(t) {
			t-> next = new_node(med);
			t = t->next;
		} else
			t = head = new_node(med);
		
	}
	fclose(fp);
	return head;

}

struct node *add_more(struct node *head)
{
	char med[STR_SIZE];
	printf("Enter medicine name\n");
	fgets(med,STR_SIZE,stdin);
	med[strlen(med)-1]=0;
	//check_med
	if(head) {
		struct node *t = head;
		while(t->next != NULL)
			t = t->next;
		t->next = new_node(med);
	} else {
		head = new_node(med);
	}

	return head;
}

struct node *delete_med(struct node *head)
{
	char med[STR_SIZE];
	printf("Enter medicine name\n");
	fgets(med,STR_SIZE,stdin);
	med[strlen(med)-1]=0;

	struct node *t = head;
	struct node *prev = NULL;

	for(;t!=NULL && strncmp(med,t->med,strlen(med));t=t->next)
		prev = t;

	if(!t)
	{
		return head;
		printf("Not found\n");

	}


}

void main()
{
	char name[STR_SIZE];
	struct node *head=NULL;
	fgets(name,STR_SIZE,stdin);
	name[strlen(name)-1]=0;
	print_presc_names(name);
	head = add_medicine_from_presc(head);
	print_cart(head);
	head = add_more(head);
	print_cart(head);
}
