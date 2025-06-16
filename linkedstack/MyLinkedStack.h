struct Node{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr){}
};

class MyLinkedStack{
private:
    Node *stacktop;
public:
    MyLinkedStack();
    ~MyLinkedStack();
    void initialize();
    bool isEmpty() const;
    void push(const int&);
    void pop();
    int top()const;
    int getNodeCnt()const;//Node의 개수를 가져옴
    void printAll();
};