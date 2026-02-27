//Linked List using Templates in C++

//Linked List using Templates in C++ program is given below:


// linkedlist.cpp
// linked list using templates
// See also: Link List program in C++

//#include "stdafx.h" //Remove this line if you see any error.
#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////
template <typename T>
struct link                           //one element of list
{
 T data;                          //data item
 link* next;                        //pointer to next link
};
////////////////////////////////////////////////////////////////
template <class T>
class linklist                        //a list of links
{
private:
 link<T>* first;                    //pointer to first link
public:
 linklist()                      //no-argument constructor
 { first = NULL; }            //no first link
 void additem(T );            //add data item (one link)
 void display();                 //display all links
};
//-------------------------------------------------------------void
template <class T>
void linklist<T>::additem(T d)         //add data item
{
 link<T> *newLink = new link<T>;
 newLink->data = d;
 //insert at head of link list
 newLink->next = first;
 first = newLink;
}
//-------------------------------------------------------------void
template <class T>
void linklist<T>::display()              //display all links
{
 link<T>* current = first;             //set ptr to first link
 while( current != NULL )           //quit on last link
 {
  cout << current->data << endl;  //print data
  current = current->next;        //move to next link
 }
}
////////////////////////////////////////////////////////////////

int main()
{
 linklist<int> li;       //make linked list
 li.additem(25);    //add four items to list
 li.additem(36);
 li.additem(49);
 li.display();      //display entire list

 linklist<char> lch;      //make linked list
 lch.additem('a');    //add four items to list
 lch.additem('b');
 lch.additem('c');
 lch.display();      //display entire list
 
 return 0;
}

