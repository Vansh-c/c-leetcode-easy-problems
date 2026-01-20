#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int *arr;
    int f; 
    int r; 
} MyStack;


MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->arr = (int*)malloc(sizeof(int) * MAX_SIZE);
    stack->f = -1;
    stack->r = -1;
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    if (obj->r == MAX_SIZE - 1) {
        printf("stack overflow\n");
        return;
    }

  
    if (obj->f == -1 && obj->r == -1) {
        obj->f = obj->r = 0;
        obj->arr[obj->r] = x;
    } else {
        obj->r++;
        obj->arr[obj->r] = x;

    
        int count = obj->r - obj->f; // count is number of elements before push  = rear - front.
        for (int i = 0; i < count; i++) {
            int temp = obj->arr[obj->f];
          
            obj->f++;
          
            obj->r++;
            obj->arr[obj->r] = temp;
        }
     
        obj->f = obj->r - count;
    }
}


int myStackPop(MyStack* obj) {
    if (obj->f == -1) {
        printf("stack is empty\n");
        return -1;
    }

    int val = obj->arr[obj->f];

    
    if (obj->f == obj->r) {
        obj->f = obj->r = -1;
    } else {
        obj->f++;
    }

    return val;
}


int myStackTop(MyStack* obj) {
    if (obj->f == -1) {
        printf("stack is empty\n");
        return -1;
    }
    return obj->arr[obj->f];
}


bool myStackEmpty(MyStack* obj) {
    return obj->f == -1;
}

void myStackFree(MyStack* obj) {
    free(obj->arr);
    free(obj);
}



int main() {
    MyStack* myStack = myStackCreate();

    
    myStackPush(myStack, 1);
    myStackPush(myStack, 2);

    printf("Top: %d\n", myStackTop(myStack)); 

    printf("Pop: %d\n", myStackPop(myStack)); 

    printf("Is empty? %s\n", myStackEmpty(myStack) ? "true" : "false"); 

    
    printf("Pop: %d\n", myStackPop(myStack)); 

   
    printf("Is empty? %s\n", myStackEmpty(myStack) ? "true" : "false"); 

    myStackFree(myStack);
    return 0;
}
