#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* create_stack(unsigned capacity){
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *) malloc(stack->capacity * sizeof(int));
    return stack;
};

int is_full(struct Stack* stack){
    return stack->top == stack->capacity - 1;
}

int is_empty(struct Stack* stack){
    return stack->top == -1;
}

void push(struct Stack* stack, int item){
    if(is_full(stack)){
        return;
    }
    stack->array[++stack->top] = item;
    printf("pushed: %d\n", item);
}

int pop(struct Stack* stack){
    if(is_empty(stack)){
        return;
    }
    return stack->array[stack->top--];
}

int main(){
    struct Stack* stack = create_stack(100);
    int i;
    for(i=0;i<40;i++){
        push(stack, i*2);
    }
    printf("popped: %d\n", pop(stack));
    return 0;
}
