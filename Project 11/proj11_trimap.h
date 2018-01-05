#ifndef SINGLELINK_H
#define SINGLELINK_H

#include<iostream>
using std::ostream; using std::cout; using std::endl;
#include<sstream>
using std::ostringstream;
#include<utility>
using std::swap;
#include<string>
using std::string;

/*Project 11
Project 11 focuses on a TriMap using variation. A templated class, and its going to use as its underlying representation a linked list. 

Ana Lopez 
Section 11
12/4/17
*/

// forward declaration so we can make Element a friend of TriMap
template<typename K, typename V>
class TriMap;

// private Element, friend of TriMap class
template <typename K, typename V>
class Element{

private:
  K key_;
  size_t index_ = 0;
  Element *next_ = nullptr;  

public:
  V value_;
  
  Element() = default;
  Element(K key, V val, size_t i) : key_(key),index_(i), next_(nullptr), value_(val) {};

  // *defined* in the class, makes templating easier.
  friend ostream& operator<<(ostream& out, Element& e){
    out <<e.key_ << ":" << e.value_ << ":" << e.index_;
    return out;
  }
  friend class TriMap<K,V>;
};


template<typename K, typename V>
class TriMap{

private:
  Element<K,V> *head_ = nullptr;
  Element<K,V> *tail_ = nullptr;
  size_t size_ = 0;
  
  // a private function, used by operator<<
  void print_list(ostream& out);
  
public:
  TriMap() = default;
  TriMap(K, V);
  TriMap(const TriMap&);
  TriMap& operator=(TriMap);
  ~TriMap();
  
  long size();
  bool insert(K,V);
  bool remove(K);
  Element<K,V>* find_key(K);
  Element<K,V>* find_value(V);
  Element<K,V>* find_index(size_t);  
  
  // *defined* in the class, makes templating easier.
  // uses private method print_list
  // you can remove print_list and just do it here if you
  // prefer. I won't test print_list
  friend ostream& operator<<(ostream& out, TriMap<K,V>& sl){
    sl.print_list(out);
    return out;
  };
};
/*TRIMAP CONSTRUCTOR
reinitializes key, value, and size. 
Construct a new Element type and assign the head and tail to it
*/
template<typename K, typename V>
TriMap<K,V>::TriMap(K key, V value){
    K key_ = key;
    V value_ = value;
    Element<K,V> *t = new Element<K,V>(key, value, 0);
    head_ = t;
    tail_ = t;
    size_ = 1;
};

/* 
bit of work. we need to remember a pointer that walks
down the list to copy, as tail_ walks down the new list. 
Make a new node (copy the current node of the list we are copying), 
update the tail_->next_ to point to the new node, update tail_ to new node
 */
 
/* Copy Constructor
 constructor for creating a new object as a copy of the existing TriMap
 
 For this function, I was very inspired by what we did for Lab 13
*/
template<typename K, typename V>
TriMap<K,V>::TriMap(const TriMap& tm){
    
    if (tm.head_ == nullptr){
    	head_ = nullptr;
    	tail_ = nullptr;
    	size_ = 0;
    }
    else {
    	head_ = new Element<K,V>(tm.head_->key_, tm.head_->value_, tm.head_->index_);
    	tail_ = head_;
    	//auto tm_ptr = tm.head_->next_;
    	//Element<K,V> *new_tm;
    	for (auto tm_ptr = tm.head_->next_ ; tm_ptr != nullptr; tm_ptr= tm_ptr->next_) {
    	   //auto new_tm = nullptr;
    	   //Element<K,V> *new_tm;
    	   //new_tm = tail_->next_;
    	   tail_->next_ = new Element<K,V>(tm_ptr->key_, tm_ptr->value_, tm_ptr->index_);
    	   //new_tm = new Element<K,V>(tm_ptr->key_, tm_ptr->value_, tm_ptr->index_);
    	    //tail_->next_ = new_tm;
    	    tail_ = tail_->next_;
    	    //tail_ = new_tm;
    	    
    	}
    	size_ = tm.size_;
    	cout << "tm size: " << size_ << endl;
    }
}
/* 
operator= Constructor

For this function, I was very inspired by what we did for Lab 13
*/
template<typename K, typename V>
TriMap<K,V>& TriMap<K,V>::operator=(TriMap tm){
    swap(head_, tm.head_);
    swap(tail_, tm.tail_);
    swap(size_, tm.size_);
    return *this;
}
	
// walk down the list using head_ , keeping a trailer pointer called to_del
// delete what to_del points to
// move head_ and to_del to the next node.
/*Destructor 
deletes everything it had and resets all Element to empty*/
template<typename K, typename V>
TriMap<K,V>::~TriMap(){
    Element<K,V>* to_del = head_;
    while (to_del != nullptr){
    	head_ = head_->next_;
    	delete to_del;
    	to_del = head_;
    }
    head_ = nullptr;
    tail_ = nullptr;
}
/* Size class method
returns the number of elements in the underlying vector*/
template<typename K, typename V>
long TriMap<K,V>::size(){
    return size_;
}

