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

    void display() {
        node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->link) cout << " ";
            temp = temp->link;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;

    doubly_ll dll;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        dll.insert_end(val);
    }

    dll.display();

    return 0;
}
