#include <iostream>
#include "MyLinkedStack.h"
using namespace std;

MyLinkedStack::MyLinkedStack(){
    initialize();
}
MyLinkedStack::~MyLinkedStack(){
    while (!isEmpty()) pop();
}
void  MyLinkedStack::initialize(){
    stacktop = nullptr;
}
bool MyLinkedStack::isEmpty() const{
    return stacktop == nullptr;
}
void MyLinkedStack::push(const int& val){
    Node *newnode = new Node(val);
    newnode -> next = stacktop;
    stacktop = newnode;
}
void MyLinkedStack::pop(){
    if(isEmpty()){
        cout << "Stack is empty" << endl;
        return;
    } 
    Node *temp = stacktop;
    stacktop = temp -> next;
    delete temp;
}
int MyLinkedStack::top()const{
    if(isEmpty()) return -1;
    return stacktop -> data;
}
//Node의 개수를 가져옴
int MyLinkedStack::getNodeCnt()const{
    int count =0;
    Node *current = stacktop;
    while(current != nullptr){
        count++;
        current = current -> next;
    }
    return count;
}
void MyLinkedStack::printAll() {
    Node* current = stacktop;
    if(current == nullptr){
        cout << "Stack is empty" << endl;
        return;
    }
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) cout << " -> ";
            current = current->next;
        }
    cout << "  (" << getNodeCnt() << " nodes)" << endl;
}