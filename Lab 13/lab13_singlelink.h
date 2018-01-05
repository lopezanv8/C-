#ifndef SINGLELINK_H
#define SINGLELINK_H

#include<iostream>
using std::ostream; using std::cout; using std::endl;
#include<sstream>
using std::ostringstream;
#include<stdexcept>
using std::out_of_range;
#include<string>
using std::string;

template <typename T>
struct Node{
public:
    Node *next_;
    T data_;
    
  Node() : next_(nullptr) {};
  Node(T d) :next_(nullptr),  data_(d) {};
};

template<typename T>
ostream& operator<<(ostream& out, Node<T>& n){
    out << n.data_<<", ";
    return out;
}

template <typename T>
class SingleLink{
private:
    Node<T> *head_;
    Node<T> *tail_;
  
public:
  SingleLink() : head_(nullptr), tail_(nullptr) {};
  SingleLink(T dat);
  void append_back(T dat);
  bool del(T val);
  Node<T> operator[](size_t indx);
  friend ostream& operator<<(ostream& out, SingleLink& sl){
    // out << "List:";
    ostringstream oss;
    for(auto itr=sl.head_; itr !=nullptr; itr=itr->next_)
      oss <<itr->data_<<", ";
    string s = oss.str();
    s = s.substr(0,s.size() - 2);
    out << s;
    return out;
  };
  ~SingleLink();
  SingleLink(const SingleLink&);
  SingleLink& operator=(SingleLink);
};

template<typename T>
SingleLink<T>::SingleLink(T dat){
  head_ = new Node<T>(dat);
  tail_ = head_;
}

// append node with data dat to the end of the list
// fast because of the tail_ pointer
template<typename T>
void SingleLink<T>::append_back(T dat){
    Node<T> *node = new Node<T>(dat);
    if (tail_ != nullptr){
	tail_->next_ = node;
	tail_ = node;
    }
    else {
	head_= node;
	tail_= node;
    }
}

template<typename T>
bool SingleLink<T>::del(T val){
    bool ret_val = false;
    Node<T> *first, *second;
    first = second = head_;
    if (first != nullptr){
	if (head_->data_ == val){
	    head_ = head_->next_;
	    cout << "Found it: "<< (head_ == nullptr) << endl;
	    ret_val = true;
	}
	else {
	    cout << "Looking"<<endl;
	    while(first != nullptr){
		if (first->data_ == val){
		    second->next_=first->next_;
		    first = first->next_;
		    ret_val = true;
		}
		second = first;
		first = first->next_;
	    }
	}
    }
    return ret_val;
}

template<typename T>	
Node<T> SingleLink<T>::operator[](size_t indx){
    if (indx < 0)
	throw out_of_range("Negative index");
    size_t cnt = 0;
    auto itr = head_;
    while (itr != nullptr){
	if (cnt == indx)
	    return *itr;
	itr = itr->next_;
	cnt++;
    }
    throw out_of_range("Index not found");
}

/* 
bit of work. we need to remember a pointer that walks
down sl, and tail_ walks down the new list. 
make a new node (copy the current sl node), update
 */
template<typename T>
SingleLink<T>::SingleLink(const SingleLink& sl){
    if (sl.head_ == nullptr){
	head_ = nullptr;
	tail_ = nullptr;
    }
    else{
	head_ = new Node<T>(sl.head_->data_);
	tail_ = head_;
	Node<T>* sl_ptr = sl.head_->next_;
	Node<T>* new_node;
	while (sl_ptr != nullptr){
	    new_node = new Node<T>(sl_ptr->data_);
	    tail_->next_ = new_node;
	    sl_ptr = sl_ptr->next_;
	    tail_ = new_node;
	}
    }
}

template<typename T>
SingleLink<T>& SingleLink<T>::operator=(SingleLink sl){
    // x = y
    // x.operator=(y);
    swap(head_, sl.head_);
    swap(tail_, sl.tail_);
    return *this;
}
	

// walk down the list, moving head_ but remember it in to_del
// delete each node in turn, the set head_ and tail_
template<typename T>
SingleLink<T>::~SingleLink(){
    Node<T>* to_del = head_;
    while (to_del != nullptr){
	head_ = head_->next_;
	delete to_del;
	to_del = head_;
    }
    head_ = nullptr;
    tail_ = nullptr;
}

#endif
  
