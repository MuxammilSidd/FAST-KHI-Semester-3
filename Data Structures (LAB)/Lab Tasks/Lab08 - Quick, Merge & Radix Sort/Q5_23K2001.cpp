//23K2001 - Muzammil
#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;

        node() : next(nullptr) {}
        node(int d) : data(d), next(nullptr){}
        void setNext(node* n){ next = n; }
        void setData(int d){ data = d; }
};
class singleList{
    public:
        node* head;
        node* tail;
        singleList() : head(nullptr), tail(nullptr){}
        void display(){
            if(!head){
                cout<<"List is empty!"<<endl;
                return;
            }
            cout<<"Elements in the list are:"<<endl;
            node* temp = head;
            while(temp){
                cout<<temp->data<<"\t";
                temp = temp->next;
            }
            cout<<endl;
        }
        void insertAtEnd(int d){
            node* n = new node(d);
            if(!head){
                head = n;
                tail = n;
            }
            else{
                tail->next = n;
                tail = n;
            }
        }
        void deleteNode(int d){
            if(!head){
                cout<<"List is empty!"<<endl;
                return;
            }
            node* before = nullptr;
            node* temp = head;
            while(temp->data!=d){
                before = temp;
                temp = temp->next;
            }
            if(!temp){
                cout<<"Value "<<d<<" not found in the list."<<endl;
                return;
            }
            if(temp == head) 
                head = head->next;
            else
                before->next = temp->next;
            
            delete temp;
            cout<<"node with value "<<d<<" deleted.\n";
        }
        void swap(node* a, node* b){
            if (a == b) return;
            int temp = a->data;
            a->data = b->data;
            b->data = temp;
        }

        node* partition(node* start, node* end){
            int pivot = end->data;
            node* i = start;
            node* j = start;

            while (j != end) {
                if (j->data < pivot) {
                    swap(i, j);
                    i = i->next;
                }
                j = j->next;
            }
            swap(i, end);
            return i;
        }
        void quickSort(node* start, node* end) {
            if(head == nullptr || head->next == nullptr){
                cout<<"Quick sort cannot be applied on this list!"<<endl;
                return;
            }

            if(start != end){
                node* pivot = partition(start, end);

                node* temp = start;
                while(temp && temp->next != pivot)
                    temp = temp->next;
                
                if (temp != nullptr)
                    quickSort(start, temp);
                quickSort(pivot->next, end);
            }
        }
};
  
int main(){  
    singleList flex1,flex2,flex3;
    cout<<"Empty list (flex1):"<<endl;
    cout<<"Applying quick sort.."<<endl<<endl;
    flex1.quickSort(flex1.head,flex1.tail);

    flex2.insertAtEnd(5);
    cout<<endl<<"List with single node (flex2):"<<endl;
    flex2.display();
    cout<<"Applying quick sort.."<<endl<<endl;
    flex2.quickSort(flex2.head,flex2.tail);

    flex3.insertAtEnd(10);
    flex3.insertAtEnd(7);
    flex3.insertAtEnd(8);
    flex3.insertAtEnd(9);
    flex3.insertAtEnd(1);
    flex3.insertAtEnd(5);
    flex3.insertAtEnd(3);
    cout<<endl<<"Sample list (flex3):"<<endl;
    flex3.display();
    cout<<"Applying quick sort.."<<endl<<endl;
    flex3.quickSort(flex3.head,flex3.tail);
    flex3.display();
    return 0;
}  
