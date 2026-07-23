class Node {
public:
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = nullptr;
    }
};
class MyLinkedList {
public:
    Node* head;
    int size;
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }
    
    int get(int index) {
        if(head == nullptr)
        {
            return -1;
        }
        if(index < 0 || index >= size)
            return -1;
        Node* temp = head;
        for(int i=0; i<index; i++)
        {

            temp= temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        newNode->next = nullptr;
        if(head == nullptr)
        {
            head = newNode;
            size++;
            return;
        }
        Node* temp = head;
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        Node* newNode = new Node(val);
        newNode->next = nullptr;
        if(index == 0)
        {
            addAtHead(val);
            return;
        }
        if(index==size)
        {
            addAtTail(val);
            return;
        }
        if(index < 0 || index > size)
            return;
        Node* temp = head;
        for(int i=0; i<index-1; i++)
        {
            temp= temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        Node* temp = head;
        Node* del;
        if(index<0 || index>=size)
        {
            return;
        }
        if(head == nullptr)
        {
            return;
        }
        if(index == 0)
        {
            del = head;
            head = head->next;
            delete del;
            size--;
            return;
        }
        for(int i=0; i<index-1; i++)
        {
            temp = temp->next;
        }
        del = temp->next;
        temp->next = temp->next->next;
        size--;
        delete(del);
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */