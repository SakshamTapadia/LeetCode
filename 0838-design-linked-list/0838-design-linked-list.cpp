class MyLinkedList {    
public:
    struct Node {
        int val;
        Node *next, *prev;
    };

    void deleteHead() {
        Node* prevHead = this->head;
        if (this->head == nullptr)
            return;
        this->head = this->head->next;
        if (this->head == nullptr)
            return;
        this->head->prev = nullptr;
        prevHead->next = nullptr;
        delete prevHead;
    }
    void deleteTail() {
        Node* prevTail = this->tail;
        if (prevTail == nullptr)
            return;
        this->tail = prevTail->prev;
        if (this->tail == nullptr) {
            this->head = nullptr;
        } else {
            this->tail->next = nullptr;
            prevTail->prev = nullptr;
        }
        delete prevTail;
    }

    Node *head, *tail;
    MyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    int get(int index) {
        Node* temp = this->head;
        for (int i = 0; i < index && temp != nullptr; i++)
            temp = temp->next;
        return temp ? temp->val : -1;
    }

    void addAtHead(int val) {
        Node* newHead = new Node();
        newHead->val = val;
        if (this->head == nullptr) {
            this->head = newHead;
            this->tail = newHead;
            return;
        }
        newHead->prev = nullptr;
        newHead->next = this->head;
        this->head->prev = newHead;
        this->head = newHead;
    }

    void addAtTail(int val) {
        Node* newTail = new Node();
        newTail->val = val;
        if (this->head == nullptr) {
            this->head = newTail;
            this->tail = newTail;
            return;
        }
        newTail->prev = this->tail;
        newTail->next = nullptr;
        this->tail->next = newTail;
        this->tail = newTail;
    }

    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }
        Node* temp = this->head;
        for (int i = 1; i < index && temp != nullptr; i++)
            temp = temp->next;

        if (!temp)
            return;
        if (temp == this->tail) {
            addAtTail(val);
            return;
        }

        Node* newNode = new Node();
        newNode->val = val;
        newNode->prev = temp;
        newNode->next = temp->next;
        temp->next = newNode;
        newNode->next->prev = newNode;
    }

    void deleteAtIndex(int index) {
        if (index == 0) {
            deleteHead();
            return;
        }
        Node* temp = this->head;
        for (int i = 0; i < index && temp; i++)
            temp = temp->next;

        if (!temp)
            return;
        if (temp == this->tail) {
            deleteTail();
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->next = nullptr;
        temp->prev = nullptr;
        delete temp;
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