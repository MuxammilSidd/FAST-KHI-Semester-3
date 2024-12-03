#include<iostream>
#include<cmath>
using namespace std;
//-------------------------------LINKED LISTS-------------------------------------//
//Generalized singlyListNode Class
template<class T>
class singlyListNode{
    public:
        T data;
        singlyListNode* next;

        singlyListNode() : next(nullptr) {}
        singlyListNode(T d) : data(d), next(nullptr){}
        T getData(){ return data; }
        singlyListNode<T>* getNext(){ return next; }
        void setNext(singlyListNode<T>* n){ next = n; }
        void setData(T d){ data = d; }
};
//Generalized Singly Linked List Class
template<class T>
class singleList{
    public:
        singlyListNode<T>* head;
        singlyListNode<T>* tail;
        singleList() : head(nullptr), tail(nullptr){}
        void display(){
            if(!head){
                cout<<"List is empty!"<<endl;
                return;
            }
            singlyListNode<T>* temp = head;
            while(temp){
                cout<<temp->getData()<<"\t";
                temp = temp->getNext();
            }
            cout<<endl;
        }

        void insertAtStart(T d){
            singlyListNode<T>* n = new singlyListNode<T>(d);
            n->next = head;
            head = n;
        }
        void insertAtEnd(T d){
            singlyListNode<T>* n = new singlyListNode<T>(d);
            if(!head){
                head = n;
                tail = n;
            }
            else{
                tail->next = n;
                tail = n;
            }
        }
        void insertAtIndex(T val, int index){
            if (index < 0) {
                cout << "Invalid index!" << endl;
                return;
            }
            if (index == 0) {
                insertAtStart(val);
                return;
            }
            singlyListNode<T>* update = new singlyListNode<T>(val);
			singlyListNode<T>* temp = head;
			singlyListNode<T>* before = nullptr;
			for(int i=0;temp != nullptr && i<index-1;i++){
				before = temp;
				temp=temp->next;
			}
            if (!temp) {
                cout << "Index out of bounds!" << endl;
                delete update;
                return;
            }
			before->next = update;
			update->next = temp;
        }
        void deleteNode(T d){
            if(!head){
                cout<<"List is empty!"<<endl;
                return;
            }
            singlyListNode<T>* before = nullptr;
            singlyListNode<T>* temp = head;
            while(temp->getData()!=d){
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
            cout<<"singlyListNode with value "<<d<<" deleted.\n";
        }
        void rotateList(int e) {
            if (head == nullptr || e <= 0) { return; }

            singlyListNode<T>* temp = head;
            singlyListNode<T>* before = nullptr;
            int n=1;
            while(temp->next!=nullptr){
                temp=temp->next;
                n++;
            }
            e=e%n;
            if(e==0){ return; }
            
            temp=head;
            for (int i=0;i<e;i++){
                before = temp;
                temp = temp->next;
            }
            singlyListNode<T>* start = temp;
            before->next = nullptr;

            singlyListNode<T>* end = start;
            while (end->next != nullptr)
                end = end->next;

            end->next = head;
            head = start;
        }
        void check(T val){
			singlyListNode<T>* temp = head;
			while(temp!=nullptr && temp->getData()!=val)
				temp = temp->next;
			
			if(temp==nullptr)
				cout<<"No singlyListNode was found with value: "<<val<<endl;
			else
				cout<<"singlyListNode with value: "<<val<<" is present in the list."<<endl;
		}
        void sort(){        //Ascending order
			if (head==nullptr || head->next==nullptr) return;
			bool swapped;
			do{
				swapped = false;
				singlyListNode<T>* current = head;
				singlyListNode<T>* prev = nullptr;
				
				while(current!=nullptr && current->next!=nullptr) {
					if(current->getData() > current->next->getData()){
						T temp = current->getData();
						current->setData(current->next->getData());
						current->next->setData(temp);
						swapped = true;
					}
					prev = current;
					current = current->next;
				}
			} while(swapped);
		}
        void checkPalindrome(){
			if(head==nullptr || head->getNext()==nullptr){
				cout<<"This list is a palindrome."<<endl;
				return;
			}
			singlyListNode<T>* one=head;
			singleList reversedList;
			while(one!=nullptr){
				reversedList.insertAtEnd(one->getData());
				one=one->next;
			}

            singlyListNode<T>* prev=nullptr;
            singlyListNode<T>* current=reversedList.head;
            singlyListNode<T>* next=nullptr;
            while(current!=nullptr){
                next=current->next;
                current->next = prev;
                prev=current;
                current=next;
            }
            reversedList.head=prev;
			one=head;
            while(one!=nullptr){
                if(one->getData()!=reversedList.head->getData()){
                cout<<"This list is NOT a palindrome."<<endl;
				return;
				}

                one=one->next;
                reversedList.head=reversedList.head->next;            
            }
            cout<<"This list is a palindrome."<<endl;
            while (reversedList.head) {
                singlyListNode<T>* temp = reversedList.head;
                reversedList.head = reversedList.head->getNext();
                delete temp;
            }
        }
        void swap(int pos1, int pos2){
            if (pos1 == pos2) return;
            if (pos1 < 0 || pos1 >= size())
                return;
            if (pos2 < 0 || pos2 >= size())    
                return;
            singlyListNode<T>* prevA = NULL;
            singlyListNode<T>* prevB = NULL;
            singlyListNode<T>* currentA = NULL;
            singlyListNode<T>* currentB = NULL;
            singlyListNode<T>* prev = NULL;
            singlyListNode<T>* current = head;
            singlyListNode<T>* temp = NULL;
            int count = 0;
            while (current){
                if (count == pos1)
                {
                    prevA = prev;
                    currentA = current;
                }
                if (count == pos2)
                {
                    prevB = prev;
                    currentB = current;
                }
                prev = current;
                current = current->getNext();
                count++;
            }
            if (prevA)
                prevA->setNext(currentB);
            else 
                head = currentB;
            if (prevB)    
                prevB->setNext(currentA);
            else
                head = currentA;
            
            temp = currentA->getNext();
            currentA->setNext(currentB->getNext());
            currentB->setNext(temp);
        }    
        int size(){
            int count = 0;
            singlyListNode<T>* temp = head;
            while (temp)
            {
                count++;
                temp = temp->getNext();
            }
            return count;    
        }

};
//Generalized Circular Linked List Class
template<class T>
class circularList{
    public:
        singlyListNode<T>* head;
        singlyListNode<T>* tail;

