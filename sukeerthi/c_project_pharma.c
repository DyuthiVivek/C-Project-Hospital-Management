#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pharma_fns.h>
#include <presc_fns.h>
/*
void deduct_medicicne(struct pharma a,int new_stock);
int check_medicines(char med[20]);
struct pharma add_medicines(struct pharma a);
int read_medicines();
void add_stock(int new_stock,char name[20]);
int update_cost_meds(int new_cost,char name[20]);
struct node* get_med_prescription(struct node*head);
struct pharma {
	char name[20];
	int stock;
	int cost;
};
*/
int read_medicines(){
	struct pharma a;
	printf("Enter name of the medicine\n");
	gets(a.name);
	if(check_medicines(a.name)==0){
		printf("Enter the number of units of the medicine\n");
		scanf("%d",&a.stock);
		printf("Enter the cost of each units\n");
		scanf("%d",&a.cost);
		add_medicines(a);
		return 1;
	}
	int new_stock;
	if(check_medicines(a.name)==1){	
		printf("Enter the number of units of the medicine\n");
		scanf("%d",&new_stock);
		add_stock(new_stock,a.name);
		return 0;
	}			
}
struct pharma add_medicines(struct pharma a){
	FILE*add_med;
	int int1,int2;
	char buff[100];
	add_med=fopen("List_of_medicines","r+");
	fseek(add_med,0,SEEK_END);
	fprintf(add_med,"%s %d %d\n",a.name,a.stock,a.cost);
	fclose(add_med);
	return a;
}
void add_stock(int new_stock,char name[20]){
	int initial_stock;
	int points;
	int final_stock;
	char buff[100];
	char result[10];
	FILE*addstock;
	addstock=fopen("List_of_medicines","r+");
	fseek(addstock,0,SEEK_SET);
	while(fscanf(addstock,"%s",buff)==1){
		if(strcmp(buff,name)==0){
			points=ftell(addstock)+1;
			fscanf(addstock,"%d",&initial_stock);
			final_stock=initial_stock+new_stock;
			sprintf(result,"%d",final_stock);
			fseek(addstock,points,SEEK_SET);
			fwrite(result,sizeof(final_stock)-1,1,addstock);
			break;
		}
		}	
	fclose(addstock);
}
int check_medicines(char med[20]){
	FILE*check_med;
	int int1,int2;
	char buff[100];
	check_med=fopen("List_of_medicines","r");
	fseek(check_med,0,SEEK_SET);
	while(fscanf(check_med,"%s %d %d",buff,&int1,&int2)==3){
		if(strcmp(buff,med)==0){
			if(int1>0){
				fclose(check_med);
	      		        return 1;  //Stock is available
			}
			if(int1==0){
				fclose(check_med);
				return 2; //stock is unavailable
			}
		}
}
	fclose(check_med);
	return 0;//Medicine is unavailable in hospital pharma
}
struct node* get_med_prescription(struct node*head){
	struct node*ptr=malloc(sizeof(struct node));
	ptr=head;
	while(ptr->med!=NULL){
		deduct_medicine(ptr->med);
		ptr=ptr->next;
	return head;
	}
}
void deduct_medicine(char name[20]){
	int initial_stock;
	int points;
	int final_stock;
	char buff[100];
	char result[10];
	FILE*deductstock;
	deductstock=fopen("List_of_medicines","r+");
	fseek(deductstock,0,SEEK_SET);
	while(fscanf(deductstock,"%s",buff)==1){
		if(strcmp(buff,name)==0){
			points=ftell(deductstock)+1;
			fscanf(deductstock,"%d",&initial_stock);
			final_stock=initial_stock+1;
			sprintf(result,"%d",final_stock);
			fseek(deductstock,points,SEEK_SET);
			fwrite(result,sizeof(final_stock)-1,1,deductstock);
			break;
		}
		}	
	fclose(deductstock);
}
int update_cost_meds(int new_cost,char name[20]){
	char buff[20];
	char result[10];
	int int1;
	FILE*update_cost;
	update_cost=fopen("List_of_medicines","r+");
	fseek(update_cost,0,SEEK_SET);
	while(fscanf(update_cost,"%s %d",buff,&int1)==2){
		if(strcmp(name,buff)==0){
			sprintf(result,"%d",new_cost);
			fseek(update_cost,1,SEEK_CUR);
			fwrite(result,1,sizeof(new_cost)-1,update_cost);
			break;
		}
		}	
	fclose(update_cost);
	return 0;
}

int main(){
	char med[20];
	char medname[20];
	int new_cost;
	int option;
	//read_medicines();
	//scanf("%s",med);
	//check_medicines(med);
	printf("Do you want to update the cost of any medicine\n");
	scanf("%d",&option);
	if(option==1){
		printf("Enter name of medicine\n");
		scanf("%s",medname);
		printf("Enter the new cost\n");
		scanf("%d",&new_cost);
		update_cost_meds(new_cost,medname);
	}
	return 0;
}
