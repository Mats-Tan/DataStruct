[toc]

# 链表

## 一般链表

### 结构

```c
struct Node{
    double value;
    struct Node *next;
    void (*Node)(struct Node* this,double v,void*n);
    void (*_Node)(struct Node* this);
};

struct List{
    int size;
    struct Node* header;

    struct Node* (*selectByValue)(struct List* this,double value);
    void (*add)(struct List* this,double value);
    void (*delete)(struct List* this,struct Node* front,struct Node* target);
    void (*deleteByIndex)(struct List* this,int index);
    void (*update)(struct List* this,struct Node* node);
};
```



## 遇到的问题

### 头文件链接失败 undefined reference to `List'

> TODO: 待查明原因并解决，目前直接在 List.c 中进行了测试

### 进行第三次add时空指针操作异常

在 `add` 操作中，误认为临时指针 `p` 操作的是成员 `next` ，但实际上操作的是成员 `next` 指向的空间，当对 `p` 创建一个新的 `Node` 对象时，实际上重新定义了 `p` 的指向，也就导致了成员next并没有指向这个新的 `Node` 对象。

为了解决这个问题，需要设置一个辅助指针 `q` 用来记录 `p` 的前一个状态，从而完成 `next` 对新对象的引用。