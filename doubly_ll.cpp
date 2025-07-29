# include <iostream>
using namespace std;
// basic structure of dll
class node
{
    public:
    int data;
    node*link;
    node*pre_link;
    node(){}
        node(int val)
        {
           data=val;
           link=pre_link=NULL;
        }
    
};
class doubly_ll
{
    public:
    node*head;
    node*last;
    doubly_ll()
    {
        head=last=NULL;
    }
    //push_front
    void push_front(int val)
    {
        // create a new node
        node *newnode= new node(val);
        // ll is empty
        if(head==NULL)
        {
            head=last=newnode;
            return;
        }
        else{
            newnode->link=head;
            head->pre_link=newnode;
            head=newnode;

        }
    }
    //dispaly
    void display()
    {
        node *temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->link;
        }
        cout<<endl;
    }
    //push_back
    void push_back(int val)
    {
        node *newnode= new node(val);
        if(head==NULL)
        {
            head=last=newnode;
            return;
        }
        else{
            last->link=newnode;
            newnode->pre_link=last;
            last=newnode;
        }
    }
    // pop_front
    void pop_front()
    {
        if(head==NULL)
        {
            cout<<"List is empty"<<endl;
            return;
        }
        node*temp=head;
        head=head->link;
        if(head!=NULL)
        {
            head->pre_link=NULL;
        }
        temp->link=NULL;
        delete temp;
    }
// pop_end
 void pop_end()
 {
    node*temp=last;
    last=last->pre_link;
    if(last!=NULL)
    {
        last->link=NULL;
    }
    temp->pre_link=NULL;
    delete temp;
}
// 
 
};
int main()
{
    doubly_ll ll;
    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);
    ll.display(); 
    ll.push_back(40);
    ll.push_back(50);
    ll.display();
    ll.pop_front();
    ll.display();
    return 0;
}
