#include <iostream>
#include <vector>
using namespace std;
using namespace std;
#define SIZE 20

struct DataItem {
   int data;
   int key;
};

std::vector<DataItem*> hashArray(SIZE, nullptr);
DataItem* dummyItem;
DataItem* item;
int hashCode(int key) {
   return key % SIZE;
}
DataItem* search(int key) {
   //get the hash 
   int hashIndex = hashCode(key);
   //move in array until an empty 
   while (hashArray[hashIndex] != nullptr) {
      if (hashArray[hashIndex]->key == key)
         return hashArray[hashIndex];
         //go to next cell
         //wrap around the table
      hashIndex = (hashIndex + 1) % SIZE;
   }
   return nullptr;
}
void insert(int key, int data) {
   DataItem* item = new DataItem;
   item->data = data;
   item->key = key;
    //get the hash 
   int hashIndex = hashCode(key);
   //move in array until an empty or deleted cell
   while (hashArray[hashIndex] != nullptr && hashArray[hashIndex]->key != -1) {
      hashIndex = (hashIndex + 1) % SIZE;
   }
   hashArray[hashIndex] = item;
}
DataItem* deleteItem(DataItem* item) {
   int key = item->key;
   int hashIndex = hashCode(key);
   while (hashArray[hashIndex] != nullptr) {
      if (hashArray[hashIndex]->key == key) {
         DataItem* temp = hashArray[hashIndex];
         hashArray[hashIndex] = dummyItem;
         return temp;
      }
      hashIndex = (hashIndex + 1) % SIZE;
   }
   return nullptr;
}
void display() {
   for (int i = 0; i < SIZE; i++) {
      if (hashArray[i] != nullptr)
         cout << " (" << hashArray[i]->key << "," << hashArray[i]->data << ")";
   }
   cout << std::endl;
}
int main() {
   dummyItem = new DataItem;
   dummyItem->data = -1;
   dummyItem->key = -1;
   insert(1, 20);
   insert(2, 70);
   insert(42, 80);
   insert(4, 25);
   insert(12, 44);
   insert(14, 32);
   insert(17, 11);
   insert(13, 78);
   insert(37, 97);
   cout<<"Insertion Done";
   cout<<"\nContents of Hash Table: ";
   display();
   int ele = 37;
   cout<<"The element to be searched: "<<ele;
   item = search(ele);
   if (item != nullptr) {
      cout << "\nElement found: " << item->key;
   } else {
      cout << "\nElement not found" << item->key;
   }
   // Clean up allocated memory
   delete(item);
   cout<<"\nHash Table contents after deletion: ";
   display();
}