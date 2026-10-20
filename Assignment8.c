#include <stdio.h>
#define size 10

int front = -1, rear = -1;

struct jobSeq {
    int jobId;
    char jobTitle[20];
};

int isFull() {
    if (rear == size-1) {
        return 1;
    }
    return 0;
}

void add(struct jobSeq que[], struct jobSeq el) {
    if (isFull() == 0) {
        rear = rear + 1;
        que[rear] = el;
        printf("Job added.\n");
    } else {
        printf("Queue is full\n");
    }
}

int isEmpty() {
    if (rear == front) {
        return 1;
    }
    return 0;
}

void delete(struct jobSeq que[]) {
    if (isEmpty() == 0) {
        front = front + 1;
        printf("Deleted Job ID: %d, Title: %s\n", que[front].jobId, que[front].jobTitle);
    } else {
        printf("Queue is empty\n");
    }
}


int main() {
    struct jobSeq que[size];
    int choice;
    
    do {
        printf("1. Add Job\n");
        printf("2. Delete Job\n");
        printf("3. Exit\n");
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
                printf("Exited\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 3);
    
    return 0;
} 
