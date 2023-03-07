void deduct_medicine(char name[20]);
int check_medicines(char med[20]);
struct pharma add_medicines(struct pharma a);
int read_medicines();
void add_stock(int new_stock,char name[20]);
struct node* get_med_prescription(struct node*head);
struct pharma {
	char name[20];
	int stock;
	int cost;
};
