//rechecked arrays
#include <iostream>
#include <limits>
using namespace std;

#define MAX 100

void displayArray(int arr[], int n) {
    cout << "Array elements: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[MAX];
    int n, totalSize;
    char cont;

    // Step 1: Ask user for initial size and elements
    cout << "Enter the size of the array (max " << MAX << "): ";
    cin >> totalSize;
    if(totalSize > MAX) totalSize = MAX;

    cout << "Enter " << totalSize << " elements:\n";
    for(n = 0; n < totalSize; n++) {
        cin >> arr[n];
    }

    cout << "\nInitial array:\n";
    displayArray(arr, totalSize);

    n = totalSize; // current filled size

    int choice;
    do {
        cout << "\n===== ARRAY MENU =====\n";
        cout << "1. Insert element\n";
        cout << "2. Delete element\n";
        cout << "3. Search element\n";
        cout << "4. Update element\n";
        cout << "5. Display array\n";
        cout << "6. Find max and min\n";
        cout << "7. Reverse array\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Input validation for menu
        if(cin.fail() || choice < 1 || choice > 8){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice! Please enter a valid number.\n";
            continue;
        }

        switch(choice) {
            case 1: { // Insert
                if(n >= MAX) {
                    cout << "Array is full! Cannot insert.\n";
                    break;
                }
                displayArray(arr, n);
                int element, pos;
                cout << "Enter element to insert: ";
                cin >> element;
                cout << "Enter position to insert (0 to " << n << ", or -1 for default at end): ";
                cin >> pos;
                if(pos == -1) pos = n; // default at end
                if(pos < 0 || pos > n) {
                    cout << "Invalid position! Insertion cancelled.\n";
                    break;
                }
                for(int i = n; i > pos; i--) {
                    arr[i] = arr[i-1];
                }
                arr[pos] = element;
                n++;
                cout << "Element inserted successfully.\n";
                displayArray(arr, n);
                break;
            }

            case 2: { // Delete
                if(n == 0) {
                    cout << "Array is empty! Cannot delete.\n";
                    break;
                }
                displayArray(arr, n);
                int pos;
                cout << "Enter position to delete (0 to " << n-1 << ", or -1 for default at end): ";
                cin >> pos;
                if(pos == -1) pos = n-1; // default at end
                if(pos < 0 || pos >= n) {
                    cout << "Invalid position! Deletion cancelled.\n";
                    break;
                }
                for(int i = pos; i < n-1; i++) {
                    arr[i] = arr[i+1];
                }
                n--;
                cout << "Element deleted successfully.\n";
                displayArray(arr, n);
                break;
            }

            case 3: { // Search
                if(n == 0) {
                    cout << "Array is empty!\n";
                    break;
                }
                int key;
                cout << "Enter element to search: ";
                cin >> key;
                bool found = false;
                for(int i = 0; i < n; i++) {
                    if(arr[i] == key) {
                        cout << "Element found at position " << i << endl;
                        found = true;
                        break;
                    }
                }
                if(!found) cout << "Element not found!\n";
                break;
            }

            case 4: { // Update
                if(n == 0) {
                    cout << "Array is empty!\n";
                    break;
                }
                displayArray(arr, n);
                int pos, newVal;
                cout << "Enter position to update (0 to " << n-1 << "): ";
                cin >> pos;
                if(pos < 0 || pos >= n) {
                    cout << "Invalid position! Update cancelled.\n";
                    break;
                }
                cout << "Enter new value: ";
                cin >> newVal;
                arr[pos] = newVal;
                cout << "Element updated successfully.\n";
                displayArray(arr, n);
                break;
            }

            case 5: { // Display
                displayArray(arr, n);
                break;
            }

            case 6: { // Max and Min
                if(n == 0) {
                    cout << "Array is empty!\n";
                    break;
                }
                int maxVal = arr[0], minVal = arr[0];
                for(int i = 1; i < n; i++) {
                    if(arr[i] > maxVal) maxVal = arr[i];
                    if(arr[i] < minVal) minVal = arr[i];
                }
                cout << "Maximum: " << maxVal << ", Minimum: " << minVal << endl;
                break;
            }

            case 7: { // Reverse
                if(n == 0) {
                    cout << "Array is empty!\n";
                    break;
                }
                for(int i = 0; i < n/2; i++) {
                    swap(arr[i], arr[n-i-1]);
                }
                cout << "Array reversed successfully.\n";
                displayArray(arr, n);
                break;
            }

            case 8: {
                cout << "Exiting program.\n";
                return 0;
            }
        }

        // Ask user if they want to continue (only accept Y/y/N/n)
        do {
            cout << "Do you want to continue? (Y/N): ";
            cin >> cont;
            if(cont == 'Y' || cont == 'y' || cont == 'N' || cont == 'n') break;
            else cout << "Invalid input! Please enter only Y or N.\n";
        } while(true);

        if(cont == 'N' || cont == 'n') {
            cout << "Exiting program.\n";
            break;
        }

    } while(true);

    return 0;
}


