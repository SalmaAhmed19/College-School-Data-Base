// CS311 Yoshii S22 slist.cpp
// Complete all functions with their comments
// NEVER delete my comments!!
// ====================================================
//HW#: HW3P1 slist  inheriting from llist
//Your name: **Salma Rashed
//Complier:  g++
//File type: slist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include "slist.h" 

// ** Make sure llist constructor and destructors have couts in them


// do not change this one
slist::slist()
{// cout << "slist constructor:" << endl;
 
}


// positions always start at 1

int slist::search(el_t key){
  Node*P=Front;
  int elemnum=1; //we start from 1
  while(P!=NULL){//as long as front is not equal to null it will keep on searching 
    if(P->Elem==key){//if the node contains key 
      return elemnum;//return it's position
    }
    P=P->Next;//goes to the next node 
    elemnum++;//incrementing 
  }
  return -1;
}


el_t slist::search2(el_t key){

  Node*P=Front;
  el_t E;
  int count=1;

  while (P!=NULL){
    if(P->Elem==key){
      return P->Elem;
      P=P->Next;
      count++;
    }
  }
  return E;
}

// don't forget to throw OutOfRange for bad pos 
// You must use moveTo to go to the pos
void slist::replace(el_t element, int pos){
  //throw out of range if in the wrong position 
  //  Node*P;  
if(pos<1 || pos>Count){
    throw OutOfRange();
  }else { //correct position 
    Node*P=Front; //set node p to front 
    moveTo(pos,P);
    P->Elem=element;//when we reach the new node replace the elem with the new element 
  }

}

bool slist::operator==(const slist& OtherOne){
  // if not the same length, return false immediately
  if(this->Count!=OtherOne.Count){
    return false;
  }
  //creating nodes that will be compared and setting both nodes to the front of both lists 
  Node*P=this->Front;
  Node*Q=OtherOne.Front;

  while(P!=NULL){
    if(P->Elem!=Q->Elem){
      return false;
    }
     // if the same lengths, check each node to see if the elements are the same 
    // since both lists have the same lenght we only need to check that one of them is not == NULL
    P=P->Next;
    Q=Q->Next;
  }
  return true;
}

