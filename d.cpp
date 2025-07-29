#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* link;
    node* pre_link;

    node() {}
    node(int val) {
        data = val;
        link = pre_link = NULL;
    }
};

class doubly_ll {
public:
    node* head;
    node* last;

    doubly_ll() {
        head = last = NULL;
    }

    void insert_front(int val) {
        node* newnode = new node(val);
        if (!head) {
            head = last = newnode;
        } else {
            newnode->link = head;
            head->pre_link = newnode;
            head = newnode;
        }
    }

    void insert_end(int val) {
        node* newnode = new node(val);
        if (!head) {
            head = last = newnode;
        } else {
            last->link = newnode;
            newnode->pre_link = last;
            last = newnode;
        }
    }

    void delete_front() {
        if (!head) {
            cout << "List is Empty" << endl;
            return;
        }
        node* temp = head;
        head = head->link;
        if (head)
            head->pre_link = NULL;
        else
            last = NULL;
        delete temp;
    }

    void delete_end() {
        if (!last) {
            cout << "List is Empty" << endl;
            return;
        }
        node* temp = last;
        last = last->pre_link;
        if (last)
            last->link = NULL;
        else
            head = NULL;
        delete temp;
    }

    void insert_after(int key, int val) {
        node* temp = head;
        while (temp && temp->data != key) {
            temp = temp->link;
        }
        if (!temp)
            return; // key not found

        node* newnode = new node(val);
        newnode->link = temp->link;
        newnode->pre_link = temp;

        if (temp->link)
            temp->link->pre_link = newnode;
        else
            last = newnode;

        temp->link = newnode;
    }

    void display() {
        if (!head) {
            cout << "List is Empty" << endl;
            return;
        }
        node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->link;
        }
        cout << endl;
    }

    void count_nodes() {
        int count = 0;
        node* temp = head;
        while (temp) {
            count++;
            temp = temp->link;
        }
        cout << count << endl;
    }
};

int main() {
    doubly_ll dll;
    int choice;

    while (cin >> choice && choice != 0) {
        switch (choice) {
            case 1: {
                int val;
                cin >> val;
                dll.insert_front(val);
                break;
            }
            case 2: {
                int val;
                cin >> val;
                dll.insert_end(val);
                break;
            }
            case 3:
                dll.delete_front();
                break;
            case 4:
                dll.delete_end();
                break;
            case 5: {
                int key, val;
                cin >> key >> val;
                dll.insert_after(key, val);
                break;
            }
            case 6:
                dll.display();
                break;
            case 7:
                dll.count_nodes();
                break;
            default:
                break;
        }
    }

    return 0;
}
