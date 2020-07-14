// flatten multilevel linked list by depth
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
    struct Node *down;
}

Node* flattenList(Node * node){
    if(node == NULL) return NULL;
    
    static Node *last;
    last = node;

    Node *next = node->next;

    if(node->down) node->next = flattenList(node->down);
    if(next) last->next = flattenList(next);
    return node;
}

//using stack instead of recusion
Node* flattenList2(Node *head){
    Node *headcopy = head;
    stack<Node*> st;
    st.push(head);
    Node *prev = NULL;

    while(!st.empty()){
        Node *temp = st.top();
        st.pop();

        if(temp->next) st.push(temp->next);
        if(temp->down) st.push(temp->down);
        if(prev != NULL) prev->next = temp;
        prev = temp;
    }
    return headcopy;
}

Node* newNode(int data){
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = newNode->child = NULL;
    return newNode;
}

void printFlattenNodes(Node* head){ 
    while (head){  
    printf("%d ", head->data);  
    head = head->next;  
    }  
} 

int main(){ 
    Node* head = newNode(1); 
    head->next = newNode(2); 
    head->next->next = newNode(3); 
    head->next->next->next = newNode(4); 
    head->next->down = newNode(7); 
    head->next->down->down = newNode(9); 
    head->next->down->down->down = newNode(14); 
    head->next->down->down->down->down = newNode(15); 
    head->next->down->down->down->down->next = newNode(23); 
    head->next->down->down->down->down->next->down = newNode(24); 
    head->next->down->next = newNode(8); 
    head->next->down->next->down = newNode(16); 
    head->next->down->next->down->down = newNode(17); 
    head->next->down->next->down->down->next = newNode(18); 
    head->next->down->next->down->down->next->next = newNode(19); 
    head->next->down->next->down->down->next->next->next = newNode(20); 
    head->next->down->next->down->down->next->next->next->down = newNode(21); 
    head->next->down->next->next = newNode(10); 
    head->next->down->next->next->down = newNode(11);
    head->next->down->next->next->next = newNode(12); 
  
    head = flattenList(head); 
    printFlattenNodes(head); 
    return 0; 
} 
