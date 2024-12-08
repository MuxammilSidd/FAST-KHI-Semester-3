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
		void insert(string key,string data){
			int k = hash(key);
			node* newnode = new node(data);
			if(htable[k] == nullptr)
				htable[k] = newnode;
			else{
				node* current = htable[k];
				while(current->next != nullptr)
					current = current->next;
				
				current->next = newnode; 
			}
		}
		void display() {
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
};

int main(){
	hashtable flex;
	flex.insert("A","aaaaa");
	flex.insert("B","bbbbb");
	flex.insert("C","ccccc");
	flex.insert("A","zzzzz");
	flex.display();
	return 0;
}