//23K2001 - Muzammil
#include<iostream>
using namespace std;

class Document{
    private:
    char *text;
    int length;

    public:
    Document(){ text = NULL;
    length = 0;}
    Document(string t){ length = t.size();
        text = new char[length];

        for(int i=0;i<length;i++)
        text[i] = t[i];
    }

    Document(Document &obj) {
    this->length = obj.length;
    this->text = new char[this->length];
    for (int i=0; i<this->length;i++)
        this->text[i] = obj.text[i];
    }

    void display(){ 
        for(int i=0;i<length;i++)
        cout<<text[i];
        
        cout<<endl;
    }
    void replace(string t){  
        delete[] this->text;

        length = t.size();
        text = new char[length];

        for(int i=0;i<length;i++)
        text[i] = t[i];
     }

    Document& operator=(Document &obj) {
    delete[] text;

    length = obj.length;
    text = new char[length];
    for (int i=0; i<length; i++)
        text[i] = obj.text[i];

    return *this;
}
    ~Document(){ delete[] text;}
};

int main(){
    char s1[] = "This is an important file."; 
    Document file1(s1);
    cout<<"File1: ";
    file1.display();
    
    Document file2(file1);
    Document file3;
    file3 = file1;
    cout<<"File2: ";
    file2.display();
    cout<<"File3: ";
    file3.display();

    char s2[] = "File has been edited.";
    file1.replace(s2);
    cout<<"File1: ";
    file1.display();
    cout<<"File2: ";
    file2.display();
    cout<<"File3: ";
    file3.display();
    return 0;
}