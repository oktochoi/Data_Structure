#include "MyLLQueue.h"
#include <iostream>
using namespace std;

LLQ::LLQ() : front(nullptr), rear(nullptr){}

LLQ::~LLQ(){
    while(!isempty()){
        dequeue();
    }
}
//Function to check if queue is empty or not
bool LLQ::isempty()
{
 if(front == nullptr && rear == nullptr)
 return true;
 else
 return false;
}

//function to enter elements in queue
void LLQ::enqueue ( int value )
{
 Node *ptr = new Node(value);
 ptr->data = value;
 ptr->link = NULL;

 //If inserting the first element/node
 if( front == NULL )
 {
  front = ptr;
  rear = ptr;
 }
 else
 {
  rear ->link = ptr;
  rear = ptr;
 }
}

//function to delete/remove element from queue
void LLQ::dequeue()
{
 if( isempty() )
 cout<<"Queue is empty\n";
 else
 //only one element/node in queue.
 if( front == rear)
 {
  free(front);
  front = rear = NULL;
 }
 else
 {
  Node *ptr = front;
  front = front->link;
  free(ptr);
 }
}

//function to show the element at front
void LLQ::showfront( )
{
 if( isempty())
 cout<<"Queue is empty\n";
 else
 cout<<"element at front is: "<<front->data << endl;
}

void LLQ::showrear( )
{
 if( isempty())
 cout<<"Queue is empty\n";
 else
 cout<<"element at rear is: "<<rear->data << endl;
}

//function to display queue
void LLQ::displayQueue()
{
 if (isempty())
  cout<<"Queue is empty\n";
 else
 {
  Node *ptr = front;
  while( ptr !=NULL)
  {
   if(ptr->link == nullptr){
       cout<<ptr->data<<" ";
   }else{
       cout<<ptr->data<<" -> ";
   }
   ptr= ptr->link;
  }
 }
 cout<<endl;
}