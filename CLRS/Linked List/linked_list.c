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
		printf(" %d ", n->data);
		n = n->next;
	}
	printf("\n");
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

//reverses a linked list recursively
void reverse_list(struct node** head_ref){
    if(!head_ref){
        return;
    }
    reverse_util(*head_ref, NULL, head_ref);
}

void reverse_util(struct node *curr, struct node* prev, struct node** head_ref){
    if(!curr->next){
        *head_ref = curr;
        curr->next = prev;
        return;
    }

    struct node* next = curr->next;
    curr->next = prev;
    reverse_util(next, curr, head_ref);
}

// reverses a list iteratively
void reverse_list_2(struct node** head_ref){
    struct node* prev = NULL;
    struct node* current = *head_ref;
    struct node* next;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head_ref = prev;
}

// compares if lists are equal
int compare_lists(struct node* head1, struct node* head2){
    struct node* temp1 = head1;
    struct node* temp2 = head2;

    while(temp1 && temp2){
        if(temp1->data == temp2->data){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }else{
            return 0;
        }
    }

    if(temp1==NULL && temp2==NULL){
        return 1;
    }
    return 0;
}

// checks if a list is a palindrome
int is_palindrome(struct node* head){
    struct node* slow_ptr = head;
    struct node* fast_ptr = head;
    struct node* second_half;
    struct node* prev_of_slow_ptr = head;
    struct node* mid_node = NULL;
    int res = 1;

    if(head!=NULL && head->next!=NULL){
        while(fast_ptr != NULL && fast_ptr->next != NULL){
            fast_ptr = fast_ptr->next->next;
            prev_of_slow_ptr = slow_ptr;
            slow_ptr = slow_ptr->next;
        }
        //now the slow_ptr is on the middle of the list

        //if the length is odd
        if(fast_ptr!=NULL){
            mid_node = slow_ptr;
            slow_ptr = slow_ptr->next;
        }

        second_half = slow_ptr;
        prev_of_slow_ptr->next = NULL;
        reverse_list(&second_half);
        res = compare_lists(head, second_half);

        reverse_list(&second_half);

        if(mid_node){
            prev_of_slow_ptr->next = mid_node;
            mid_node->next = second_half;
        }else{
            prev_of_slow_ptr->next = second_half;
        }
    }

    return res;
}

// get intersection util function
int _get_intersection_node(int d, struct node* head1, struct node* head2){
    int i;
    struct node* current1 = head1;
    struct node* current2 = head2;

    for(i=0;i<d;i++){
        if(current1==NULL){
            return -1;
        }
        current1 = current1->next;
    }
    while(current1 != NULL && current2 != NULL){
        if(current1 == current2){
            return current1->data;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    return -1;
}

// get intersection function
int get_intersection_node(struct node* head1, struct node* head2){
    int c1 = get_length_iteratively(head1);
    int c2 = get_length_iteratively(head2);
    int d;

    if(c1 > c2){
        d = c1 - c2;
        return _get_intersection_node(d, head1, head2);
    }else{
        d = c2 - c1;
        return _get_intersection_node(d, head2, head1);
    }
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

    insert_after(head, 3);

    append(&head, 1);

    print_list(head);

    reverse_list_2(&head);

    print_list(head);

    printf("%d\n", is_palindrome(head));


    return 0;
}
