#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};
class LRUCache : public Cache{
    private:
        int memory_filled{};
    public:
        LRUCache(int capacity){
            tail = head = nullptr; 
            cp = capacity; 
            mp.clear(); 
        }

        void set(int key , int value) override{
            auto itr = mp.find(key);
            if(itr != mp.end() && itr->second != nullptr){ // if we key is already present in the memory then let's remove it
                if(itr->second==head){
                    head->value = value;
                    return;
                }
                memory_filled--;
                Node* prev_node = itr->second ->prev; 
                Node* next_node = itr->second ->next; 
                if(prev_node != nullptr)
                    prev_node -> next = next_node; 
                if(next_node != nullptr)
                    next_node -> prev = prev_node; 
                if(head == itr->second){
                    head = head->next;
                }
                if(tail == itr->second){
                    tail = tail->next;
                }
                //mp.erase(itr);
            }
            Node * n = new Node(key , value); 
            memory_filled++;
            if(head == nullptr) { // if first key 
                head = n;
                if(tail == nullptr){
                    tail = n; 
                }else{
                    head->next = tail; 
                    tail->prev = head;
                }
            }else{
                head->prev = n;
                n->next = head; 
                head = n;
            }
            mp[key] = n;
            if(memory_filled > cp) {
                //mp.erase(tail->key);
                mp[tail->key] = nullptr;
                tail = tail->prev;
                memory_filled--;
            }
        }

        int get(int key) override {
            // return value
            auto itr = mp.find(key); 
            if(itr != mp.end() && itr->second != nullptr){
                // TODO Remove this key and insert it in the front 
                int value = itr->second->value;
                if(itr->second != head){ // if it is not already at front 
                    set(key , value);
                }
                return value;
            }else{
                return -1;
            }
        }
};
int main() {
    freopen("input" , "r" , stdin);
    freopen("output", "w" , stdout);
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
