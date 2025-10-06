#include <iostream>
using namespace std;

// ====================== SINGLY LINKED LIST ======================
// Structure for list node
struct ListNode {
    int info;
    ListNode* link;
    ListNode(int val) : info(val), link(nullptr) {}
};

// Linked list handler class
class ListHandler {
private:
    ListNode* start;
public:
    ListHandler() : start(nullptr) {}

    // Add node at start
    void prependNode(int val) {
        ListNode* freshNode = new ListNode(val);
        freshNode->link = start;
        start = freshNode;
        cout << "Added " << val << " at beginning\n";
    }

    // Add node at end
    void appendNode(int val) {
        ListNode* freshNode = new ListNode(val);
        if (!start) {
            start = freshNode;
        } else {
            ListNode* current = start;
            while (current->link) current = current->link;
            current->link = freshNode;
        }
        cout << "Added " << val << " at end\n";
    }

    // Remove node by value
    void removeNode(int val) {
        if (!start) {
            cout << "List empty!\n";
            return;
        }
        
        // Check if first node matches
        if (start->info == val) {
            ListNode* oldNode = start;
            start = start->link;
            delete oldNode;
            cout << "Removed " << val << " from list\n";
            return;
        }
        
        // Search for node to remove
        ListNode* current = start;
        while (current->link && current->link->info != val)
            current = current->link;
            
        if (!current->link) {
            cout << val << " not in list\n";
        } else {
            ListNode* oldNode = current->link;
            current->link = current->link->link;
            delete oldNode;
            cout << "Removed " << val << " from list\n";
        }
    }

    // Show all nodes
    void showList() {
        if (!start) {
            cout << "List is empty\n";
            return;
        }
        ListNode* current = start;
        cout << "List contents: ";
        while (current) {
            cout << current->info;
            if (current->link) cout << " => ";
            current = current->link;
        }
        cout << " => END\n";
    }
};

// ====================== SORTING ALGORITHMS ======================

// Combine sorted arrays (for merge sort)
void combineArrays(int arr[], int left, int mid, int right) {
    int size1 = mid - left + 1;
    int size2 = right - mid;
    
    // Temporary arrays
    int firstHalf[size1], secondHalf[size2];
    
    // Copy data
    for (int i = 0; i < size1; i++)
        firstHalf[i] = arr[left + i];
    for (int j = 0; j < size2; j++)
        secondHalf[j] = arr[mid + 1 + j];
    
    // Merge back into original array
    int i = 0, j = 0, k = left;
    while (i < size1 && j < size2) {
        if (firstHalf[i] <= secondHalf[j]) {
            arr[k] = firstHalf[i];
            i++;
        } else {
            arr[k] = secondHalf[j];
            j++;
        }
        k++;
    }
    
    // Copy remaining elements
    while (i < size1) arr[k++] = firstHalf[i++];
    while (j < size2) arr[k++] = secondHalf[j++];
}

// Recursive merge sort
void recursiveMergeSort(int arr[], int left, int right) {
    if (left >= right) return;
    
    int middle = left + (right - left) / 2;
    recursiveMergeSort(arr, left, middle);
    recursiveMergeSort(arr, middle + 1, right);
    combineArrays(arr, left, middle, right);
}

// Partition for quick sort
int splitArray(int arr[], int low, int high) {
    int pivot = arr[high];  // Last element as pivot
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            // Swap elements
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Place pivot in correct position
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

// Recursive quick sort
void recursiveQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = splitArray(arr, low, high);
        recursiveQuickSort(arr, low, pivotIndex - 1);
        recursiveQuickSort(arr, pivotIndex + 1, high);
    }
}

// ====================== SEARCH ALGORITHM ======================

// Find element in sorted array
int findInSortedArray(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    
    while (left <= right) {
        int center = left + (right - left) / 2;
        
        if (arr[center] == target)
            return center;  // Found at center index
        else if (arr[center] < target)
            left = center + 1;  // Search right half
        else
            right = center - 1;  // Search left half
    }
    return -1;  // Not found
}

// ====================== UTILITY FUNCTIONS ======================

// Display array elements
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// ====================== MAIN PROGRAM ======================
int main() {
    ListHandler myList;
    int mainChoice;
    
    do {
        cout << "\n========== DATA STRUCTURES MENU ==========\n";
        cout << "1. Work with Linked List\n";
        cout << "2. Use Sorting Algorithms\n";
        cout << "3. Perform Binary Search\n";
        cout << "4. Quit Program\n";
        cout << "Choose option (1-4): ";
        cin >> mainChoice;

        switch (mainChoice) {
            // Linked List Operations
            case 1: {
                int listChoice, value;
                do {
                    cout << "\n----- LINKED LIST OPERATIONS -----\n";
                    cout << "1. Insert at Start\n";
                    cout << "2. Insert at End\n";
                    cout << "3. Remove Specific Value\n";
                    cout << "4. Display List\n";
                    cout << "5. Return to Main Menu\n";
                    cout << "Choose operation (1-5): ";
                    cin >> listChoice;

                    switch (listChoice) {
                        case 1:
                            cout << "Enter value to insert at start: ";
                            cin >> value;
                            myList.prependNode(value);
                            break;
                        case 2:
                            cout << "Enter value to insert at end: ";
                            cin >> value;
                            myList.appendNode(value);
                            break;
                        case 3:
                            cout << "Enter value to remove: ";
                            cin >> value;
                            myList.removeNode(value);
                            break;
                        case 4:
                            myList.showList();
                            break;
                        case 5:
                            cout << "Returning to main menu...\n";
                            break;
                        default:
                            cout << "Invalid choice! Try again.\n";
                    }
                } while (listChoice != 5);
                break;
            }

            // Sorting Operations
            case 2: {
                int elementCount;
                cout << "Enter number of elements: ";
                cin >> elementCount;
                int dataArray[elementCount];
                
                cout << "Enter " << elementCount << " elements: ";
                for (int i = 0; i < elementCount; i++)
                    cin >> dataArray[i];

                cout << "\nChoose sorting method:\n";
                cout << "1. Merge Sort\n2. Quick Sort\n";
                cout << "Enter choice (1-2): ";
                int sortChoice;
                cin >> sortChoice;

                cout << "Original array: ";
                printArray(dataArray, elementCount);

                if (sortChoice == 1) {
                    recursiveMergeSort(dataArray, 0, elementCount - 1);
                    cout << "After Merge Sort: ";
                } else {
                    recursiveQuickSort(dataArray, 0, elementCount - 1);
                    cout << "After Quick Sort: ";
                }
                printArray(dataArray, elementCount);
                break;
            }

            // Binary Search Operation
            case 3: {
                int elementCount, searchValue;
                cout << "Enter number of elements (array must be sorted): ";
                cin >> elementCount;
                int searchArray[elementCount];
                
                cout << "Enter " << elementCount << " sorted elements: ";
                for (int i = 0; i < elementCount; i++)
                    cin >> searchArray[i];

                cout << "Enter value to find: ";
                cin >> searchValue;

                int position = findInSortedArray(searchArray, elementCount, searchValue);
                if (position != -1)
                    cout << "Value " << searchValue << " found at position " << position << endl;
                else
                    cout << "Value " << searchValue << " not found in array\n";
                break;
            }

            // Exit Program
            case 4:
                cout << "Thank you for using the program!\n";
                break;

            default:
                cout << "Invalid selection! Please choose 1-4.\n";
        }
    } while (mainChoice != 4);

    return 0;
}