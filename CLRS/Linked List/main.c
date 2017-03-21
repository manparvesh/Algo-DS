#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

// sets values to nodes
void set_values_to_nodes(struct node *head, int data, struct node *n){
    head->data = data;
    head->next = n;
}

// print the complete linked list
void print_list(struct node *n){
	while(n){
		printf(" %d\n", n->data);
		n = n->next;
	}
}

// push a node into this list at the beginning
void push(struct node **head_ref, int new_data){
    struct node* new_node = (struct node*) malloc(sizeof(struct node));

    new_node->data = new_data;
    new_node->next = (*head_ref);

    *head_ref = new_node;
}

// insert a node after given node
void insert_after(struct node* prev_node, int new_data){
    if (prev_node == NULL){
        return;
    }
    struct node* new_node = (struct node*) malloc(sizeof(struct node));

    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// given a reference pointer to the head, appends a new node at the end.
void append(struct node** head_ref, int new_data){
    struct node* new_node = (struct node*) malloc(sizeof(struct node));

    new_node->data = new_data;
    new_node->next = NULL;

    struct node* last = *head_ref;

    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }

    while(last->next != NULL){
        last = last->next;
    }

    last->next = new_node;
}

// delete the node which contains the given data
void delete_node_with_data(struct node **head_ref, int key){
    struct node* temp = *head_ref, *prev;

    if(temp == NULL){
        return;
    }

    if(temp!=NULL && temp->data == key){
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while(temp!=NULL && temp->data!=key){
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    free(temp);
}

//deletes node at given position
void delete_node_at_position(struct node **head_ref, int position){
    if(*head_ref == NULL) return;

    struct node* temp = *head_ref;

    if(position == 0){
        *head_ref = temp->next;
        free(temp);
        return;
    }

    int i = 0;
    for(i=0;i<position;i++){
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL){
        return;
    }

    struct node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

// get length of list iteratively
int get_length_iteratively(struct node *head){
    int length = 0;
    struct node *temp = head;
    while(temp!=NULL){
        temp = temp->next;
        length++;
    }
    return length;
}

// get length of list recursively
int get_length_recusively(struct node *head){
    if(head== NULL){
        return 0;
    }
    return 1 + get_length_recusively(head->next);
}

// search for element in a linked list iteratively
int search_key_iteratively(struct node* head, int key){
    if(head == NULL) return 0;

    struct node *temp = head;

    while(temp != NULL){
        if(temp->data == key){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

// get Nth value of a linked list
int get_Nth(struct node* head, int n){
    int i;
    struct node* temp = head;

    for(i=0;i<n;i++){
        temp = temp->next;
    }

    if(temp == NULL) return -1;
    return temp->data;
}

int main(){
    struct node *head = NULL;
    struct node *second = NULL;
    struct node *third = NULL;

    head = (struct node*) malloc(sizeof(struct node));
    second = (struct node*) malloc(sizeof(struct node));
    third = (struct node*) malloc(sizeof(struct node));

    set_values_to_nodes(head, 1, second);

    set_values_to_nodes(second, 2, third);

    set_values_to_nodes(third, 3, NULL);

//    print_list(head);

    insert_after(head, 4);

    append(&head, 5);

    print_list(head);

    delete_node_at_position(&head, 2);

    print_list(head);

    printf("\n");

    printf("%d\n", get_length_iteratively(head));
    printf("%d\n", search_key_iteratively(head, 2));

    return 0;
}