/*Checks if the key does exist in the underlying list, 
if it does, no action is taken. 
if it doesn't exist, then it inserts a new Element<K,V> in the linked list
Element<K,V> has the key, the value, a proper insertion value. 
*/
template<typename K, typename V>
bool TriMap<K,V>::insert(K key, V value) {
    int index = size_;
    cout << "index: " << index << endl;
    if (find_key(key) != nullptr) { //checks if key does exist
        return false;
    }
    
    Element<K,V> *e = new Element<K,V>(key, value, index); 
    //creates new Element<K,V>
    if (head_ == nullptr) { //empty linked list so it inserts it
        //sets both head and tail to be the element since the list is empty
        head_ = e; 
        tail_ = e;
        //reinitializes head_ and tail to both be the element
        size_++; //increment size
        return true;
    }

    else {
        //comparing one node and another node to see where new element can go in
            //cur is the current node. 
            Element<K,V> *cur; //current node
            Element<K,V> *trailer = nullptr; //node following the current node
            for (cur = head_; cur != nullptr;){
                if (cur->key_ > key) {
                    break; //key cant be bigger than the current node key
                }
                trailer = cur; //assigns the trailer to the current node
                cur=cur->next_; //current moves to the next one
            }
            if (cur == head_) { //insert at beginning 
                e->next_ = head_; //reinitializes element ptr next to the head 
                head_ = e; //head is the element
                size_++; //increments the size 
                return true;
            }
            else if (cur == nullptr) { //insert at end
                tail_->next_ = e; //sets the tail next to be the element 
                tail_ = e; //sets to tail to be the element
                size_++; //increments size 
                return true;
            }
            else { //insert in middle 
                trailer->next_ = e; //trailer next node is the element
                e->next_ = cur; //element next node is the current node
                size_++; //increments the size 
                return true;
            }
    }
    return false;
}
  
/*Checks if the element key is in the underlying list, 
if it does not, then no action is taken
if it does, then it is removed. 
After it is removed the index values of the Element<K,V> is updated

For this function, I was very inspired by what was posted in Piazza for Lab 13 by Nitash
*/
template<typename K, typename V>
bool TriMap<K,V>::remove(K key){
  // again, what are all the cases!!!
  // also, if you delete a node, the indicies of all
  // nodes with a higher index have that index reduced by one
    //int index = size_;
    
    if (find_key(key) == nullptr) { //find_key doesnt find the key
        return false;
    }
    //Element<K,V> *e = new Element<K,V>(key, value, index);
    // case 1: if list is empty
    if (head_ == nullptr)
      return false;

    // case 2: we have to delete the head
    if (head_->key_ == key) { 
      if (head_ == tail_) // if list has only one element we need this check to
                          // ensure tail is updated
        tail_ = nullptr;
      
      auto temp = head_;   // snip and re-attach
      head_ = head_->next_;
      auto temp_index = temp->index_;
      //size_t deleted_ind
      delete temp;
      for (auto pos = head_; pos != nullptr; pos = pos->next_) {
          if (pos->index_ > temp_index) {
              pos->index_--; //iterator pointing to index_ is decremented
          }
      }
      size_ --; //decrements the size

      return true;
    }

    // in all other cases, get the pointer to the Node before
    auto p = head_;
    while (p->next_ != nullptr && p->next_->key_ != key)
      p = p->next_;

    if (p->next_ == nullptr) // we didn't find the Node
      return false;

    // if we find it, just snip out the in-between node

    if (p->next_ == tail_) // but we have to check if  we have to delete the last Node. 
                           // Since our implementation needs the tail
                           // pointer, we have this extra check
      tail_ = p;

    auto temp = p->next_;  // snip and reattach
    p->next_ = p->next_->next_;
    auto temp_index = temp->index_; 
    delete temp;
    for (auto pos = head_; pos != nullptr; pos = pos->next_) {
         if (pos->index_ > temp_index) {
              pos->index_--; //iterator pointing to the index_ is decremented
         }
    }
    size_ --; //decrements the size

    return true;
 }


    
/*Using a linear search
if the Element<K,V> with the key is found in the list, then it is returned
if it is not found, then a nullptr is returned
*/
template<typename K, typename V>
Element<K,V>* TriMap<K,V>::find_key(K key){
  // no binary search, just linear search
  Element<K,V> *pos;

    for (pos = head_; pos != nullptr; pos = pos->next_) {
        if (pos->key_ == key) {
            return pos;
            //return &(*pos);
        }
    }
 
  return nullptr;
}

/*Using a linear search
if the Element<K,V> with the value is found in the list, then it is returned
if it is not found, then a nullptr is returned
*/
template<typename K, typename V>
Element<K,V>* TriMap<K,V>::find_value(V val){
  // linear search
  Element<K,V> *pos;
    for (pos = head_; pos != nullptr; pos = pos->next_) {
        if (pos->value_ == val){
            return pos;
        }
    }

  return nullptr;
}  

/*Using a linear search
if the Element<K,V> with the index is found in the list, then it is returned
if it is not found, then a nullptr is returned
*/
template<typename K, typename V>
Element<K,V>* TriMap<K,V>::find_index(size_t i){
  Element<K,V> *pos;
    for (pos = head_; pos != nullptr; pos = pos->next_) {
        if (pos->index_ == i) {
            return pos;
        }
    }

    return nullptr;
}

/*Print the TriMap
*/
template<typename K, typename V>
void TriMap<K,V>::print_list(ostream &out){
    
    ostringstream oss;
    Element<K,V> *ptr;
    for(ptr = head_; ptr != nullptr; ptr = ptr->next_) {
        oss << *ptr << ", ";
    }
    string s = oss.str();
    s = s.substr(0,s.size()-2);
    out << s;
  // this is a class member function, has access
  // to private data. Called by operator<<
  
};


#endif
