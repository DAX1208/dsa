#include <iostream>
using namespace std;
class node
{
public :
int data;
node*link;
node(){}
node(int val)
{
    data=val;
    link=NULL;
}
};
class list
{
    public:
    node*head;// point to first element
    node*last; //point tolast element
    list()
    {
        head=last=NULL;
    }
    // push_front
    void push_front(int val)
    {
        // create new node
        node *newnode= new node(val);
        if(head ==NULL)
        {
            head =last= newnode;
        }
        else{
            newnode->link=head;
            head=newnode;
        }
    }
    // push_back
    void push_back(int val)
    {
        // create new node 
        node *newnode= new node(val);
        if(head ==NULL)
        {
            head =last=newnode;
        }
        else
        {
            last->link = newnode;
            last = newnode;
        }
    }
    // insert any position
    void insert(int val, int pos)
    {
        if(pos<0)
        {
            cout<<"Invaild choice "<<endl;
            return;
        }
        if(pos==0)
        {
            push_front(val);
             return;
        }
        node* newnode=new node(val);
        node*temp=head;
        for(int i=0; i<pos-1 && temp!=NULL; i++)
        {
            temp=temp->link;
        }
        newnode->link = temp->link;
        temp->link = newnode;
    }
    // pop_front
    void pop_front()
    {
        // check ll is empty or not
        if(head ==NULL)
        {
            cout<<"ll is empty"<<endl;
            return;
        }
        node*temp=head;
        head=head->link;
        delete temp;
    }
    //pop_end
    void pop_end()
    {
        // check ll is empty or not
        if(head ==NULL)
        {
            cout<<"ll is empty"<<endl;
            return;
        }
        node*temp=head;
        while(temp->link!=last)
        {
            temp=temp->link;
        }
        temp->link=NULL;
        delete last;
        last=temp;
    }
     // display
     void display()
     {
        if(head ==NULL)
        {
            cout<<"ll is empty"<<endl;
            return;
        }
        node*temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->link;
        }
        cout<<endl;
     }
     // search
     void search(int key)
     {
        if(head==NULL)
        {
            cout<<"ll is empty"<<endl;
            return;
        }
        node*temp=head;
        int pos=0;
        while(temp!=NULL)
        {
            if(temp->data ==key)
            {
                cout<<"element is found at position"<<pos<<endl;
                return;
            }
            temp=temp->link;
            pos++;
        }
     }
};
int main()
{
    list l;
    int choice, val, pos;
    while (true) {
        cout << "1. Push Front\n2. Push Back\n3. Insert\n4. Pop Front\n5. Pop End\n6. Display\n7. Search\n8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push front: ";
                cin >> val;
                l.push_front(val);
                break;
            case 2:
                cout << "Enter value to push back: ";
                cin >> val;
                l.push_back(val);
                break;
            case 3:
                cout << "Enter value and position to insert: ";
                cin >> val >> pos;
                l.insert(val, pos);
                break;
            case 4:
                l.pop_front();
                break;
            case 5:
                l.pop_end();
                break;
            case 6:
                l.display();
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> val;
                l.search(val);
                break;
            case 8:
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}