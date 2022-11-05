#include <iostream>

using namespace std;

/* Definition of Linked List node */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* Print list */
void printList(ListNode *root)
{
    while (root)
    {
        cout << " " << root->val;
        root = root->next;
    }
    cout << endl;
}

/* Free the elements of list */
void deleteList(ListNode *root)
{
    if (root)
        deleteList(root->next);

    delete root;
    root = nullptr;
    return;
}

/* Reverse input Linked List */
ListNode *reverseList(ListNode *head)
{
    if (head == nullptr)
        return head;

    ListNode *curr = head;
    ListNode *prev = nullptr;
    ListNode *next = nullptr;

    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    /*if(prev!=nullptr)
          cout<<"prev="<<prev->val<<endl;*/

    return prev;
}

int main(){
    ListNode* root1;
    ListNode* element=new ListNode(1);
    root1=element;
    element->next=new ListNode(2); element=element->next;  
    element->next=new ListNode(3); element=element->next; 
    element->next=new ListNode(4); element=element->next; 
    element->next=new ListNode(5); element=element->next;  element->next=nullptr;
 
    cout<<"\n List1 before: ";
    printList(root1);

    root1=reverseList(root1);
    
    cout<<"\n List1 after: ";
    printList(root1);

    ListNode* root2=new ListNode(1);
    root2->next=new ListNode(2);    
 
    cout<<"\n List2 before: ";
    printList(root2);

    root2=reverseList(root2);
    
    cout<<"\n List2 after: ";
    printList(root2);

    ListNode* rootEmpty=nullptr;
    rootEmpty=reverseList(rootEmpty);
    cout<<"\n Empty input after: ";
    printList(rootEmpty);

    deleteList(root1);
    deleteList(root2);

    return 0;
}