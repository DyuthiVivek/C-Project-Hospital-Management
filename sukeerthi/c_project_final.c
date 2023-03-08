#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pharma_fns.h>
#include <presc_fns.h>
int read_medicines(){                                                  //function to take inputs of medicine details to be added
	struct pharma a;
	char stock[10];
	char cost[10];
	printf("Enter name of the medicine\n");
	fgets(a.name,20,stdin);
	a.name[strlen(a.name)-1]=0;
	if(check_medicines(a.name)==0){                               //if the medicine is new it is added to the list using functions add_medicines
		printf("Enter the number of units of the medicine\n");
		fgets(stock,10,stdin);
		a.stock=atoi(stock);
		printf("Enter the cost of each units\n");
		fgets(cost,10,stdin);
		a.cost=atoi(cost);
		add_medicines(a);
		return 1;
	}
	int new_stock;
	char new[10];
	if(check_medicines(a.name)==1 || check_medicines(a.name)==2){	 //if the medicine already exists new stock is added using function add_stock
		printf("Enter the number of units of the medicine\n");
		fgets(new,10,stdin);
		new_stock=atoi(new);
		add_stock(new_stock,a.name);
		return 0;
	}			
}
struct pharma add_medicines(struct pharma a){                          //function to add the medicine to the list
	FILE*add_med;
	int int1,int2;
	char buff[100];
	add_med=fopen("List_of_medicines","r+");                       //opening the text file containing the list
	fseek(add_med,0,SEEK_END);
	fprintf(add_med,"%s %d %d\n",a.name,a.stock,a.cost);           //printing the new medicine details at the end of the file
	fclose(add_med);
	return a;
}
void add_stock(int new_stock,char name[20]){                           //function to add stock of medicines by taking the input name of the medicine and new stock
	int initial_stock;
	int points;
	int final_stock;
	char buff[100];
	char result[12];
	FILE*addstock;
	addstock=fopen("List_of_medicines","r+");
	fseek(addstock,0,SEEK_SET);
	while(fscanf(addstock,"%s",buff)==1){                          //checking for the name with each medicine name
		if(strcmp(buff,name)==0){
			points=ftell(addstock)+1;
			fscanf(addstock,"%d",&initial_stock);          //storing the initial value of stock
			final_stock=initial_stock+new_stock;           //calculating final value
			sprintf(result,"%d",final_stock);
			fseek(addstock,points,SEEK_SET);
			fwrite(result,sizeof(final_stock)-1,1,addstock);  //overwriting the final value of stock using fwrite
			break;
		}
		}	
	fclose(addstock);
}
int check_medicines(char med[20]){                                    //function to check for the medicine in pharmacy list
	FILE*check_med;
	int int1,int2;
	char buff[100];
	check_med=fopen("List_of_medicines","r");
	fseek(check_med,0,SEEK_SET);
	while(fscanf(check_med,"%s %d %d",buff,&int1,&int2)==3){
		if(strcmp(buff,med)==0){                             //checking the name of medicine with name entered 
			if(int1>0){
				fclose(check_med);
	      		        return 1;                            //returns 1 if medicine is sold in pharmacy and stock is available
			}
			if(int1==0){
				fclose(check_med);
				return 2;                           //returns 2 if medicine is sold in pharmacy but stock is unavailable
			}
		}
}
	fclose(check_med);
	return 0;                                                   //Medicine is not sold in hospital pharmacy
}
struct node* get_med_prescription(struct node*head){               //using the prescription to check the medicines in pharmacy and print the bill
	struct node*ptr=malloc(sizeof(struct node));          
	ptr=head;
	int a,b;
	int total=0;
	printf("*************************************HOSPITAL-PHARMACY*******************************************\n");
	printf("Name of medicine          Cost\n");
	b=billing(ptr->med);
	total=total+b;
	while(ptr->next!=NULL){                                    //ptr traverses through the linked list 
		ptr=ptr->next;
		deduct_medicine(ptr->med);                         //each medicine in linked list is passed through deduct function
		a=billing(ptr->med);                               //    and billing function
		total=total+a;
	}
	printf("Total Amount               %d\n",total);           //printing the total of the bill
	printf("*************************************************************************************************\n");
	return head;
}
void deduct_medicine(char name[20]){                               //function the reduce the stock of the medicine when sold 
	int initial_stock;
	int points;
	int final_stock;
	char buff[100];
	char result[12];
	FILE*deductstock;
	deductstock=fopen("List_of_medicines","r+");
	fseek(deductstock,0,SEEK_SET);
	while(fscanf(deductstock,"%s",buff)==1){                  //checking for the name of medicine
		if(strcmp(buff,name)==0){
			points=ftell(deductstock)+1;
			fscanf(deductstock,"%d",&initial_stock);
			final_stock=initial_stock-1;              //reducing the stock by one unit
			sprintf(result,"%d",final_stock);          //converting final stock  int to string
			fseek(deductstock,points,SEEK_SET);         
			fwrite(result,sizeof(final_stock)-1,1,deductstock);      //rewriting the final stock after reducing
			break;
		}
	}	
	fclose(deductstock);
}
int  billing(char name[20]){                                             //fnction to print each medicine in bill
	char buff[20];
	int int1,int2;
	FILE*bill=fopen("List_of_medicines","r+");
	fseek(bill,0,SEEK_SET);
	while(fscanf(bill,"%s %d %d",buff,&int1,&int2)==3){              //checking for the medicine in list
		if(strcmp(buff,name)==0){
			printf("%s                       %d\n",name,int2); //printing the name of the medicine and its cost
			fclose(bill);
			return int2;                                       //returns the cost to get added to total 
		}
	}
}	
/*
int main(){
	char med[20];
	char medname[20];
	int new_cost;
	int option;
	read_medicines();
	scanf("%s",med);
	check_medicines(med);
	printf("Do you want to update the cost of any medicine\n");
	scanf("%d",&option);
	if(option==1){
		printf("Enter name of medicine\n");
		scanf("%s",medname);
		printf("Enter the new cost\n");
		scanf("%d",&new_cost);
		update_cost_meds(new_cost,medname);
	}
	struct node* head=malloc(sizeof(struct node));
	struct node a;
	struct node b;
	struct node c;
	head=&a;
	strcpy(head->med,"Dolo");
	head->next=&b;
	strcpy(b.med,"Kolo");
	b.next=&c;
	strcpy(c.med,"Pipo");
	c.next=NULL;
	get_med_prescription(head);
	return 0;}
*/
