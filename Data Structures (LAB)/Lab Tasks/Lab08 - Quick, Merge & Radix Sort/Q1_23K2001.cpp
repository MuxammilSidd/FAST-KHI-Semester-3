//23K2001 - Muzammil
#include<iostream>
using namespace std;
class student{
	public:
		string name;
		int score;
		student(){}
		student(string n, int s):name(n),score(s){}
		void getData(){
			cout<<"Name: "<<name<<"\t"<<"Score: "<<score<<endl;
		}
		void operator =(const student s){
			this->name = s.name;
			this->score = s.score;
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
				temp->std.getData();
				temp=temp->next;
			}
			cout<<endl;
		}
		void insertAtEnd(student s){
			node* temp = head;
			node* n = new node(s);
			if(head == NULL){
				head = n;
				tail = n;
			}
			else{
				tail->next = n;
				tail = n;
			}
		}
		void deleteNode(string n,int s){
			node* before = nullptr;
			node* temp = head;

			if(temp != nullptr && temp->std.name == n && temp->std.score == s) {
				head = temp->next;
				delete temp;
				if(head == nullptr) 
					tail = nullptr;
				return;
			}

			while(temp!=nullptr){
				if(temp->std.name==n && temp->std.score==s){
					before->next = (temp->next);
					delete temp;
					return;
				}
				before = temp;
				temp = temp->next;
			}
			cout<<"Record was not found!"<<endl;
		}
		student getMax(){
			node* temp = head;
			student m = head->std;

			while(temp != nullptr){
				if (temp->std.score > m.score) 
					m = temp->std;
				temp = temp->next;
			}
			return m;
    	} 
		int numOfnodes(){
			node* temp = head;
			int c=0;
			while(temp!=nullptr){
				c++;
				temp = temp->next;
			}
			return c;
		}
		void countingSort(int place){
			int n = numOfnodes();
			student* output = new student[n];
			int count[10] = {0};

			node* temp = head;
			while (temp != nullptr){
				count[(temp->std.score / place) % 10]++;
				temp = temp->next;
			}
			for (int i = 1; i < 10; i++)
				count[i] += count[i - 1];
			temp = head;
			for (int i = n - 1; i >= 0; i--) {
				output[count[(temp->std.score / place) % 10] - 1] = temp->std;
				count[(temp->std.score / place) % 10]--;
				temp = temp->next;
			}
			temp = head;
			for (int i = 0; i < n; i++) {
				temp->std = output[i];
				temp = temp->next;
			}
			delete[] output;
		}

		void radixSort() {
			node* maxNode = head;
			node* temp = head;
			while (temp != nullptr) {
				if (temp->std.score > maxNode->std.score) 
					maxNode = temp;
				temp = temp->next;
			}

			int maxScore = maxNode->std.score;
			for (int place = 1; maxScore / place > 0; place *= 10)
				countingSort(place);
		}

		node* getMiddle(node* start, node* end){
			if(start == nullptr) 
				return nullptr;

			node* slow = start;
			node* fast = start;
			while (fast != end && fast->next != end) {
				slow = slow->next;
				fast = fast->next->next;
			}
			return slow;
		}
		node* binarySearch(string n,int s){
			node* left = head;
			node* right = nullptr;

			while (left != right) {
				node* mid = getMiddle(left, right);
				if (mid == nullptr) return nullptr;

				if (mid->std.name==n && mid->std.score==s)
					return mid;
				else if (mid->std.score < s)
					left = mid->next;
				else
					right = mid;
			}
			return nullptr;
		}

};

int main(){
	student ayaan("Ayaan", 90);
    student zameer("Zameer", 60);
    student sara("Sara", 70);
    student sohail("Sohail", 30);
    student ahmed("Ahmed", 20);

	singleList flex;
	flex.insertAtEnd(ayaan);
	flex.insertAtEnd(zameer);
	flex.insertAtEnd(sara);
	flex.insertAtEnd(sohail);
	flex.insertAtEnd(ahmed);
	cout<<"Your list: "<<endl;
	flex.display();

	cout<<"Applying Radix Sort!"<<endl<<endl;
	flex.radixSort();
	cout<<"Your list: "<<endl;
	flex.display();

	string n;
	int s;
	cout<<"Enter name & score to search:"<<endl;
	cin>>n>>s;
	node* src = flex.binarySearch(n,s);
	if(src){
		cout<<"Record with Name: "<<src->std.name<<", Score: "<<src->std.score<<" found!"<<endl;
		flex.deleteNode(src->std.name,src->std.score);
		cout<<"Successfully deleted."<<endl<<endl;
	}
	else
		cout<<"No record found!"<<endl<<endl;

	cout<<"Your list:"<<endl;
	flex.display();
	return 0;
}