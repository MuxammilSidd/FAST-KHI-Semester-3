#include<iostream> 
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap(){
        size=0;
    }

    void insert(int val){
        arr[size]=val;
        int index= size;
        size++;

        while(index>0){
            int parent= (index-1)/2;
            if(arr[parent]< arr[index]){          //max heap
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return;
            } 
        }
    }

    void deletefromhead(){
        if(size==0){
            cout<<"No tree exist"<<endl;
            return;
        }

       arr[0]=arr[size];
       size--;
       
       int i=0;
       while(i<size){
            int leftindex= i*2+1;
            int rightindex=i*2+2;
              
              if(leftindex<size && arr[i]<arr[leftindex]){
                swap(arr[i],arr[leftindex]);
                i=leftindex;
              }
              else if(rightindex<size && arr[i]<arr[rightindex]){
                swap(arr[i],arr[rightindex]);
                i=rightindex;
            }
            else{
                return;
            }
       }
    }

    void print(){
        for(int i=0; i<size; i++){
            cout<<" "<<arr[i];
        }
        cout<<endl;
    }

};

void maxheapify(int *arr, int size, int i){
         
         int largest= i;
         int left= 2*i+1;
         int right= 2*i+2;

         if(left<size && arr[largest]<arr[left]){
                 largest=left;
         }
         
         if(right<size && arr[largest]<arr[right]){
            largest=right;
         }
            if(largest!=i){
            swap(arr[i],arr[largest]);
              maxheapify(arr,size,largest); 
            }
     }
     
     
   void minheapify(int *arr, int size, int i){
        int smallest=i;
        int left= 2*i+1;
        int right= 2*i+2;

        if(left<size && arr[smallest]> arr[left]){
            smallest=left;
        }
        if(right<size && arr[smallest]> arr[right]){
            smallest=right;
        }
        
        if(smallest!=i){
            swap(arr[i],arr[smallest]);
            minheapify(arr,size,smallest);
                    }
        
   }

   void heapsort(int *arr, int size){
    
    int n= size;
    while(n>0){
        swap(arr[0],arr[n-1]);
        n--;
        minheapify(arr,n,0);
    }
   }

int main(){
    //heap h;
    // h.deletefromhead();
    // h.insert(55);
    // h.insert(35);
    // h.insert(50);
    // h.insert(45);
    // h.insert(59);
    // h.print();
    
    int arr[5]={54,53,55,52,50};
    int n=5;
    for(int i=n/2-1; i>=0;i--){
       maxheapify(arr,n,i);
    }
    
    cout<<"printing array now"<<endl;
    //printing array
    for(int i=0; i<n;i++){
    cout<<" "<<arr[i];
    }cout<<endl;

    // heapsort(arr,n);

    //  cout<<"printing sorted array now"<<endl;
    // //printing array
    // for(int i=0; i<n;i++){
    // cout<<" "<<arr[i];
    // }

}