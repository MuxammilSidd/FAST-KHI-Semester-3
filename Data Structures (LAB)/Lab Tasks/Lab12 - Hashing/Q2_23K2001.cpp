//23K2001 - Muzammil
#include<iostream>
using namespace std;

class node{
	public:
		string data;
		node* next;
		node(string d){
			data = d;
			next = nullptr;
		}	
};
class hashtable{
	public:
		node** htable;
		const static int size = 5;
		hashtable(){
			htable = new node*[size];
			for(int i=0;i<size;i++){
				htable[i] = nullptr;
			}
		}
		int hash(string key){
			int sum = 0;
			for(int i=0;i<key.length();i++)
				sum += static_cast<int>(key[i]);
			
			return sum%size;    // Division method: h(k) = k mod m
		}
		void print() {
            for (int i = 0; i < size; i++) {
                cout << "Index# " << i << " : ";
                node* current = htable[i];
                while (current) {
                    cout << current->data;
                    current = current->next;
                    if (current) cout << ", ";
                }
                cout << endl;
            }
        }
        void addRecord(){
			string data;
			cout << "\nInput string to add in dictionary: ";
			cin >> data;
			int k = hash(data);
			node* newnode = new node(data);

			if(htable[k] == nullptr)
				htable[k] = newnode;
			else{
				node* current = htable[k];
				while(current->next != nullptr)
					current = current->next;
				current->next = newnode; 
			}
			cout << endl << " Addition successful! " << endl;
		}
		void search(string d){
			for(int i=0;i<size;i++){
				node* current = htable[i];
				while(current){
					if(current->data == d){
						cout << "\"" << d << "\" : found in index# " << i << endl;
						return;
					}
					else
						current= current->next;
				}
			}
			cout << "No such string was found." << endl;  
		}
};

int main(){
    hashtable flex;
	flex.addRecord();
	flex.addRecord();
	flex.addRecord();
    cout<<endl<<"Searching for \"Atif\":"<<endl;
	flex.search("Atif");

    cout<<endl<<"Dictionary:"<<endl;
	flex.print();

	return 0;
}