        circularList() : head(nullptr), tail(nullptr){}
        void display(){
            if(!head){
                cout<<"List is empty!"<<endl;
                return;
            }
            singlyListNode<T>* temp = head;
            do{
                cout << temp->getData() << "\t";
                temp = temp->getNext();
            } while (temp != head); // Stop when we loop back to the head
            cout << endl;
        }

        void insertAtStart(T val){
            singlyListNode<T>* n = new singlyListNode<T>(val);
            if(head==nullptr){
                head = n;
                tail = n;
                tail->setNext(head);
            } 
			else{
                n->setNext(head);
                head = n;
                tail->setNext(head);
            }
		}
        void insertAtEnd(T val){
			singlyListNode<T>* n = new singlyListNode<T>(val);
			if(head == NULL){
				head = n;
				tail = n;
                tail->setNext(head);
			}
			else{
				tail->setNext(n);
				tail = n;
                tail->setNext(head);
			}
		}
        void insertAtIndex(T val,int index){
            if (index < 0) {
                cout << "Invalid index!" << endl;
                return;
            }
            if (index == 0) {
                insertAtStart(val);
                return;
            }
			singlyListNode<T>* update = new singlyListNode<T>(val);
			singlyListNode<T>* temp = head;
			singlyListNode<T>* before = nullptr;
			for(int i=0;temp != nullptr && i<index-1;i++){
				before = temp;
				temp=temp->getNext();
			}
            if (!temp) {
                cout << "Index out of bounds!" << endl;
                delete update;
                return;
            }
			before->setNext(update);
			update->setNext(temp);
		}
		void deleteNode(int val){
			if(head==nullptr){
			cout<<"The list is empty."<<endl;
            return;
        	}

        	if(head->getData()==val){
				singlyListNode<T>* temp = head;

				if(head->getNext()==head){
					head = nullptr;
					tail = nullptr;
				} 
				else{
					head = head->getNext();
					tail->setNext(head);
				}
				delete temp;
				return;
			}
            singlyListNode<T>* before = nullptr;
            singlyListNode<T>* temp = head;
            while(temp->getNext()!=head && temp->getData()!=val){
                before = temp;
                temp = temp->getNext();
            }

            if(temp->getNext()==head && temp->getData()!=val){
                cout<<val<<" was not found in this list."<<endl;
                return;
            }

            before->setNext(temp->getNext());
            if(temp==tail)
                tail = before;
            delete temp;
    	}
};

//Generalized singlyListNode Class for Doubly List
template<class T>
class doublyNode{
    public:
        doublyNode<T>* next;
        doublyNode<T>* prev;
        T data;

        doublyNode() : next(nullptr), prev(nullptr){}
        doublyNode(T d) : next(nullptr),prev(nullptr),data(d){}
        T getData(){ return data; }
        void setData(T d){ data = d; }
		doublyNode<T>* getNext(){return next;}
		doublyNode<T>* getPrev(){return prev;}
		void setNext(doublyNode<T>* update){next = update;}
		void setPrev(doublyNode<T>* update){prev = update;}
};
//Generalized Doubly List Class
template<class T>
class doublyList{
    public:
        doublyNode<T>* head;
        doublyNode<T>* tail;

        doublyList():head(nullptr),tail(nullptr){}
        void display(){
            if(!head){
                cout<<"List is empty!"<<endl;
                return;
            }
            doublyNode<T>* temp = head;
			while(temp!=nullptr)
			{
				cout<<temp->getData()<<"\t";
				temp=temp->getNext();
			}
			cout<<endl;
        }

        void insertAtStart(T val){
			doublyNode<T>* n = new doublyNode<T>(val);
            if (!head) 
                head = tail = n;
            else {
                n->setNext(head);
                head->setPrev(n);
                head = n;
            }
		}
		void insertAtEnd(T val){
			doublyNode<T>* temp = head;
			doublyNode<T>* n = new singlyListNode<T>(val);
			if(head == NULL){
				head = n;
				tail = n;
			}
			else{
				tail->setNext(n);
                n->setPrev(tail);
				tail = n;
			}
		}
        void deleteNode(T d) {
            if(!head){
                cout << "List is empty!" << endl;
                return;
            }
            doublyNode<T>* temp = head;
            while (temp && temp->getData() != d)
                temp = temp->next;
            
            if (!temp) {
                cout << "Value " << d << " not found in the list." << endl;
                return;
            }

            if (temp == head) {
                head = head->next;
                if (head)
                    head->prev = nullptr;  // Update head's prev if list isn't empty
            }
            // If the singlyListNode to delete is the tail
            else if (!temp->next)
                temp->prev->next = nullptr;
            // If the singlyListNode is in the middle
            else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }

