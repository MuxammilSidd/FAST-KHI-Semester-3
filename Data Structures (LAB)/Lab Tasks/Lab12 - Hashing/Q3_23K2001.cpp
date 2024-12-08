//23K2001 - Muzammil
#include<iostream>
#include<list>
using namespace std;

class node{
	public:
	    int value;
    	node(int v) :value(v) {}
};
class hashing{
	public:
		list<node>* htable;
		int size;
		hashing(int s){
			size = s;
			htable = new list<node>[size];
		}
		int hashfunction(int value){ return value%size; }
		~hashing(){ delete[] htable; }

		void insert(int value) {
        	int index = hashfunction(value);
        	htable[index].emplace_back(value);
	    }

    	void deleteKey(int key){
        	int index = hashfunction(key);
        	auto& bucket = htable[index];
        	for(auto it = bucket.begin(); it != bucket.end(); ++it){
            	if (it->value == key) {
                	bucket.erase(it);
                	cout << "Deleted key: " << key << endl;
                	return;
            	}
        	}
        	cout << "Key not found: " << key << endl;
    	}

    	int search(int key) {
        	int index = hashfunction(key);
        	auto& bucket = htable[index];
        	for (const auto& node : bucket) {
            	if (node.value == key) {
            		cout << "Key found! " << endl;
                	return node.value;
            	}
        	}
            cout << "Key not found" << endl;
            return -1;
		}
    
    	void display() {
            for (int i = 0; i < size; ++i) {
                cout << "Index# " << i << ": ";
                bool first = true;
                for (const auto& node : htable[i]) {
                    if (!first) cout << ", ";
                    cout << node.value;
                    first = false;
                }
                cout << endl;
            }
        }
};

int main(){
	hashing flex(10);
	flex.insert(45);
    flex.insert(32);
    flex.insert(67);
    flex.insert(11);
    flex.insert(99);
    flex.insert(21);

    cout<<"Searching for '67': ";
    flex.search(67);
    cout<<endl<<"Searching for '100': ";
    flex.search(100);
    cout<<endl<<"Deleting key '32': "<<endl;
    flex.deleteKey(32);
    cout<<endl;
    flex.display();
	return 0;
}