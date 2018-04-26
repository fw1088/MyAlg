#include<stdlib.h>
#include<stdio.h>

struct node {
    int val;
    struct node *next;
};

void addNode(node* head, int val){
    if(head == NULL) {
        return;
    }
    node* tmp = head;
    node* pre = tmp;
    while(tmp != NULL){
       pre = tmp;
       tmp = tmp->next;
    }
    node* newNode = new node();
    newNode->val = val;
    newNode->next = NULL;
    pre->next = newNode;
    return;
}

void print_node(node* head){
    if(head == NULL){
       return;
    }
    node* tmp = head->next;
    while(tmp != NULL){
        printf("%d\n",tmp->val);
        tmp = tmp->next;
    }
    printf("\n");
  
}

void deleteNode(node* head,int val){
    if(head == NULL){
       return;
    }
    node* tmp = head->next;
    node* pre = head;
    while(tmp != NULL){
        if(tmp->val == val){
            pre->next = tmp->next;
            break;
        }
        pre = tmp;
        tmp = tmp->next;
    }
}

void reverseNode(node* head){
    if(head == NULL) {
        return;
    }
    node* currentNode = head->next;
    node* nextNode = currentNode;
    node* preNode = NULL;
    while(currentNode != NULL) {
        nextNode = currentNode->next;
        currentNode->next = preNode;
        preNode = currentNode;
        currentNode = nextNode;
    }
    head->next = preNode;
}

//insert at after
void insertVal(node* head,node** common,int index){
    if(head==NULL|| common==NULL|| index < 0){
        return;
    }
    node* tmp = head->next;
    while(tmp != NULL){
      if(index == 0){
          node* nextNode = tmp->next;
          tmp->next = *common;
          tmp->next->next = nextNode;
          break;
      }
      index--;
      tmp = tmp->next;
    }
}

int meetNode(node* head1,node* head2){
    if(head1 == NULL || head2 == NULL){
        return -1;
    }
    //construct circle
    node* tmp = head1->next;
    node* pre = head1;
    while(tmp != NULL) {
        pre = tmp;
        tmp =  tmp->next;
    }
    pre->next = head1->next;
    node* first = head2;
    node* second = head2;
    while(second != NULL){
        first = first->next;
        if(second->next != NULL){
            second = second->next->next;
        }else {
            return -1;
        }
        if(second == first){
            int val = 0;
            second = head2;
            while(second != NULL) {
                printf("%d----\n",second->val);
                if(second == first ){
                    val = second->val;
                    break;
                 }
                 second = second->next;
                 first = first->next;
            }
            return val;
        }
    }
    return -1;
}
int main(){
    node* head;
    head = new node();
    head->val = 0;
    addNode(head,2);
    addNode(head,3);
    addNode(head,4);
    addNode(head,56);
    addNode(head,12);
    addNode(head,23);
    addNode(head,10);
    deleteNode(head,23);
    reverseNode(head);
    //construct circle node
    node* commonNode = new node;
    commonNode->val = -18;
    commonNode->next = NULL;
    node* head1 = new node;
    addNode(head1,-111111111);
    addNode(head1,122222);
    addNode(head1,111);
    addNode(head1,0);
    addNode(head1,110);
    insertVal(head1,&commonNode,4);
    node* head2 = new node;
    addNode(head2,11100);
    addNode(head2,12);
    addNode(head2,8);
    addNode(head2,5);
    addNode(head2,-8);
    addNode(head2,2);
    addNode(head2,-10);
    addNode(head2,77);
    addNode(head2,123);
    addNode(head2,34);
    addNode(head2,99);
    insertVal(head2,&commonNode,6);
    int val = meetNode(head1,head2);
    printf("%d",val);
    return 0;
}
