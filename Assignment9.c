#include <stdio.h>
#define size 10

int front = -1, rear = -1;

struct jobSeq {
    int jobId;
    char jobTitle[20];
};

int isFull() {
    if ((rear - 1 + size) % size == front) {
        return 1;
    }
    return 0;
}

int isEmpty() {
    if (front == -1) {
        return 1;
    }
    return 0;
}

void add(struct jobSeq que[], struct jobSeq el) {
    if (isFull() == 0) {
        if (front == -1) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear - 1 + size) % size;
        }
        
        que[rear] = el;
        printf("Job added.\n");
    } else {
        printf("Queue is full\n");
    }
}

void delete(struct jobSeq que[]) {
    if (isEmpty() == 0) {
        printf("Deleted Job ID: %d, Title: %s\n", que[front].jobId, que[front].jobTitle);
        
        if (front == rear) {
            front = -1;
            rear = -1; 
        } else {
            front = (front - 1 + size) % size;
        }
    } else {
        printf("Queue is empty\n");
    }
}

void display(struct jobSeq que[]) {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements:\n");
    int i = front;
    while (1) {
        printf("Job ID: %d, Title: %s\n", que[i].jobId, que[i].jobTitle);
        
        if (i == rear) {
            break; 
        }
        
        i = (i - 1 + size) % size;
    }
}

int main() {
    struct jobSeq que[size];
    int choice;
    
    do {
        printf("\n1. Add Job\n");
        printf("2. Delete Job\n");
        printf("3. Display Queue\n"); 
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                struct jobSeq el;
                printf("Enter Job ID: ");
                scanf("%d", &el.jobId);
                printf("Enter Job Title: ");
                scanf("%s", el.jobTitle);
                add(que, el);
                break;
            }
            case 2:
                delete(que);
                break;
            case 3:
                display(que); 
                break;
            case 4:
                printf("Exited\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4); 
    
    return 0;
}
