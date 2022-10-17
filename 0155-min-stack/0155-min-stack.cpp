class Node {
    private: 
    int val;
    Node* next;
    Node* prev;
    
    public:

        
    Node* getNext() {return next;}
    Node* getPrev() {return prev;}
    int getValue() {return val;}
    
    void setNext(Node* node) {
        next = node;   
    }
    
    
    void setPrev(Node* node) {
        prev = node;   
    }
    
    Node() {
        next = nullptr;
        prev = nullptr;
    }
    Node(int val) {
        this->val = val;
        next = nullptr;
    }

};


class MinStack {
public:
    Node* topStack;
    int minValue; 
    stack<pair<int, int>> minStack;
    
    MinStack() {     
       topStack = nullptr;
    }
    
    void push(int val) {
        Node* temp = new Node(val);
        
        if(topStack == nullptr) {
            minValue = val;
            topStack = temp;
            topStack->setPrev(nullptr);
            topStack->setNext(nullptr);
        } else {
        topStack->setNext(temp);
        topStack->getNext()->setPrev(topStack); 
        topStack = topStack->getNext();
        }
        
        /* Utilize Min Stack */ 
        
        if (minStack.empty() || val < minStack.top().first) {
            minStack.push({val, 1});
        } else if (val == minStack.top().first) {
            minStack.top().second++;
        }
        
        
        
    }
    
    void pop() {
        
        if (top() == minStack.top().first) {
            minStack.top().second--;
            if (minStack.top().second == 0) {
                minStack.pop();
            }
        }
        
        Node* temp = topStack;
        
        int value = temp->getValue();
    
        topStack = temp->getPrev();
        if(topStack) {
            topStack->setNext(nullptr);
        }
        
        delete temp;
        
    }
    
    int top() {
         return topStack->getValue();
    }
    
    int getMin() {
        return minStack.top().first; 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */