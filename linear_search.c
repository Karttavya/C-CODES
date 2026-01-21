#include <stdio.h>
#define size 10
// Global array
int arr[size] = {10, 20, 30, 40, 50};
int count= 5;
// Function for Linear Search
int linearSearch(int n) {
for (int i = 0; i < count; i++) {
if (arr[i] == n) {
return i; // element found, return index
}
}
return -1; // element not found
}
int main() {
int key = 30; // element to search
int result = linearSearch(key);
if (result != -1)
printf("Element %d found at index %d\n", key, result);
else
printf("Element %d not found\n", key);
return 0;
}