            delete temp;
            cout << "singlyListNode with value " << d << " deleted."<<endl;
        }

        void concatenate(doublyList &l,doublyList &m){
            if(l.head==nullptr || m.head==nullptr){
                cout<<"One of the provided list was empty."<<endl;
                return;
            }

            l.tail->setNext(m.head);
            m.head->setPrev(l.tail);
            l.tail = m.tail;
        }
};

template<class T>
void displayReverse(singlyListNode<T>* head){        //Display LinkedList reversed by Recursion
    if(head==nullptr)
	return;
	
    displayReverse(head->getNext());
    cout<<head->getData()<<"\t";
}
//------------------------------------------------------------------------------//

//-------------------------------STACKS-------------------------------------//
//Generalized Stacks Class (By Array)
template<class T>
class stacksByArray{
	private:
		int top,size;
	public:
		T *arr;
		stacksByArray():top(-1),size(0),arr(nullptr){}
		stacksByArray(int s):top(-1),size(s){ arr = new T[size]; }
		int getSize() { return size; }
		T peek(){
            if(isEmpty())
				throw std::underflow_error("Stack underflow occurred!");
            return arr[top]; 
        }
		void push(T e){
			if(isFull()){
				cout<<"Stack overflow occured!"<<endl;
				return;
			}
			arr[++top] = e;
		}
		T pop(){
			if(top<0)
				throw std::underflow_error("Stack underflow occurred!");
			
			T last = arr[top--];
			return last;
		}
		bool isEmpty(){
			if(top<0)
				return true;
			return false;
		}
        bool isFull() { return top >= size - 1; }
		bool checkPalindrome(){
			stacksByArray<T> reversed(this->size);
			for(int i=0;i<size;i++)
				reversed.push(this->arr[i]);
			
			for(int i=0;i<size;i++){
				if(this->arr[i]!=reversed.pop())
					return false;
			}
			return true;
		}
		~stacksByArray(){ delete[] arr; }
};
int precedence(char c){                 //helper for infixToPostfix function
    if(c == '^') 
        return 3;
    else if(c == '*' || c == '/') 
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}
string infixToPostfix(string infix){            //infixToPostfix function using stacksByArray<char>
    string postfix = "";
    stacksByArray<char> s(infix.length());

    for(int i = 0; i < infix.length(); i++){
        char c = infix[i];

        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            postfix += c;
        else if(c == '(')
            s.push(c);
        else if(c == ')'){
            while(!s.isEmpty() && s.peek() != '('){
                char op = s.pop();
                postfix += op;
            }
            if(s.peek() == '(') 
                s.pop();
        } else{
            while(!s.isEmpty() && precedence(c) <= precedence(s.peek())){
                char op = s.pop();
                postfix += op;
            }
            s.push(c);
        }
    }
    while(!s.isEmpty()){
        char op = s.pop();
        postfix += op;
    }

    return postfix;
}

//Generalized Stacks Class (By LinkedList)
template<class T>
class stacksByLL{
	private:
		singlyListNode<T>* top;
	public:
		stacksByLL():top(nullptr){}
		void push(T e){
			singlyListNode<T>* n = new singlyListNode<T>;
			if(n==nullptr){
				cout<<"Stack overflow occured!"<<endl;
				return;
			}
			n->setData(e);
			n->setNext(top);
			top = n;
		}
		T pop(){
			if(top==nullptr)
				throw std::underflow_error("Stack underflow occurred!");
			
			T last = top->getData();
			singlyListNode<T>* temp = top;
			top=top->getNext();
			delete temp;
			return last;
		}
		T peek(){
			if(isEmpty())
				throw std::underflow_error("Stack underflow occurred!");
			T last = top->getData();
			return last;
		}
		void display(){
			if(top==nullptr){
				cout<<"Stack empty!"<<endl;
				return;
			}
			singlyListNode<T>* temp = top;
			while(temp!=nullptr){
				cout<<temp->getData()<<endl;
				temp=temp->getNext();
			}

		}
		bool isEmpty(){
			if(top==nullptr)
				return true;
			return false;
		}
};

float applyOperation(char op,float val1,float val2){
    switch(op){
        case '+': return val1 + val2;
        case '-': return val1 - val2;
        case '*': return val1 * val2;
        case '/': return val1 / val2;
        case '^': return pow(val1, val2);
        default: return 0;
    }
}

bool checkDigit(char c){ return (c >= '0' && c <= '9'); }

float parseNumber(const string& s, int& i){
    string numStr = "";
    while(i < s.length() && (checkDigit(s[i]) || s[i] == '.')){
        numStr += s[i];
        i++;
    }
    i--;
    return stof(numStr);
}

void evaluateTop(stacksByLL<char>& operators, stacksByLL<float>& values){
    if(operators.isEmpty()) return;
    
    char op = operators.pop();
    float val2 = values.pop();
    float val1 = values.pop();
    
    values.push(applyOperation(op,val1,val2));
}

