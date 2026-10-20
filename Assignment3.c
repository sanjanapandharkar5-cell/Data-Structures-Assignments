#include <stdio.h>

struct bookInfo {
    char bookName[20];
    int bookId;
    char bookAuthor[20];
    int numberOfCopies;
};

void accept(struct bookInfo books[], int n) {
    for(int i = 0; i < n; i++) {
        printf("Enter book name: ");
        scanf("%s", books[i].bookName);
        printf("Enter book author: ");
        scanf("%s", books[i].bookAuthor);
        printf("Enter book id: ");
        scanf("%d", &books[i].bookId);
        printf("Enter number of copies: ");
        scanf("%d", &books[i].numberOfCopies);
    }
}

void display(struct bookInfo books[], int n) {
    for(int i = 0; i < n; i++) {
        printf("book name: %s\n", books[i].bookName);
        printf("book author: %s\n", books[i].bookAuthor);
        printf("book id: %d\n", books[i].bookId);
        printf("copies: %d\n", books[i].numberOfCopies);
    }
}

int linearSearch(struct bookInfo books[], int n, int el) {
      for(int i=0; i<n; i++) {
            if(books[i].bookId == el) {
                return i;
            }
      }
      return -1;
}
             
int binarySearch(struct bookInfo books[], int n, int el) {
      int l=0, h=n-1;
      while(l<=h) {
           int mid = (l+h)/2;
           if(books[mid].numberOfCopies == el) {
                return mid;
           } else {
                   if(books[mid].numberOfCopies > el) {
                         h = mid-1;
                   } else {
                         l=mid+1;
                   }
           }
      }
      return -1;
}

void bubbleSort(struct bookInfo books[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (books[j].bookId > books[j + 1].bookId) {
                struct bookInfo temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}

void selectionSort(struct bookInfo books[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (books[j].bookId < books[minIndex].bookId) {
                minIndex = j;
            }
        }
        struct bookInfo temp = books[minIndex];
        books[minIndex] = books[i];
        books[i] = temp;
    }
}


void insertionSort(struct bookInfo books[], int n) {
    for (int i = 1; i < n; i++) {
        struct bookInfo key = books[i];
        int j = i - 1;
       
        while (j >= 0 && books[j].bookId > key.bookId) {
            books[j + 1] = books[j];
            j = j - 1;
        }
        books[j + 1] = key;
    }
}


void shellSort(struct bookInfo books[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            struct bookInfo temp = books[i];
            int j;
           
            for (j = i; j >= gap && books[j - gap].bookId > temp.bookId; j -= gap) {
                books[j] = books[j - gap];
            }
            books[j] = temp;
        }
    }
}
                                                                   
int main() {
    struct bookInfo books[50];
    int total;
    printf("Total books: ");
    scanf("%d", &total);
    accept(books, total);
    printf("\n");
   
    printf("Original:\n");
    display(books, total);
    printf("\n");
   
    int lans = linearSearch(books, total, 23);
    if(lans!=-1) {
         printf("Linear Search Found at: %d\n", lans);
    } else {
         printf("Linear Search Not Found\n");
    }
   
    int bans = binarySearch(books, total, 64);
    if(bans!=-1) {
         printf("Binary Search Found at: %d\n", bans);
    } else {
         printf("Binary Search Not Found\n");
    }
   
    int op;
    printf("Enter the sorting method you want to perform: ");
    scanf("%d", &op);
   
    switch(op) {
        case 1: bubbleSort(books, total);
                printf("\nBubbleSort\n");
                display(books, total);
                printf("\n");
                break;
        case 2: selectionSort(books, total);
                printf("\nSelectionSort\n");
                display(books, total);
                printf("\n");
                break;
        case 3: insertionSort(books, total);
                printf("\nInsertionSort\n");
                display(books, total);
                printf("\n");
                break;
        case 4: shellSort(books, total);
                printf("\nShellSort\n");
                display(books, total);
                printf("\n");
        default: printf("Wrong method");
    }
   
    return 0;
}
