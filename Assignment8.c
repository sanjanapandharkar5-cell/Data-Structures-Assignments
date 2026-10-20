#include <stdio.h>
#define size 3

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
        printf("Print job added successfully\n");
    } else {
        printf("Queue Overflow! Print queue is full.\n");
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
        printf("The first inserted print job is processed & removed. Job ID: %d, Title: %s\n", que[front].jobId, que[front].jobTitle);
    } else {
        printf("Queue Underflow! No print jobs available.\n");
    }
}

void display(struct jobSeq que[]) {
    if (isEmpty() == 1) {
        printf("No pending print jobs is displayed\n");
    } else {
        printf("All pending print jobs are displayed in FIFO order:\n");
        for (int i = front + 1; i <= rear; i++) {
            printf("Job ID: %d, Title: %s\n", que[i].jobId, que[i].jobTitle);
        }
    }
}


int main() {
    struct jobSeq que[size];
    int choice;
    
    printf("Queue initialized successfully\n");
    
    do {
        printf("\n1. Add Print Job\n");
        printf("2. Delete Print Job\n");
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
                printf("Program terminates successfully\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);
    
    return 0;
}
