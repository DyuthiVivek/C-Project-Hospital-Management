struct pharma* deduct_medicicne(struct pharma a,int new_stock);
int check_medicines(char med[20]);
struct pharma add_medicines(struct pharma a);
int read_medicines();
struct pharma add_stock(struct pharma a,int new_stock,char name[20]);
struct pharma {
	char name[20];
	int stock;
	int cost;
};
