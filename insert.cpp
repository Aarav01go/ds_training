#include <iostream>

using namespace std;

// ---------- Node Definition ----------
struct Node {
    char data;
    Node* next;
    Node(char d) : data(d), next(nullptr) {}
};

// ---------- Linked List ----------
class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    // Add a node at the front
    void insertFront(char value) {
        Node* node = new Node(value);
        node->next = head;
        head = node;
    }

    // Add a node at the end
    void insertEnd(char value) {
        Node* node = new Node(value);
        if (!head) { head = node; return; }
        Node* curr = head;
        while (curr->next) curr = curr->next;
        curr->next = node;
    }

    // Insert after a given node pointer
    void insertAfter(Node* position, char value) {
        if (!position) return;
        Node* node = new Node(value);
        node->next = position->next;
        position->next = node;
    }

    // Delete the first node that matches 'value'
    void deleteValue(char value) {
        Node* curr = head;
        Node* prev = nullptr;
        while (curr && curr->data != value) {
            prev = curr;
            curr = curr->next;
        }
        if (!curr) return;               // not found
        if (!prev) head = curr->next;    // deleting first node
        else prev->next = curr->next;
        delete curr;
    }

    // Reverse the list in-place
    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        head = prev;
    }

    // Count the nodes
    int size() const {
        int count = 0;
        for (Node* p = head; p; p = p->next) count++;
        return count;
    }

    // Print all nodes
    void print() const {
        for (Node* p = head; p; p = p->next) cout << p->data << ' ';
        cout << '\n';
    }

    // Merge another list to the end of this list
    void merge(LinkedList& other) {
        if (!head) { head = other.head; return; }
        Node* p = head;
        while (p->next) p = p->next;
        p->next = other.head;
        other.head = nullptr; // optional: clear the other list
    }
};

// ---------- Demonstration ----------
int main() {
    LinkedList list1;

    // Build first list: E D C B A
    list1.insertFront('A');
    list1.insertFront('B');
    list1.insertFront('C');
    list1.insertFront('D');
    list1.insertFront('E');

    // Insert '4' after the first node (E)
    list1.insertAfter(list1.head, '4');

    cout << "List after insertion:\n";
    list1.print();

    list1.insertFront('F');
    cout << "After inserting F at front:\n";
    list1.print();

    cout << "Size: " << list1.size() << "\n";

    cout << "Reversed list:\n";
    list1.reverse();
    list1.print();

    list1.deleteValue('4');
    cout << "After deleting '4':\n";
    list1.print();

    // Second list to merge
    LinkedList list2;
    list2.insertEnd('X');
    list2.insertEnd('Y');
    list2.insertEnd('Z');

    cout << "Second list:\n";
    list2.print();

    list1.merge(list2);
    cout << "Merged list:\n";
    list1.print();
}
