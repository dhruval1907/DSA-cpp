#include<iostream>
using namespace std;

// Sorting Algorithms
void selectionSort(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        int minvalue = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[minvalue]){
                minvalue = j;
            }
        }
        swap(arr[i], arr[minvalue]);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int L[n1], R[n2];
    
    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Searching Algorithms
int linearSearch(int arr[], int n, int target){
    for(int i = 0; i < n; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int n, int target){
    int left = 0, right = n - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return -1;
}

// Utility Functions
void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void inputArray(int arr[], int &n, const string& purpose) {
    cout << "Enter the number of elements for " << purpose << ": ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

bool isSorted(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        if(arr[i] > arr[i+1]) {
            return false;
        }
    }
    return true;
}

// Menu Functions
void displayMainMenu() {
    cout << "\n===== MAIN MENU =====" << endl;
    cout << "1. Use Sorting Algorithms" << endl;
    cout << "2. Use Searching Algorithms" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice (1-3): ";
}

void displaySortMenu() {
    cout << "\n===== SORTING ALGORITHMS =====" << endl;
    cout << "1. Selection Sort" << endl;
    cout << "2. Merge Sort" << endl;
    cout << "3. Back to Main Menu" << endl;
    cout << "Enter your choice (1-3): ";
}

void displaySearchMenu() {
    cout << "\n===== SEARCHING ALGORITHMS =====" << endl;
    cout << "1. Linear Search" << endl;
    cout << "2. Binary Search" << endl;
    cout << "3. Back to Main Menu" << endl;
    cout << "Enter your choice (1-3): ";
}

int main() {
    int sortArray[100];  // Separate array for sorting
    int searchArray[100]; // Separate array for searching
    int sortSize = 0;     // Size of sorting array
    int searchSize = 0;    // Size of searching array
    int choice, target, result;
    
    do {
        displayMainMenu();
        cin >> choice;
        
        switch(choice) {
            case 1: // Sorting Algorithms
                if(sortSize == 0) {
                    cout << "\nNo data for sorting! Please enter data first." << endl;
                    inputArray(sortArray, sortSize, "sorting");
                }
                
                int sortChoice;
                do {
                    displaySortMenu();
                    cin >> sortChoice;
                    
                    int tempArr[100];
                    for(int i = 0; i < sortSize; i++) tempArr[i] = sortArray[i];
                    
                    switch(sortChoice) {
                        case 1:
                            cout << "\n=== SELECTION SORT ===" << endl;
                            cout << "Original array: ";
                            printArray(tempArr, sortSize);
                            selectionSort(tempArr, sortSize);
                            cout << "After Selection Sort: ";
                            printArray(tempArr, sortSize);
                            break;
                            
                        case 2:
                            cout << "\n=== MERGE SORT ===" << endl;
                            cout << "Original array: ";
                            printArray(tempArr, sortSize);
                            mergeSort(tempArr, 0, sortSize-1);
                            cout << "After Merge Sort: ";
                            printArray(tempArr, sortSize);
                            break;
                            
                        case 3:
                            cout << "Returning to main menu..." << endl;
                            break;
                            
                        default:
                            cout << "Invalid choice!" << endl;
                    }
                    
                    if(sortChoice != 3) {
                        cout << "\nPress Enter to continue...";
                        cin.ignore();
                        cin.get();
                    }
                    
                } while(sortChoice != 3);
                break;
                
            case 2: // Searching Algorithms
                if(searchSize == 0) {
                    cout << "\nNo data for searching! Please enter data first." << endl;
                    inputArray(searchArray, searchSize, "searching");
                }
                
                int searchChoice;
                do {
                    displaySearchMenu();
                    cin >> searchChoice;
                    
                    int tempArr[100];
                    for(int i = 0; i < searchSize; i++) tempArr[i] = searchArray[i];
                    
                    switch(searchChoice) {
                        case 1: // Linear Search
                            cout << "\n=== LINEAR SEARCH ===" << endl;
                            cout << "Array: ";
                            printArray(tempArr, searchSize);
                            cout << "Enter number to search: ";
                            cin >> target;
                            result = linearSearch(tempArr, searchSize, target);
                            if(result != -1) {
                                cout << "Element found at index " << result << endl;
                            } else {
                                cout << "Element not found" << endl;
                            }
                            break;
                            
                        case 2: // Binary Search
                            cout << "\n=== BINARY SEARCH ===" << endl;
                            cout << "NOTE: Requires sorted array in ascending order!" << endl;
                            
                            if(!isSorted(tempArr, searchSize)) {
                                cout << "Your array is not sorted. Please enter a new sorted array:" << endl;
                                inputArray(searchArray, searchSize, "binary search (sorted)");
                                for(int i = 0; i < searchSize; i++) tempArr[i] = searchArray[i];
                                
                                // Auto-sort if still not sorted
                                if(!isSorted(tempArr, searchSize)) {
                                    cout << "Auto-sorting your array..." << endl;
                                    selectionSort(tempArr, searchSize);
                                    cout << "Sorted array: ";
                                    printArray(tempArr, searchSize);
                                }
                            } else {
                                cout << "Array is already sorted. Good!" << endl;
                            }
                            
                            cout << "Sorted Array: ";
                            printArray(tempArr, searchSize);
                            cout << "Enter number to search: ";
                            cin >> target;
                            result = binarySearch(tempArr, searchSize, target);
                            if(result != -1) {
                                cout << "Element found at index " << result << endl;
                            } else {
                                cout << "Element not found" << endl;
                            }
                            break;
                            
                        case 3:
                            cout << "Returning to main menu..." << endl;
                            break;
                            
                        default:
                            cout << "Invalid choice!" << endl;
                    }
                    
                    if(searchChoice != 3) {
                        cout << "\nPress Enter to continue...";
                        cin.ignore();
                        cin.get();
                    }
                    
                } while(searchChoice != 3);
                break;
                
            case 3:
                cout << "Thank you! Goodbye!" << endl;
                break;
                
            default:
                cout << "Invalid choice! Please enter 1-3." << endl;
        }
        
    } while(choice != 3);
    
    return 0;
}