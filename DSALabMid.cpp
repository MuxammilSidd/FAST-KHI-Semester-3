#include<iostream>
#include<cmath>
using namespace std;
//-------------------------------LINKED LISTS-------------------------------------//
//Generalized node Class
template<class T>
class node{
    public:
        T data;
        node* next;

        node() : next(nullptr) {}
        node(T d) : data(d), next(nullptr){}
        T getData(){ return data; }
        node<T>* getNext(){ return next; }
        void setNext(node<T>* n){ next = n; }
        void setData(T d){ data = d; }
};
//Generalized Singly Linked List Class
template<class T>
class singleList{
    public:
        node<T>* head;
        node<T>* tail;
        singleList() : head(nullptr), tail(nullptr){}
        void display(){
            if(!head){
                cout<<"List is empty!"<<endl;
                return;
            }
            node<T>* temp = head;
            while(temp){
                cout<<temp->getData()<<"\t";
                temp = temp->getNext();
            }
            cout<<endl;
        }

        void insertAtStart(T d){
            node<T>* n = new node<T>(d);
            n->next = head;
            head = n;
        }
        void insertAtEnd(T d){
            node<T>* n = new node<T>(d);
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
            node<T>* update = new node<T>(val);
			node<T>* temp = head;
			node<T>* before = nullptr;
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
            node<T>* before = nullptr;
            node<T>* temp = head;
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
            cout<<"node with value "<<d<<" deleted.\n";
        }
        void rotateList(int e) {
            if (head == nullptr || e <= 0) { return; }

            node<T>* temp = head;
            node<T>* before = nullptr;
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
            node<T>* start = temp;
            before->next = nullptr;

            node<T>* end = start;
            while (end->next != nullptr)
                end = end->next;

            end->next = head;
            head = start;
        }
        void check(T val){
			node<T>* temp = head;
			while(temp!=nullptr && temp->getData()!=val)
				temp = temp->next;
			
			if(temp==nullptr)
				cout<<"No node was found with value: "<<val<<endl;
			else
				cout<<"node with value: "<<val<<" is present in the list."<<endl;
		}
        void sort(){        //Ascending order
			if (head==nullptr || head->next==nullptr) return;
			bool swapped;
			do{
				swapped = false;
				node<T>* current = head;
				node<T>* prev = nullptr;
				
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
			node<T>* one=head;
			singleList reversedList;
			while(one!=nullptr){
				reversedList.insertAtEnd(one->getData());
				one=one->next;
			}

            node<T>* prev=nullptr;
            node<T>* current=reversedList.head;
            node<T>* next=nullptr;
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
                node<T>* temp = reversedList.head;
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
            node<T>* prevA = NULL;
            node<T>* prevB = NULL;
            node<T>* currentA = NULL;
            node<T>* currentB = NULL;
            node<T>* prev = NULL;
            node<T>* current = head;
            node<T>* temp = NULL;
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
            node<T>* temp = head;
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
        node<T>* head;
        node<T>* tail;

        circularList() : head(nullptr), tail(nullptr){}
        void display(){
            if(!head){
                cout<<"List is empty!"<<endl;
                return;
            }
            node<T>* temp = head;
            do{
                cout << temp->getData() << "\t";
                temp = temp->getNext();
            } while (temp != head); // Stop when we loop back to the head
            cout << endl;
        }

        void insertAtStart(T val){
            node<T>* n = new node<T>(val);
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
			node<T>* n = new node<T>(val);
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
			node<T>* update = new node<T>(val);
			node<T>* temp = head;
			node<T>* before = nullptr;
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
				node<T>* temp = head;

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
            node<T>* before = nullptr;
            node<T>* temp = head;
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

//Generalized node Class for Doubly List
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
			doublyNode<T>* n = new node<T>(val);
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
            // If the node to delete is the tail
            else if (!temp->next)
                temp->prev->next = nullptr;
            // If the node is in the middle
            else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }

            delete temp;
            cout << "node with value " << d << " deleted."<<endl;
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
void displayReverse(node<T>* head){        //Display LinkedList reversed by Recursion
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
		node<T>* top;
	public:
		stacksByLL():top(nullptr){}
		void push(T e){
			node<T>* n = new node<T>;
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
			node<T>* temp = top;
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
			node<T>* temp = top;
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
        node<T>* front;
        node<T>* rear;
        queueByLL():front(nullptr),rear(nullptr),size(0){}
		void enqueue(T val){
            node<T>* n = new node<T>(val);
            if(isEmpty())
                front = rear = n;
            else{
                rear->next = n;
			    rear = n;
            }
            cout<<"node with value: "<<val<<" enqueued!"<<endl;
            size++;
		}
		void dequeue(){
			if(isEmpty()){
                cout<<"Queue is empty!"<<endl;
                return;
            }
            node<T>* temp = front;
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
            node<T>* temp = front;
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
node<T>* quickSortLL(node<T>* n){              //Quick Sort on LinkedList
    if(!n || !n->next) return n;  

    node<T>* pivot = n;  // First node as Pivot
    node<T>* lessHead = nullptr;
    node<T>* lessTail = nullptr;
    node<T>* greaterHead = nullptr;
    node<T>* greaterTail = nullptr;

    node<T>* current = n->next;

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
//-----------------------------------------------------------------------------------------------------------//

int main() {
    // Example usage of your classes
    singleList<int> list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.display();
    return 0;
}