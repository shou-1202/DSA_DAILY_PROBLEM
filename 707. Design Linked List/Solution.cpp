class MyLinkedList {
public:
    struct Node {
        int val;
        Node* next;
        Node(int x) : val(x), next(nullptr) {} 
    };
    Node* head;
    MyLinkedList() {
        head = nullptr;
    }
    
    int get(int index) {
        if(!head){
            return -1;
        }
        Node* temp = head;

        while(temp->next!=NULL && index!=0){
            index--;
            temp = temp->next;
        }
        if(index!=0)return -1;
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if(!head){
            head = newNode;
            return;
        }
        else{
            Node* temp = head;
        
            while(temp->next!=NULL){
               temp = temp->next;
            }

            temp->next = newNode;
        }
        
        
    }
    
    void addAtIndex(int index, int val) {
        if(!head && index>0){
            return;
        }
        if(index == 0){
            addAtHead(val);
        }
        Node* temp = head;

        while(temp!=NULL && index!=1){
            index--;
            temp = temp->next;
        }
        if(index==1){
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    
    void deleteAtIndex(int index) {
        if(!head){
            return;
        }
        if(index == 0){
            Node* temp = head;
            head = head->next;
            temp->next = NULL;
            delete(temp);
            return;
        }
        Node* temp = head;
        Node* temp1 = head;
        while(temp->next!=NULL && index!=0){
            index--;
            temp1 = temp;
            temp = temp->next;
        }

        if(index==0){
            temp1->next = temp->next;
            temp->next = nullptr;
            delete(temp);
        }
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