Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement the MyLinkedList class:

**MyLinkedList()** Initializes the MyLinkedList object.\
**int get(int index)** Get the value of the indexth node in the linked list. If the index is invalid, return -1.\
**void addAtHead(int val)** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.\
**void addAtTail(int val)** Append a node of value val as the last element of the linked list.\
**void addAtIndex(int index, int val)** Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.\
**void deleteAtIndex(int index)** Delete the indexth node in the linked list, if the index is valid.


Example 1:\

```
Input
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
Output
[null, null, null, null, 2, null, 3]

Explanation
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
myLinkedList.get(1);              // return 2
myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
myLinkedList.get(1);              // return 3
```

Idea:\
first node and other nodes should be processed separately. 



```cpp
class MyLinkedList {
public:
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int x):val(x), next(nullptr){}
    };

    MyLinkedList() {
        dummyNode = new LinkedNode(0);
        size = 0;
    }
    
    int get(int index) {
        if(index > size - 1) {
            return -1;
        } else {
            LinkedNode* cur = dummyNode->next;
            while(index--) {
                cur = cur->next;
            }
            return cur->val;
        }
    }
    
    void addAtHead(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = dummyNode->next;
        dummyNode->next = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = dummyNode;
        while(cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = newNode;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index <= size){
            LinkedNode* newNode = new LinkedNode(val);
            LinkedNode* cur = dummyNode;
            while(index--) {
                cur = cur->next;
            }
            newNode->next = cur->next;
            cur->next = newNode;
            size++;   
        }
    }
    
    void deleteAtIndex(int index) {
        if(index < size){
            // LinkedNode* newNode = new LinkedNode(val);
            LinkedNode* cur = dummyNode;
            while(index--) {
                cur = cur->next;
            }
            LinkedNode* tmp = cur->next;
            cur->next = cur->next->next;
            // important
            // if did not set tmp to nullptr,
            // this would cause problem when using tmp in future
            delete tmp;
            tmp = nullptr;
            size--;
        }
    }
    // print part
    void printLinkedList() {
        LinkedNode* cur = dummyHead;
        while (cur->next != nullptr) {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }


private:
    int size;
    LinkedNode* dummyNode;
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
```

























