struct node{
        char med[100];
        struct node* next;
};
struct node *new_node(char med[100]);
void print_cart(struct node *t);
void print_presc_names(char name[100]);
struct node *add_medicine_from_presc(struct node *head);
struct node *add_more(struct node *head);
struct node *delete_med(struct node *head);
struct node *return_cart(char name[31]);
char *create_presc();

