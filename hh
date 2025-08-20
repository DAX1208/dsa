#include <iostream>
using namespace std;


class Node {
public:
    int bookID;
    Node* next;

    Node(int id) {
        bookID = id;
        next = nullptr;
    }
};


class HashTable {
private:
    Node* table[10];

   
    int hashFunction(int x) {
        return (x * 7) % 10;
    }

public:
    // Constructor
    HashTable() {
        for (int i = 0; i < 10; i++) {
            table[i] = nullptr;
        }
    }

    // Insert book ID into the hash table
    void insert(int bookID) {
        int index = hashFunction(bookID);
        Node* newNode = new Node(bookID);

        // If no element at index, directly insert
        if (table[index] == nullptr) {
            table[index] = newNode;
        } else {
            // Else append at the end of the linked list
            Node* current = table[index];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Display hash table
    void display() {
        for (int i = 0; i < 10; i++) {
            cout << i << " ->";
            Node* current = table[i];
            while (current != nullptr) {
                cout << " " << current->bookID;
                current = current->next;
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable ht;
    int choice;

    while (cin >> choice)
