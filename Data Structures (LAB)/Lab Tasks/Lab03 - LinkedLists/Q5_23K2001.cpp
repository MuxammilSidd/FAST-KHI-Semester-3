//23K2001 - Muzammil
#include<iostream>
using namespace std;

class node{
    public:
    char val;
    node* next;
    node(char v) : val(v),next(nullptr) {}
};

bool isPalindrome(node* head)
{
    node* slow=head;
    node* fast=head;
    while(fast->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    
    node* mid=slow;
    slow=slow->next;
    node* ptr;
    
    while(slow!=nullptr)
    {
        ptr=head;
        while(ptr->next!=mid)
        {
            ptr=ptr->next;
        }
        if(ptr->val!=slow->val)
        return false;
        mid=ptr;
        slow=slow->next;
    }
    return true;
}

int main()
{
    node* head=new node('1');
    head->next=new node('0');
    head->next->next=new node('2');
    head->next->next->next=new node('0');
    head->next->next->next->next=new node('1');
    cout<<(isPalindrome(head) ? "True" : "False")<<endl;
    return 0;
}