//reechecked queues
#include <iostream>
#include <string>
using namespace std;

class Queue {
    int *arr;
    int capacity;
    int currentSize;

public:
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        currentSize = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isFull() {
        return currentSize == capacity;
    }

    bool isEmpty() {
        return currentSize == 0;
    }

    void push(int val, int pos = -1, bool showMsg = true) {
        if (isFull()) {
            if (showMsg) cout << "Queue is FULL! Cannot insert.\n";
            return;
        }

        if (pos == -1 || pos > currentSize) pos = currentSize; // default: insert at end

        for (int i = currentSize; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = val;
        currentSize++;

        if (showMsg) {
            print();
            cout << "Inserted " << val << " at position " << pos << ".\n";
        }
    }

    void pop(int pos = -1) {
        if (isEmpty()) {
            cout << "Queue is EMPTY! Cannot pop.\n";
            return;
        }

        if (pos == -1 || pos >= currentSize) pos = currentSize - 1; // default: remove from end

        int removed = arr[pos];
        for (int i = pos; i < currentSize - 1; i++) {
            arr[i] = arr[i + 1];
        }
        currentSize--;

        print();
        cout << "Removed " << removed << " from position " << pos << ".\n";
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is EMPTY! Nothing to peek.\n";
        } else {
            cout << "Front element is: " << arr[0] << "\n";
        }
    }

    void count() {
        cout << "Current size: " << currentSize << " / " << capacity << "\n";
    }

    void print() {
        if (isEmpty()) {
            cout << "Queue is EMPTY.\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < currentSize; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;

    Queue q(size);

    int initialCount;
    cout << "How many elements do you want to insert initially? ";
    cin >> initialCount;

    if (initialCount > size) {
        cout << "Number of elements cannot exceed queue size. Setting to max size: " << size << "\n";
        initialCount = size;
    }

    cout << "Enter " << initialCount << " element(s):\n";
    for (int i = 0; i < initialCount; i++) {
        int x;
        cin >> x;
        q.push(x, -1, false); // suppress messages during initial input
    }

    // Display queue once after all initial elements are inserted
    cout << "\nInitial Queue after insertion:\n";
    q.print();
    q.count();

    int choice;
    string cont = "YES";

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Count\n";
        cout << "5. Print\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Validate menu choice first
        if (choice < 1 || choice > 6) {
            cout << "Invalid choice. Please enter a number between 1 and 6.\n";
            continue; // skip rest of loop, redisplay menu
        }

        switch (choice) {
            case 1: {
                if (!q.isFull()) {
                    int val, pos;
                    cout << "Enter value to insert: ";
                    cin >> val;
                    cout << "Enter index position (or -1 for end): ";
                    cin >> pos;
                    q.push(val, pos);
                } else {
                    cout << "Queue is FULL! Cannot insert.\n";
                }
                break;
            }
            case 2: {
                if (!q.isEmpty()) {
                    int pos;
                    cout << "Enter index position to pop (or -1 for end): ";
                    cin >> pos;
                    q.pop(pos);
                } else {
                    cout << "Queue is EMPTY! Cannot pop.\n";
                }
                break;
            }
            case 3:
                q.peek();
                break;
            case 4:
                q.count();
                break;
            case 5:
                q.print();
                break;
            case 6:
                cout << "Exiting...\n";
                return 0;
        }

        // Ask if user wants to continue
        cout << "Do you want to continue? (Y/N): ";
        cin >> cont;

    } while (cont == "Y" || cont == "y");

    cout << "Program ended.\n";
    return 0;
}

