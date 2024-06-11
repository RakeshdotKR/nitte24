// #include<queue>
// #include<iostream>
// using namespace std;
// int main()
// {
//     queue<int> q;
//     q.push(10);
//     q.push(20);
//     q.push(30);
//     cout<<"Size:"<<q.size()<<endl;
//     cout<<"Front:"<<q.front()<<endl;
//     cout<<"Back:"<<q.back()<<endl;
//     q.empty();
//     q.pop();//remove elements
// }

//Queue Pair
#include<queue>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void printpair(pair<int,int> pr){
    int first = pr.first;
    int second = pr.second;
    cout<<"First pair"<<first;
    cout<<"Second pair"<<second;
}
int main(){
    queue<pair<int,int>> qp; 
    qp.push({10,50});
    qp.push({20,60});

    printpair(qp.front());
    //qp.pop();
}


////*********** Linked List ***********/

#include <iostream>

using namespace std;

// Define the structure for a node in the linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class LinkedList {
private:
    ListNode* head;

public:
    // Constructor to initialize the head pointer
    LinkedList() : head(nullptr) {}

    // Function to insert a new node at the beginning of the linked list
    void insertFront(int val) {
        // Create a new node with the given value
        ListNode* newNode = new ListNode(val);
        // Update the next pointer of the new node to point to the current head
        newNode->next = head;//existing head node
        // Update the head pointer to point to the new node
        head = newNode;
    }

    // Function to insert a new node at the end of the linked list
    void insertEnd(int val) {
        // Create a new node with the given value
        ListNode* newNode = new ListNode(val);
        // If the list is empty, set the new node as the head
        if (!head) {
            head = newNode;
            return;
        }
        // Traverse the list to find the last node
        ListNode* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        // Update the next pointer of the last node to point to the new node
        temp->next = newNode;
    }

    // Function to delete a node with a given value from the linked list
    void deleteNode(int val) {
        // If the list is empty, return
        if (!head) {
            return;
        }
        // If the node to be deleted is the head, update the head pointer
        if (head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        // Traverse the list to find the node with the given value
        ListNode* prev = head;
        ListNode* curr = head->next;
        while (curr) {
            if (curr->val == val) {
                prev->next = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    // Function to print the elements of the linked list
    void printList() {
        // Traverse the list and print each element
        ListNode* temp = head;
        while (temp) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to clear the linked list (delete all nodes)
    void clear() {
        // Traverse the list and delete each node
        ListNode* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    // Create an instance of the LinkedList class
    LinkedList myList;

    // Insert elements at the front
    myList.insertFront(3);
    myList.insertFront(2);
    myList.insertFront(1);

    // Print the list
    cout << "List after insertFront: ";
    myList.printList();

    // Insert elements at the end
    myList.insertEnd(4);
    myList.insertEnd(5);

    // Print the list
    cout << "List after insertEnd: ";
    myList.printList();

    // Delete an element
    myList.deleteNode(3);

    // Print the list
    cout << "List after deleteNode(3): ";
    myList.printList();

    // Clear the list
    myList.clear();

    // Print the list
    cout << "List after clear: ";
    myList.printList();

    return 0;
}
