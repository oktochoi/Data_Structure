class Stack {
private:
    int *data;
    int maxSize;
    int top;    
public:
    Stack(int maxSize);
    ~Stack();
    void push(int value);
    int pop();
    int peek();
    bool isEmpty();
    bool isFull();
    int size();
    void print();
};