#ifndef _LIST_H
#define _LIST_H

struct Node{
    double value;
    struct Node *next;
    void (*Node)(struct Node* this,double v,void*n);
    void (*_Node)(struct Node* this);
};
void Node(struct Node* this, double,void* value);

struct List{
    int size;
    struct Node* header;

    struct Node* (*selectByValue)(struct List* this,double value);
    void (*add)(struct List* this,double value);
    void (*delete)(struct List* this,struct Node* front,struct Node* target);
    void (*deleteByIndex)(struct List* this,int index);
    void (*update)(struct List* this,struct Node* node);
};

void List(struct List* this);
void test();

#endif //_LIST_H
