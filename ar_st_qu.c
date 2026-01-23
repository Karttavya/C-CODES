#include <stdio.h>
#include <stdlib.h>

// -----------------------------
// 1. ARRAY OPERATIONS
// -----------------------------
void array_operations() {
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[size];
    int n = size;
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int choice;
    while (1) {
        printf("\n--- Array Menu ---\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display array\n");
        printf("4. Search element\n");
        printf("5. Update element\n");
        printf("6. Sort array\n");
        printf("7. Reverse array\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int pos, val;
            printf("Enter position (0-based index): ");
            scanf("%d", &pos);
            printf("Enter value to insert: ");
            scanf("%d", &val);
            if (pos < 0 || pos > n) {
                printf("Invalid position!\n");
            } else {
                for (int i = n; i > pos; i--) arr[i] = arr[i-1];
                arr[pos] = val;
                n++;
            }
        }
        else if (choice == 2) {
            int pos;
            printf("Enter position to delete (0-based index): ");
            scanf("%d", &pos);
            if (pos < 0 || pos >= n) {
                printf("Invalid position!\n");
            } else {
                for (int i = pos; i < n-1; i++) arr[i] = arr[i+1];
                n--;
            }
        }
        else if (choice == 3) {
            printf("Array elements: ");
            for (int i = 0; i < n; i++) printf("%d ", arr[i]);
            printf("\n");
        }
        else if (choice == 4) {
            int val, found = 0;
            printf("Enter element to search: ");
            scanf("%d", &val);
            for (int i = 0; i < n; i++) {
                if (arr[i] == val) {
                    printf("%d found at index %d\n", val, i);
                    found = 1;
                    break;
                }
            }
            if (!found) printf("%d not found\n", val);
        }
        else if (choice == 5) {
            int pos, val;
            printf("Enter position to update (0-based index): ");
            scanf("%d", &pos);
            if (pos < 0 || pos >= n) printf("Invalid position!\n");
            else {
                printf("Enter new value: ");
                scanf("%d", &val);
                arr[pos] = val;
            }
        }
        else if (choice == 6) {
            int order;
            printf("Sort Ascending(1) or Descending(2)? ");
            scanf("%d", &order);
            for(int i=0;i<n-1;i++){
                for(int j=i+1;j<n;j++){
                    if ((order==1 && arr[i]>arr[j]) || (order==2 && arr[i]<arr[j])){
                        int temp=arr[i]; 
                        arr[i]=arr[j]; 
                        arr[j]=temp;
                    }
                }
            }
        }
        else if (choice == 7) {
            for(int i=0;i<n/2;i++){
                int temp=arr[i]; 
                arr[i]=arr[n-1-i]; 
                arr[n-1-i]=temp;
            }
        }
        else if (choice == 8) break;
        else printf("Invalid choice!\n");
    }
}

// -----------------------------
// 2. STACK OPERATIONS
// -----------------------------
void stack_operations() {
    int max_size;
    printf("Enter maximum size of stack: ");
    scanf("%d", &max_size);

    int stack[max_size], top = -1;
    int choice;

    while(1){
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Peek/Top\n4. Display\n5. Check if empty\n6. Check if full\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        if(choice==1){
            if(top==max_size-1) printf("Stack is full!\n");
            else{
                int val;
                printf("Enter element to push: ");
                scanf("%d",&val);
                stack[++top]=val;
            }
        }
        else if(choice==2){
            if(top==-1) printf("Stack is empty!\n");
            else printf("Popped element: %d\n",stack[top--]);
        }
        else if(choice==3){
            if(top==-1) printf("Stack is empty!\n");
            else printf("Top element: %d\n",stack[top]);
        }
        else if(choice==4){
            if(top==-1) printf("Stack is empty!\n");
            else{
                printf("Stack elements: ");
                for(int i=0;i<=top;i++) printf("%d ",stack[i]);
                printf("\n");
            }
        }
        else if(choice==5) printf("Stack empty? %s\n",(top==-1)?"Yes":"No");
        else if(choice==6) printf("Stack full? %s\n",(top==max_size-1)?"Yes":"No");
        else if(choice==7) break;
        else printf("Invalid choice!\n");
    }
}

// -----------------------------
// 3. QUEUE OPERATIONS
// -----------------------------
void queue_operations() {
    int max_size;
    printf("Enter maximum size of queue: ");
    scanf("%d", &max_size);

    int queue[max_size], front=-1, rear=-1;
    int choice;

    while(1){
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek/Front\n4. Display\n5. Check if empty\n6. Check if full\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        if(choice==1){
            if(rear==max_size-1) printf("Queue is full!\n");
            else{
                int val;
                printf("Enter element to enqueue: ");
                scanf("%d",&val);
                if(front==-1) front=0;
                queue[++rear]=val;
            }
        }
        else if(choice==2){
            if(front==-1 || front>rear) {
                printf("Queue is empty!\n");
            } else {
                printf("Dequeued element: %d\n",queue[front++]);
            }
        }
        else if(choice==3){
            if(front==-1 || front>rear) printf("Queue is empty!\n");
            else printf("Front element: %d\n",queue[front]);
        }
        else if(choice==4){
            if(front==-1 || front>rear) printf("Queue is empty!\n");
            else{
                printf("Queue elements: ");
                for(int i=front;i<=rear;i++) printf("%d ",queue[i]);
                printf("\n");
            }
        }
        else if(choice==5) printf("Queue empty? %s\n",(front==-1 || front>rear)?"Yes":"No");
        else if(choice==6) printf("Queue full? %s\n",(rear==max_size-1)?"Yes":"No");
        else if(choice==7) break;
        else printf("Invalid choice!\n");
    }
}

// -----------------------------
// MAIN FUNCTION
// -----------------------------
int main() {
    int choice;
    while(1){
        printf("\n--- Main Menu ---\n");
        printf("1. Array Operations\n2. Stack Operations\n3. Queue Operations\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        if(choice==1) array_operations();
        else if(choice==2) stack_operations();
        else if(choice==3) queue_operations();
        else if(choice==4) break;
        else printf("Invalid choice!\n");
    }

    return 0;
}