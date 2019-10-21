#include "linkList.h"

template <class T>//node constructor
node<T>::node(){
next = NULL;
}

template <class T>//node destructor
node<T>::~node(){
}

template <class T>
linkList<T>::linkList()//linkList constructor
{
	head=NULL;
	tail=NULL;
	size = 0;
}

template <class T>
linkList<T>::linkList(int _size, T data){//alternate linkList contructor with a size and value input

	head = NULL;
	tail = NULL;
	size = _size;
	for(int i = 0; i < _size; i++)
        {
                createNode(data);
        }

}
template <class T>
linkList<T>::~linkList(){//linkList destructor
	node<T> *current = head;
	node<T> *next;
	while(current->next != NULL){
	next = current->next;
	delete current;
	current = next;
	}

	
//	delete head;
	delete tail;
}

template <class T>
void linkList<T>::init(){//initializes all values in the Array to numbers input by user
node<T> *temp = head;
T tempValue(0);
 

    cin >> tempValue;
    for (int i = 0; i < getSize(); i++) {
        cin >> tempValue;
        temp->data = tempValue;
	temp = temp->next;
	}
}

template <class T>
void linkList<T>::createNode(T value)//creates nodes at the end of the list. Used for initialization
{
	node<T> *temp = new node<T>();
	temp->data = value;
	temp->next = NULL;
	if(head == NULL)
	{
		head = temp;
		tail = temp;
	}
	else
	{	
	tail->next = temp;
	tail = temp;
	temp = NULL;
	}
	
}


template <class T>
void linkList<T>::printList()//prints all items in the list
{
	node<T> *temp = head;

	for(int i = 0; i < getSize(); i++)
	{
		cout << temp->data << " ";
		temp = temp->next;
	
	}
	cout << "Size: " << getSize() << endl;
	delete temp;
}

template <class T>
int linkList<T>::getSize(){//returns the size of the list
	return size;
}


template <class T>
void linkList<T>::insert(int pos,T value)//inserts a given value at a given position
{
 if(pos > 0 && pos <= getSize()){//if it is greater than 0 and less than the size, insert at pos
	node<T> *current = head;
	node<T> *prev = current;
	node<T> *temp = new node<T>();
	for(int i=0; i<pos; i++)
	{	
		prev = current;
		current = current->next;
	}
	temp->data = value;

        prev->next = temp;
        temp->next = current;

	temp = NULL;
 	delete temp;
	}
   else if(pos == 0){//adds at the head
	node<T> *temp = new node<T>();
	temp->data = value;
	temp->next = head;
	head = temp;

	temp = NULL;
	delete temp;
	}
   else if(pos > getSize()){ //gives an error message about the size of the array
                cout << "The list has " << getSize() << "elements. Please give a position within the size" << endl;
        }	
   else if(pos < 0)//if the position given is negative
	cout << "The negative position " << pos << " is not located in the list" << endl;
}

template <class T>
void linkList<T>::remove(int pos)//!!!Currently not working!!! 
{	
	if(getSize() == 0){//makes sure that the list has at least one element
		cout << "cannot remove from an empty list" << endl;
	}
   else if(pos > 0 && pos <= getSize()){//if the position is between 0 and the size of the list
	node<T> *current = head->next;
	node<T> *previous = head;
	for(int i=0; i < pos; i++)
	{
		previous = current;
		current = current->next;
	}
	//previous->next = current->next;//!!!THIS IS THE ISSUE. COULD NOT FIX DUE TO TIME!!!
	delete current;
	
	}
    else if(pos == 0){//if the position is the head of the list
        node<T> *temp = head;
        head = head->next;
	temp = NULL;
	delete temp;
	}
    else if(pos > getSize()){//if the position is larger than the size of the list
        cout << "The position is larger than the size of the List. Cannot delete an out-of-bounds element" << endl;
        }
    else if(pos < 0)
	cout << "This position is smaller than the size of the List. Cannot delete a negative index" << endl;


}

template <class T>
int linkList<T>::find(T _data){//searches for a value given by the user and returns the given index. -1 otherwise

	node<T> *temp = head;
        for(int i = 0; i < size; i++)
        {
               if(temp->data == _data)
			return i;

		 temp = temp->next;

        }

	return -1;

}

template <class T>
T linkList<T>::operator[](int index)  {//same as find but overriden operator 
	node<T> *temp = head;
    if ((index >= 0) && (index < size)) {
        for(int i = 0; i < index; i++)
		temp = temp->next;

	return temp->data;
    }
    else {
        return -1;
    }
}







