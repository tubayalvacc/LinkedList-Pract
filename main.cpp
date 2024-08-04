#include "iostream" // Include the input-output stream library

struct Node { // Define the structure for a Node in the linked list
    int data; // Integer data held by the node
    struct Node* next; // Pointer to the next node in the list
};

// Function to insert a node at the front of the linked list
void insertFront(struct Node **head, int data) {
    // Allocate memory for a new node
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));

    // Assign the data to the new node
    newNode->data = data;

    // Set the next pointer of the new node to the current head
    newNode->next = *head;

    // Update the head to point to the new node
    *head = newNode;
}

// Function to delete a node from the front of the linked list
void deleteFront(struct Node *&head) {
    // Temporary pointer to store the current head
    struct Node *temp = head;

    // If the list is empty, print a message and return
    if (head == NULL) {
        std::cout << "Linked List Empty, nothing to delete ";
        return;
    }

    // Print the data of the node being deleted
    std::cout << "\nValue deleted: " << temp->data;

    // Update the head to point to the next node
    head = head->next;

    // Free the memory of the deleted node
    delete temp;
}

// Function to display the linked list
void display(struct Node *node) {
    std::cout << "\n\n"; // Print a new line for formatting

    // Traverse the list and print each node's data
    while (node != NULL) {
        std::cout << node->data << " "; // Print the data
        node = node->next; // Move to the next node
    }
    std::cout << "\n"; // Print a new line at the end
}

// Main function to demonstrate linked list operations
int main() {
    struct Node *head = NULL; // Initialize the head of the linked list to NULL

    // Insert nodes at the front of the list
    insertFront(&head, 6);
    insertFront(&head, 12);
    insertFront(&head, 18);
    insertFront(&head, 76);
    insertFront(&head, 3);
    insertFront(&head, 15);

    // Display the list
    display(head);

    // Delete nodes from the front of the list
    deleteFront(head);
    deleteFront(head);

    // Display the list again
    display(head);

    return 0; // Return 0 to indicate successful execution
}