float calcExpression(const string& infix){          //Expression calculator using stacksByLL
    stacksByLL<char> operators;
    stacksByLL<float> values;

    for(int i = 0; i < infix.length(); i++){
        char c = infix[i];

        if(checkDigit(c) || c == '.') 
            values.push(parseNumber(infix,i));
        else if(c == '('){
            if(i > 0 && (checkDigit(infix[i-1]) || infix[i-1] == ')'))
                operators.push('*');
            
            operators.push(c);
        } 
		else if(c == ')'){
            while (!operators.isEmpty() && operators.peek() != '(')
                evaluateTop(operators,values);
            
            operators.pop();
        } 
		else if(c == '*' || c == '/' || c == '+' || c == '-' || c == '^'){
            while (!operators.isEmpty() && precedence(c) <= precedence(operators.peek()))
                evaluateTop(operators,values);
            
            operators.push(c);
        }
    }
    while (!operators.isEmpty()) 
        evaluateTop(operators, values);

    return values.peek();
}
//----------------------------------------------------------------------------------------------//

//-------------------------------QUEUES-------------------------------------//
//Generalized Queues Class (By Array)
template<class T>
class queueByArray{
    private:
        int rear,front,size;
    public:
        T *arr;
        queueByArray():front(-1),rear(-1),size(0),arr(nullptr){}
		queueByArray(int s):front(-1),rear(-1),size(s){ arr = new T[size]; }
		void enqueue(T val){
			if(isFull()){
				cout<<"Queue is full!"<<endl;
				return;
			}
            else if(isEmpty())
                front = rear = 0;
            else
                rear++;
			arr[rear]=val;
		}
		void dequeue(){
			if(isEmpty()){
                cout<<"Queue is empty!"<<endl;
                return;
            }
            else if(front == rear){
                cout<<"Dequeued: "<<arr[front]<<endl;
                front = rear = -1;
            }
            else{
                cout<<"Dequeued: "<<arr[front]<<endl;
                front++;
            }
		}
		bool isEmpty(){
			if(front==-1 || front>rear)
				return true;
			return false;
		}
        bool isFull(){
            if(rear==size-1)
                return true;
            return false;
        }
        T atFront(){
            if(isEmpty())
                throw std::underflow_error("Queue is empty!");

            return arr[front];
        }
        void display(){
            if(isEmpty()){
                cout<<"Queue is empty!"<<endl;
                return;
            }
            for(int i=front;i<=rear;i++)
                cout<<arr[i]<<endl;
        }
		~queueByArray(){ delete[] arr; }
};

//Generalized Queues Class (By LinkedList)
template<class T>
class queueByLL{
    private:
        int size;
    public:
        singlyListNode<T>* front;
        singlyListNode<T>* rear;
        queueByLL():front(nullptr),rear(nullptr),size(0){}
		void enqueue(T val){
            singlyListNode<T>* n = new singlyListNode<T>(val);
            if(isEmpty())
                front = rear = n;
            else{
                rear->next = n;
			    rear = n;
            }
            cout<<"singlyListNode with value: "<<val<<" enqueued!"<<endl;
            size++;
		}
		void dequeue(){
			if(isEmpty()){
                cout<<"Queue is empty!"<<endl;
                return;
            }
            singlyListNode<T>* temp = front;
            cout << "Dequeued: " << temp->data << endl;
            front = front->next;
            if (front == nullptr)
                rear = nullptr;
            delete temp;
            size--;
		}
		bool isEmpty(){ return front == nullptr; }
        T atFront(){
            if(isEmpty())
                throw std::underflow_error("Queue is empty!");
            return front->data;
        }
        void display(){
            if(isEmpty()){
                cout<<"Queue is empty!"<<endl;
                return;
            }
            singlyListNode<T>* temp = front;
            cout << "Queue elements: "<<endl;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};
//----------------------------------------------------------------------------------------------//

//--------------------------------------------RECURSIONS & BACKTRACKING---------------------------------------------------//

int recursiveArraySum(int *arr[],int *sizes,int dim){       //Jagged Array Sum
    if(dim==0)
        return 0;
    if(sizes[dim-1]==0)
        return recursiveArraySum(arr,sizes,dim-1);

    return (arr[dim-1][--sizes[dim-1]])+recursiveArraySum(arr,sizes,dim);
}

bool moveLion(bool *maze[],int x,int y,int s,bool **sol){       //Rat in maze - Backtracking
    if(x==s-1 && y==s-1){
        sol[x][y]=1;
        return true;
    }
    if((x<s && y<s && maze[x][y]==1) ? true : false){
        sol[x][y]=1;
        if(moveLion(maze,x+1,y,s,sol))
            return true;
        if(moveLion(maze, x, y+1, s, sol))
            return true;
    }
    sol[x][y]=0;
    return false;
}
void display(bool **arr,int r,int c){
    for(int i=0;i<r;i++){
        cout<<"-";
        for(int j=0;j<c;j++)
            cout<<arr[i][j]<<"-";
        cout<<endl;
    }
}

//----------------------------------------N-Queens-----------------------------------------------------------
bool canPlace(int board[],int row,int col){
    for(int i=0; i<row; i++){
        if(board[i]==col || abs(board[i]-col)==abs(i-row))
            return false;
    }
    return true;
}
bool maxFlags(int board[],int n,int row=0){
    if(row==n) 
        return true;
    
    for(int col=0;col<n;col++){
        if(canPlace(board,row,col)){
            board[row] = col;
            if(maxFlags(board,n,row+1))
                return true;

            board[row] = -1;
        }
    }
    return false;
}
void displayFlags(int *arr,int n){
    int f=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i]==j){
                cout<<"F ";
                f++; }
            else
                cout<<"- ";
        }
        cout<<endl;
    }
    cout<<"Maximum number of flags that can be placed: "<<f<<endl;
}

//-----------------------------------------------------------------------------------------------------------//
//--------------------------------------------SORTING---------------------------------------------------//
template<class T>
singlyListNode<T>* quickSortLL(singlyListNode<T>* n){              //Quick Sort on LinkedList
    if(!n || !n->next) return n;  

    singlyListNode<T>* pivot = n;  // First singlyListNode as Pivot
    singlyListNode<T>* lessHead = nullptr;
    singlyListNode<T>* lessTail = nullptr;
    singlyListNode<T>* greaterHead = nullptr;
    singlyListNode<T>* greaterTail = nullptr;

    singlyListNode<T>* current = n->next;

    // Partitioning the List into less and greater parts relative to pivot
    while(current){
        if(current->data < pivot->data){
            if(!lessHead){
                lessHead = current;
                lessTail = current;
            } else {
                lessTail->next = current;
                lessTail = current;
            }
        } else {
            if(!greaterHead){
                greaterHead = current;
                greaterTail = current;
            } else {
                greaterTail->next = current;
                greaterTail = current;
            }
        }
        current = current->next;
    }

    if(lessTail) lessTail->next = nullptr;  // Terminate Less List
    if(greaterTail) greaterTail->next = nullptr;  // Terminate Greater List

    lessHead = quickSortLL(lessHead);  
    greaterHead = quickSortLL(greaterHead); 

    
    //Combine the lists
    pivot->next = nullptr;  

    if(!lessHead){  // If the less list is empty, pivot is the head
        pivot->next = greaterHead;  // Append greater list after pivot
        return pivot;
    }

    lessTail = lessHead;
    while(lessTail->next){
        lessTail = lessTail->next;  // Traverse till the end of less
    }

    lessTail->next = pivot;  // Append Pivot to the end of less
    pivot->next = greaterHead;  // Append greater list after pivot

    return lessHead;  // Return the new head of sorted list
}

int partition(int a[], int start, int end)  
{  
    int pivot = a[end]; // Pivot is the last element
    int i = start - 1;  // Index of the smaller element

    for(int j = start; j < end; j++) {  
        if (a[j] <= pivot) {  
            i++;  
            // Swap a[i] and a[j]
            int t = a[i];  
            a[i] = a[j];  
            a[j] = t;  
        }  
    }  
    // Swap a[i + 1] with pivot (a[end])
    int t = a[i + 1];  
    a[i + 1] = a[end];  
    a[end] = t;  

    return i + 1;  // Return the partition index
}
//Quick sort on Array
void quickSortArr(int a[], int start, int end) /* a[] = array to be sorted, start = Starting index, end = Ending index */  
{  
    if (start < end)  
    {  
        int p = partition(a, start, end); //p is the partitioning index  
        quickSortArr(a, start, p - 1);  
        quickSortArr(a, p + 1, end);  
    }  
}  


/* Function to merge the subarrays of a[] */  
void merge(int a[], int beg, int mid, int end){         //Merge sort helper    
    int i, j, k;  
    int n1 = mid - beg + 1;    
    int n2 = end - mid;    
      
    int LeftArray[n1], RightArray[n2]; //temporary arrays  
      
    /* copy data to temp arrays */  
    for (int i = 0; i < n1; i++)    
    LeftArray[i] = a[beg + i];    
    for (int j = 0; j < n2; j++)    
    RightArray[j] = a[mid + 1 + j];    
      
    i = 0; /* initial index of first sub-array */  
    j = 0; /* initial index of second sub-array */   
    k = beg;  /* initial index of merged sub-array */  
      
    while (i < n1 && j < n2)    
    {    
        if(LeftArray[i] <= RightArray[j])    
        {    
            a[k] = LeftArray[i];    
            i++;    
        }    
        else    
        {    
            a[k] = RightArray[j];    
            j++;    
        }    
        k++;    
    }    
    while (i<n1)    
    {    
        a[k] = LeftArray[i];    
        i++;    
        k++;    
    }    
      
    while (j<n2)    
    {    
        a[k] = RightArray[j];    
        j++;    
        k++;    
    }    
}    
  
void mergeSort(int a[], int beg, int end)   //Merge sort on array
{  
    if (beg < end)   
    {  
        int mid = (beg + end) / 2;  
        mergeSort(a, beg, mid);  
        mergeSort(a, mid + 1, end);  
        merge(a, beg, mid, end);  
    }  
}

