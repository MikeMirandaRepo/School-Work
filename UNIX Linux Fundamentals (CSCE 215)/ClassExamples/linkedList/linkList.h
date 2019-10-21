

#ifndef LINKLIST_H
#define LINKLIST_H

#include <iostream>
using namespace std;

template <class T>
class node
{
	public:
	node();
	~node();
	T data;
	node *next;
};

template <class T>
class linkList{

	private:
	  node<T> *head, *tail;
	  int size;

	public:
	  linkList();
	  linkList(int size, T data);
	  ~linkList();
	  T operator[](int index);
	  void createNode(T data);
	  void init();
	  void printList();
	  int getSize();		
	  void insert(int pos, T value);
	  void remove(int pos);
	  int find(T data);
	  
};

#endif /* LINKLIST_H */
