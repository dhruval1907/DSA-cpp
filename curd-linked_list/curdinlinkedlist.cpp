#include<iostream>
using namespace std;

// Node class for Linked List
class Node {
  public:
    int data;     // Stores data
    Node* next;   // Pointer to next node
    
    // Constructor to initialize a node with value
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// DMA class to handle Linked List operations
class DMA {
  private:
    Node* head;   // Pointer to head (start) of the list

  public:
    // Constructor initializes empty list
    DMA() {
        head = nullptr;
    }
    
    // Insert a node at the beginning of the list
    void insert(int data) {
        Node* newNode = new Node(data); // Create a new node
        newNode->next = head;           // Point new node to current head
        head = newNode;                 // Make new node the new head
    }
    
    // Search for a node with given key
    bool search(int key) {
        Node* temp = head; // Start from head
        while (temp != nullptr) {
            if (temp->data == key) { // If match found
                cout << "\nElement " << key << " found in list.";
                return true;
            }
            temp = temp->next; // Move to next node
        }
        cout << "\nElement " << key << " not found.";
        return false;
    }

    // Display the linked list
    void display() {
        Node* temp = head; 
        while (temp != nullptr) {
            cout << temp->data << " -> "; // Print data
            temp = temp->next;
        }
        cout << "Null" << endl; // End of list
    }
    
    // Reverse the linked list
    void reverse() {
        Node* prev = nullptr; 
        Node* curr = head;     
        Node* next = nullptr;  

        // Iterative reversal of linked list
        while (curr != nullptr) {
            next = curr->next;   // Store next node
            curr->next = prev;   // Reverse current node's link
            prev = curr;         // Move prev one step ahead
            curr = next;         // Move curr one step ahead
        }

        head = prev; // New head after reversal
        cout << endl << "List reversed." << endl;
    }
    
    // Delete a node with given key
    void delete_node(int key) {
        if (head == nullptr) { // If list is empty
            cout << endl << "List is empty." << endl;
            return;
        }

        // If node to delete is the head node
        if (head->data == key) {
            Node* temp = head;
            head = head->next; // Move head to next
            delete temp;       // Delete old head
            cout << endl << "Node deleted." << endl;
            return;
        }

        // Traverse list to find the node before the one to delete
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != key) {
            temp = temp->next;
        }

        // If key not found in list
        if (temp->next == nullptr) {
            cout << endl << "Value not found." << endl;
            return;
        }

        // Delete node
        Node* del = temp->next;         // Node to delete
        temp->next = temp->next->next;  // Bypass deleted node
        delete del;                     // Free memory
        cout << endl << "Node deleted." << endl;
    }
};


int main() {
    DMA a;  // Create linked list object
    int choice, value;

    // Menu-driven program
    do {
        cout << "\n--- Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Search Element\n";
        cout << "3. Delete Node\n";
        cout << "4. Reverse List\n";
        cout << "5. Display List\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: // Insert
            cout << "Enter value: ";
            cin >> value;
            a.insert(value);
            break;

        case 2: // Search
            cout << "Enter key to search: ";
            cin >> value;
            a.search(value);
            break;

        case 3: // Delete
            cout << "Enter value to delete: ";
            cin >> value;
            a.delete_node(value);
            break;

        case 4: // Reverse list
            a.reverse();
            break;

        case 5: // Display list
            a.display();
            break;

        case 6: // Exit
            cout << "Exiting program...\n";
            break;

        default: // Invalid input
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6); // Loop until exit option

    return 0;
}

