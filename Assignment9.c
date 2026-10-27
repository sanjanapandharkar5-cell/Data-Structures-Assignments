#include <stdio.h>
#include <string.h>

#define SIZE 3

int front = 0, rear = 0;

struct jobseq {
    int jobId;
    char jobTitle[20];
};

int isFull() {
    if (((rear + 1) % SIZE) == front) {
        return 1;
    }
    return 0;
}

int isEmpty() {
    if (front == rear) {
        return 1;
    }
    return 0;
}

void add(struct jobseq que[], struct jobseq el) {
    if (isFull() == 0) {
        rear = (rear + 1) % SIZE;
        que[rear] = el;
        printf("Job added.\n");
    } else {
        printf("Queue is full\n");
    }
}

void deleteJob(struct jobseq que[]) {
    if (isEmpty() == 0) {
        front = (front + 1) % SIZE;
        printf("Deleted Job ID: %d, Title: %s\n", que[front].jobId, que[front].jobTitle);
    } else {
        printf("Queue is empty\n");
    }
}

void display(struct jobseq que[]) {
    if (isEmpty() == 1) {
        printf("No jobs are present\n");
    } else {
        int i = (front + 1) % SIZE;
        while (1) {
            printf("Job ID: %d, Title: %s\n", que[i].jobId, que[i].jobTitle);
            if (i == rear) {
                break;
            }
            i = (i + 1) % SIZE;
        }
    }
}

int main() {
    struct jobseq que[SIZE];
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
                struct jobseq el;
                printf("Enter Job ID: ");
                scanf("%d", &el.jobId);
                printf("Enter Job Title: ");
                scanf("%s", el.jobTitle);
                add(que, el);
                break;
            }
            case 2:
                deleteJob(que);
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

