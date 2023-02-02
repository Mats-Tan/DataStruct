#include <stdio.h>
#include <stdlib.h>
#include "List.h"

// struct Node{
//     double value;
//     struct Node *next;
//     void (*Node)(struct Node* this,double v,void*n);
//     void (*_Node)(struct Node* this)
// };

void Node(struct Node* this,double v,void*n){
    this->value = v;
    this->next = n;
}

void _Node(struct Node* this){
    free(this);
}

// struct List{
//     int size;
//     struct Node* header;

//     struct Node* (*selectByValue)(struct List* this,double value);
//     void (*add)(struct List* this,double value);
//     void (*delete)(struct List* this,struct Node* front,struct Node* target);
//     void (*deleteByIndex)(struct List* this,int index);
//     void (*update)(struct List* this,struct Node* node);
// };


struct Node* selectByValue(struct List* this,double value){
    if(this->header==NULL)return NULL;
    struct Node* p = this->header;
    
    while(p->next != NULL)
    {
        if(p->value == value) return p;
        p = p->next;
    }
    return p;
};

void add(struct List* this,double value){
    // p永远是操作位
    struct Node* p = this->header;
    struct Node* q = NULL;
    for(int i=0;i<this->size;i++){
        q = p;
        p = p->next;
    }
    if(this->header==NULL){
        this->header = malloc(sizeof(struct Node));
        Node(this->header,value,NULL);
    }else{
        p = malloc(sizeof(struct Node));
        Node(p,value,NULL);
        q->next = p;
    }
    
    this->size++;
};

void delete(struct List* this,struct Node* front,struct Node* target){
    front->next = target->next;
    target->_Node(target);
    this->size--;
};

void deleteByIndex(struct List* this,int index){
    struct Node* p = this->header;
    struct Node* q = NULL;
    for(int i=0;i<this->size && i<index;i++){
        q = p;
        p = p->next;
    }
    if(p!=NULL){
        this->delete(this,q,p);
    }
};

void update(struct List* this,struct Node* node){
    
};

// List构造器
void List(struct List* this){
    this->size = 0;
    this->header = NULL;

    this->selectByValue = selectByValue;
    this->add = add;
    this->delete = delete;
    this->deleteByIndex = deleteByIndex;
    this->update = update;
}

void test(){
    printf("test");
}

