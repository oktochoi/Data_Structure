struct Node{
    int data;
    Node *link;
    Node(int val, Node* a = nullptr) : data(val), link(a){}
};

class LLQ{
    Node* front;
    Node* rear;
public:
    LLQ();
    ~LLQ();
    bool isempty();
    void enqueue(int value);
    void dequeue();
    void showfront();
    void showrear();
    void displayQueue();
};