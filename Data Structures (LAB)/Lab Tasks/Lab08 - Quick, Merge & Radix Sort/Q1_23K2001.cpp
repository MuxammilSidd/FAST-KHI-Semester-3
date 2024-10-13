//23K2001 - Muzammil
#include<iostream>
using namespace std;
class student{
	public:
		string name;
		int score;
		student(string n, int s):name(n),score(s)
		void getData(){
			cout<<"Name: "<<name<<"\t"<<"Score: "<<score<<endl;
		}
};
class node{
	public:
		student std;
		node* next;
		node(student s) : std(s),next(nullptr){}
};
class singleList{
	private:
		node* head;
		node* tail;
	public:
		singleList(){
			head = nullptr;
			tail = nullptr;
		}
		void display(){
			node* temp = head;
			while(temp!=nullptr)
			{
				cout<<temp->getData();
				temp=temp->next;
			}
			cout<<endl;
		}
		
		void insertAtStart(int val)	
		{
			node* n = new node(val);
			n->next=head;
			head = n;
		}
		void insertAtEnd(int val)
		{
			node* temp = head;
			node* n = new node(val);
			if(head == NULL){
				head = n;
				tail = n;
			}
			else{
				tail->next = n;
				tail = n;
			}
		}
		void insertAtIndex(int index,int val){
			node* update = new node(val);
			node* temp = head;
			node* before = nullptr;
			for(int i=0;i<index-1;i++){
				before = temp;
				temp=temp->next;
			}
			before->next = update;
			update->next = temp;
		}
		void deleteNode(int val){
			node* before = nullptr;
			node* temp = head;
			while(temp->getData()!=val){
				before = temp;
				temp = temp->next;
			}
			before->next = (temp->next);
			delete temp;
		}
		int getMax(int n) {  
		   int max = a[0];  
		   for(int i = 1; i<n; i++) {  
		      if(a[i] > max)  
		         max = a[i];  
		   }  
		   return max; //maximum element from the array  
		}  
  
		void countingSort(int a[], int n, int place) // function to implement counting sort  
		{  
		  int output[n + 1];  
		  int count[10] = {0};    
		  
		  // Calculate count of elements  
		  for (int i = 0; i < n; i++)  
		    count[(a[i] / place) % 10]++;  
		      
		  // Calculate cumulative frequency  
		  for (int i = 1; i < 10; i++)  
		    count[i] += count[i - 1];  
		  
		  // Place the elements in sorted order  
		  for (int i = n - 1; i >= 0; i--) {  
		    output[count[(a[i] / place) % 10] - 1] = a[i];  
		    count[(a[i] / place) % 10]--;  
		  }  
		  
		  for (int i = 0; i < n; i++)  
		    a[i] = output[i];  
		}  
		  
		// function to implement radix sort  
		void radixsort(int a[], int n) {  
		   
		  // get maximum element from array  
		  int max = getMax(a, n);  
		  
		  // Apply counting sort to sort elements based on place value  
		  for (int place = 1; max / place > 0; place *= 10)  
		    countingSort(a, n, place);  
		}  
};

int main(){
	
	return 0;
}