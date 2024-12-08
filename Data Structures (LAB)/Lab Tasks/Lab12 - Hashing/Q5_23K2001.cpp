//23K2001 - Muzammil
#include<iostream>
using namespace std;

const static int size = 15;

class student{
	public:
		int rollnum;
		string name;
		student(int r,string n):rollnum(r),name(n){}
		student():rollnum(0),name(""){}
};
class StudentHashTable{
	public:
		student* table;
		StudentHashTable(){
			table = new student[size];
			for(int i=0;i<size;i++)
				table[i].rollnum = -1;
		}
        int hash(int num){ return num%size; }

        void insertRecord(string name,int rollnum){
            student newstudent(rollnum,name);
            int key = hash(rollnum);
            for(int i=0;i<size;i++){
                int probe = (key + (i*i) ) %size;
                if(table[probe].rollnum == -1 || table[probe].rollnum == -2){
                    table[probe] = newstudent;
                    cout << "\nAdded student \""<<name<<"\" Rollnum: "<<rollnum<< endl;
                    return;
                }
            }
            cout << "\nNo space in table available!" << endl;
        }

        void display(){
            cout<<endl;
            for(int i=0;i<size;i++){
                cout << "Index# " << i << ": ";
                if(table[i].rollnum == -1)
                    cout << "-";
                else
                    cout <<  "Name : " << table[i].name << " Roll#: " << table[i].rollnum;
                cout << endl;
            }
        }

        void searchRecord(int id){
            int key = hash(id);
            for(int i=0;i<size;i++){
                int probe = (key + (i*i) ) %size;
                if(table[probe].rollnum == id){
                    cout<<"Record found!"<<endl;
                    cout << "Name: " << table[probe].name << " Roll#: " << table[probe].rollnum << endl;
                    return;
                }
            }
            cout << "Record not found." << endl;
        }
};

int main(){
	StudentHashTable flex;
	flex.insertRecord("Muzammil",2001);
	flex.insertRecord("Ali",2085);
	flex.insertRecord("Ahmed",1687);
	flex.display();

    cout<<endl<<"Searching for Roll#: 2001"<<endl;
	flex.searchRecord(2001);
    cout<<endl<<"Searching for Roll#: 2024"<<endl;
	flex.searchRecord(2024);
	return 0;
}