void bubbleSort(int arr[] , int size) {
    for (int i=0;i<size;i++) {
        for (int j=0;j<size-1-i;j++) {
            if (arr[j]>arr[j+1]) {
                //swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void selectionSort(int arr[] , int size) {
    for (int i=0;i<size-1;i++) {
        int lowest=arr[i];
        int lowest_index=i;
        for (int j=i+1;j<size;j++) {
            if (arr[j]<lowest) {
                lowest =arr[j];
                lowest_index=j;
            }
        }
        // swap
                int temp = arr[i];
                arr[i] = arr[lowest_index];
                arr[lowest_index] = temp;
    }
}
void insertionSort(int arr[] , int size) {
    for (int i=1;i<size;i++) {
        int j = i-1;
        int key=arr[i];
        while (j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void shellSort(int myarr[], int n1) {
    for (int gap = n1/2; gap > 0; gap /= 2) {
        for(int j = gap;j<n1;j++){
            int temp = myarr[j];
            int res = j;

            while(res>=gap && myarr[res-gap]>temp){
                myarr[res] = myarr[res-gap];
                res-=gap;
            }
            myarr[res] = temp;
        }
    }
}

int binSearchAsc(int *arr,int n,int key){      //When sorted ascending
    int left = 0;
    int right = n-1;
    while(left <= right) {
        int mid = left + (right - left)/2;

        if (arr[mid] == key) 
            return mid;
        else if (arr[mid] < key) 
            left = mid + 1;
        else 
            right = mid - 1;
    }
    return -1;
}
int binSearchDesc(int *arr,int n,int key){      //When sorted descending
    int left = 0;
    int right = n-1;
    while(left <= right) {
        int mid = left + (right - left)/2;

        if (arr[mid] == key) 
            return mid;
        else if (arr[mid] > key) 
            left = mid + 1;
        else 
            right = mid - 1;
    }
    return -1;
}
//-----------------------------------------------------------------------------------------------------------//

//--------------------------------------------TREES---------------------------------------------------//
class BSTnode{
    public:
        int data;
        BSTnode* left;
        BSTnode* right;
        BSTnode():left(nullptr),right(nullptr){}
        BSTnode(int T):data(T),left(nullptr),right(nullptr){}
};
class BST{
    public:
        BSTnode* root;
        BST():root(nullptr){}

        void insertNode(int T){
            if(root == nullptr){
                BSTnode* n = new BSTnode(T);
                root = n;
                return;
            }
            BSTnode* temp = root;
            while(1){
                if(temp->data <= T){
                    if(temp->right != nullptr)
                        temp = temp->right;
                    else{
                        temp->right = new BSTnode(T);
                        break; 
                    }
                }
                else{
                    if(temp->left != nullptr)
                        temp = temp->left;
                    else{
                        temp->left = new BSTnode(T);
                        break;
                    }
                }
            }
        }
        BSTnode* getFarRight(BSTnode* root){
            while(root->right != nullptr)
                root = root->right;
            return root;
        }
        BSTnode* helper(BSTnode*root){
            if(root->left==nullptr)
                return root->right;
            if(root->right==nullptr)
                return root->left;

            BSTnode* rightSideRoot = root->right;
            BSTnode* leftSideMax = getFarRight(root->left);
            leftSideMax->right = rightSideRoot;
            return root->left;
        }
        BSTnode* deleteNode(int id){
            if(root == nullptr)
                return nullptr;
            if(root->data == id){
                BSTnode* deletedBSTnode = root;
                root = helper(root);
                return deletedBSTnode;
            }

            BSTnode* temp = root;
            while(temp != nullptr){
                if (temp->data > id) {
                    if(temp->left != nullptr && temp->left->data == id){
                        BSTnode* deletedBSTnode = temp->left;
                        temp->left = helper(temp->left);
                        return deletedBSTnode;
                    } 
                    else
                        temp = temp->left;
                } 
                else{
                    if(temp->right != nullptr && temp->right->data == id){
                        BSTnode* deletedBSTnode = temp->right;
                        temp->right = helper(temp->right);
                        return deletedBSTnode;
                    } 
                    else
                        temp = temp->right;
                }
            }
            return nullptr;
        }
        bool search(int id){
            if(root == nullptr) 
                return false;
            BSTnode* temp = root;
            while(temp != nullptr){
                if(temp->data == id)
                    return true;
                else if(temp->data < id)
                    temp = temp->right;
                else
                    temp = temp->left;
            }
            return false;
        }
        void inOrder(){ inOrder(root); }
        void inOrder(BSTnode* r){
    		if(r == nullptr)
        		return;

		    inOrder(r->left);
		    cout<<r->data<<"  ";
		    inOrder(r->right);
		}

        int greatestLeft(node* root){   //Helper for checking if tree is BST
            if(root == nullptr)
                return -2147483648;
            while(root->right)
                root = root->right;
            
            return root->data;
        }
        int lowestRight(node* root){   //Helper for checking if tree is BST
            if(root == nullptr)
                return 2147483647;
            while(root->left)
                root = root->left;
            
            return root->data;
        }
        bool checkBST(){ return checkBST(root); }
        //Make sample only by making root node and node->left node->right to insert val (Lab09 Q3)
        /*  BSTnode* flex = new node(10);
            flex->left = new node(6);
            flex->right = new node(13);
            flex->left->left = new node(1);
            flex->left->right = new node(12);
            flex->right->left = new node(9);
            flex->right->right = new node(14);
        */
        bool checkBST(node* root){      //To check if given tree is a BST
            if(root == nullptr)
                return true;
            
            int leftMax = greatestLeft(root->left);
            int rightMin = lowestRight(root->right);
            if((root->left && leftMax >= root->data) || (root->right && rightMin <= root->data))
                return false;
            return checkBST(root->left) && checkBST(root->right);
        }
        
};

class AVLnode{
    public:
        int data;
        int height;
        AVLnode* left;
        AVLnode* right;
        AVLnode():left(nullptr),right(nullptr){}
        AVLnode(int T):data(T),height(1),left(nullptr),right(nullptr){}
};
class AVLTree{
    public:
        AVLnode* root;
        AVLTree():root(nullptr){}

        AVLnode* insertNode(AVLnode* root,int T){
            if(root == nullptr) return new AVLnode(T);
            
            if(T < root->data)
                root->left = insertNode(root->left , T);
            else if(T > root->data)
                root->right = insertNode(root->right , T);
            
            root->height = 1 + max(getHeight(root->left) , getHeight(root->right));
            int balance = getBalance(root);

            if (balance > 1 && T < root->left->data)
                return rightRotate(root);
            if (balance < -1 && T > root->right->data)
                return leftRotate(root);

            if (balance > 1 && T > root->left->data){
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
            if (balance < -1 && T < root->right->data){
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }

            return root; 
        }
        void insertNode(int T){ root = insertNode(root,T);  }
        void preOrder(){ preOrder(root); }
        void preOrder(AVLnode* r){
    		if(r == nullptr)
        		return;

		    cout<<r->data<<"  ";
		    preOrder(r->left);
		    preOrder(r->right);
		}
        int getHeight(AVLnode* r){
            if(r == nullptr) 
                return 0;
            return r->height;
        }
        int getBalance(AVLnode* root){  return(getHeight(root->left) - getHeight(root->right)); }

        AVLnode* rightRotate(AVLnode* y){
            AVLnode* x = y->left;
            AVLnode* temp = x->right;

            x->right = y;
            y->left = temp;

            y->height = 1 + max(getHeight(y->left) , getHeight(y->right));
            x->height = 1 + max(getHeight(x->left) , getHeight(x->right));
            return x;
        }

        AVLnode* leftRotate(AVLnode* x){
            AVLnode* y = x->right;
            AVLnode* temp = y->left;

            y->left = x;
            x->right = temp;
            
            x->height = 1 + max(getHeight(x->left) , getHeight(x->right));
            y->height = 1 + max(getHeight(y->left) , getHeight(y->right));
            return y;
        }

        AVLnode* farLeft(AVLnode* r){   //Helper for deleteNode() function
            AVLnode* curr = r;
            while (curr->left)
                curr = curr->left;
            return curr;
        }
        AVLnode* deleteNode(AVLnode* r, int id) {
            if (!r) return r;

            if (id < r->data)
                r->left = deleteNode(r->left, id);
            else if (id > r->data)
                r->right = deleteNode(r->right, id);
            else {
                if (!r->left || !r->right) {
                    AVLnode* temp = r->left ? r->left : r->right;
                    if (!temp) {
                        temp = r;
                        r = nullptr;
                    } else
                        *r = *temp;
                    delete temp;
                } else {
                    AVLnode* temp = farLeft(r->right);
                    r->data = temp->data;
                    r->right = deleteNode(r->right, temp->data);
                }
            }

            if (!r) return r;

            r->height = max(getHeight(r->left), getHeight(r->right)) + 1;
            int balance = getBalance(r);

            if (balance > 1 && getBalance(r->left) >= 0)
                return rightRotate(r);
            if (balance > 1 && getBalance(r->left) < 0) {
                r->left = leftRotate(r->left);
                return rightRotate(r);
            }
            if (balance < -1 && getBalance(r->right) <= 0)
                return leftRotate(r);
            if (balance < -1 && getBalance(r->right) > 0) {
                r->right = rightRotate(r->right);
                return leftRotate(r);
            }

            return r;
        }
        void deleteNode(int id){ root = deleteNode(root, id); }

        bool search(int id){
            if(root == nullptr) 
                return false;
            AVLnode* temp = root;
            while(temp != nullptr){
                if(temp->data == id)
                    return true;
                else if(temp->data < id)
                    temp = temp->right;
                else
                    temp = temp->left;
            }
            return false;
        }
};

#include<cstring>
#include<cstdlib>
const int DEGREE = 3;
class BTreeNode{
    public:
    int numKeys;
    int keys[2 * DEGREE - 1];
    BTreeNode* children[2 * DEGREE];
    bool isLeaf;

    BTreeNode(bool leaf) : numKeys(0), isLeaf(leaf) { memset(children, 0, sizeof(children)); }

    int* search(int id) {
        int i = 0;
        while (i < numKeys && id > keys[i])
            i++;
        if (i < numKeys && keys[i] == id)
            return &keys[i];
        if (isLeaf)
            return nullptr;
        return children[i]->search(id);
    }

    void insertNonFull(int T){
        int i = numKeys - 1;
        if (isLeaf) {
            while (i >= 0 && keys[i] > T) {
                keys[i + 1] = keys[i];
                i--;
            }
            keys[i + 1] = T;
            numKeys++;
        } else {
            while (i >= 0 && keys[i] > T)
                i--;
            if (children[i + 1]->numKeys == 2 * DEGREE - 1) {
                splitChild(i + 1, children[i + 1]);
                if (keys[i + 1] < T)
                    i++;
            }
            children[i + 1]->insertNonFull(T);
        }
    }
    void splitChild(int i, BTreeNode* y){
        BTreeNode* z = new BTreeNode(y->isLeaf);
        z->numKeys = DEGREE - 1;

        for (int j = 0; j < DEGREE - 1; j++)
            z->keys[j] = y->keys[j + DEGREE];
        if (!y->isLeaf) {
            for (int j = 0; j < DEGREE; j++)
                z->children[j] = y->children[j + DEGREE];
        }
        y->numKeys = DEGREE - 1;

        for (int j = numKeys; j >= i + 1; j--)
            children[j + 1] = children[j];
        children[i + 1] = z;

        for (int j = numKeys - 1; j >= i; j--)
            keys[j + 1] = keys[j];
        keys[i] = y->keys[DEGREE - 1];
        numKeys++;
    }
    void remove(int id){
        int idx = findKey(id);
        if (idx < numKeys && keys[idx] == id) {
            if (isLeaf)
                removeFromLeaf(idx);
            else
                removeFromNonLeaf(idx);
        } else {
            if (isLeaf)
                return;
            bool isLastChild = (idx == numKeys);
            if (children[idx]->numKeys < DEGREE)
                fill(idx);
            if (isLastChild && idx > numKeys)
                children[idx - 1]->remove(id);
            else
                children[idx]->remove(id);
        }
    }
    void removeFromLeaf(int idx){
        for (int i = idx + 1; i < numKeys; i++)
            keys[i - 1] = keys[i];
        numKeys--;
    }
    void removeFromNonLeaf(int idx){
        int id = keys[idx];
        if (children[idx]->numKeys >= DEGREE) {
            int pred = getPred(idx);
            keys[idx] = pred;
            children[idx]->remove(pred);
        } else if (children[idx + 1]->numKeys >= DEGREE) {
            int succ = getSucc(idx);
            keys[idx] = succ;
            children[idx + 1]->remove(succ);
        } else {
            merge(idx);
            children[idx]->remove(id);
        }
    }
    int findKey(int id){
        int idx = 0;
        while (idx < numKeys && keys[idx] < id)
            idx++;
        return idx;
    }
    int getPred(int idx){
        BTreeNode* cur = children[idx];
        while (!cur->isLeaf)
            cur = cur->children[cur->numKeys];
        return cur->keys[cur->numKeys - 1];
    }
    int getSucc(int idx){
        BTreeNode* cur = children[idx + 1];
        while (!cur->isLeaf)
            cur = cur->children[0];
        return cur->keys[0];
    }
    void fill(int idx){
        if (idx != 0 && children[idx - 1]->numKeys >= DEGREE)
            borrowFromPrev(idx);
        else if (idx != numKeys && children[idx + 1]->numKeys >= DEGREE)
            borrowFromNext(idx);
        else {
            if (idx != numKeys)
                merge(idx);
            else
                merge(idx - 1);
        }
    }
    void borrowFromPrev(int idx){
        BTreeNode* child = children[idx];
        BTreeNode* sibling = children[idx - 1];
        for (int i = child->numKeys - 1; i >= 0; i--)
            child->keys[i + 1] = child->keys[i];
        if (!child->isLeaf) {
            for (int i = child->numKeys; i >= 0; i--)
                child->children[i + 1] = child->children[i];
        }
        child->keys[0] = keys[idx - 1];
        if (!child->isLeaf)
            child->children[0] = sibling->children[sibling->numKeys];
        keys[idx - 1] = sibling->keys[sibling->numKeys - 1];
        child->numKeys++;
        sibling->numKeys--;
    }
    void borrowFromNext(int idx){
        BTreeNode* child = children[idx];
        BTreeNode* sibling = children[idx + 1];
        child->keys[child->numKeys] = keys[idx];
        if (!child->isLeaf)
            child->children[child->numKeys + 1] = sibling->children[0];
        keys[idx] = sibling->keys[0];
        for (int i = 1; i < sibling->numKeys; i++)
            sibling->keys[i - 1] = sibling->keys[i];
        if (!sibling->isLeaf) {
            for (int i = 1; i <= sibling->numKeys; i++)
                sibling->children[i - 1] = sibling->children[i];
        }
        child->numKeys++;
        sibling->numKeys--;
    }
    void merge(int idx){
        BTreeNode* child = children[idx];
        BTreeNode* sibling = children[idx + 1];
        child->keys[DEGREE - 1] = keys[idx];
        for (int i = 0; i < sibling->numKeys; i++)
            child->keys[i + DEGREE] = sibling->keys[i];
        if (!child->isLeaf) {
            for (int i = 0; i <= sibling->numKeys; i++)
                child->children[i + DEGREE] = sibling->children[i];
        }
        for (int i = idx + 1; i < numKeys; i++)
            keys[i - 1] = keys[i];
        for (int i = idx + 2; i <= numKeys; i++)
            children[i - 1] = children[i];
        child->numKeys += sibling->numKeys + 1;
        numKeys--;
        delete sibling;
    }
};
class BTree{
    public:
    BTreeNode* root;
    BTree() : root(nullptr) {}

    void insert(int T){
        if (!root) {
            root = new BTreeNode(true);
            root->keys[0] = T;
            root->numKeys = 1;
        } else {
            if (root->numKeys == 2 * DEGREE - 1) {
                BTreeNode* s = new BTreeNode(false);
                s->children[0] = root;
                s->splitChild(0, root);
                int i = (s->keys[0] < T) ? 1 : 0;
                s->children[i]->insertNonFull(T);
                root = s;
            } else 
                root->insertNonFull(T);
            
        }
    }
    int* search(int id){ return root ? root->search(id) : nullptr; }
    void remove(int id){
        if (!root)
            return;
        root->remove(id);
        if (root->numKeys == 0) {
            BTreeNode* temp = root;
            if (root->isLeaf)
                root = nullptr;
            else
                root = root->children[0];
            delete temp;
        }
    }
};

//-----------------------------------------------------------------------------------------------------------//

//--------------------------------------------HEAP---------------------------------------------------//



//-----------------------------------------------------------------------------------------------------------//

//--------------------------------------------HASHING---------------------------------------------------//


//-----------------------------------------------------------------------------------------------------------//
\

int main() {
    // Example usage of your classes
    singleList<int> list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.display();
    return 0;
}