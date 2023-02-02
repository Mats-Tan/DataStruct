/*
 * @Author: tan 1494378582@qq.com
 * @Date: 2023-02-01 21:33:40
 * @LastEditors: tan 1494378582@qq.com
 * @LastEditTime: 2023-02-02 10:53:08
 * @FilePath: \DataStruct\链表\src\main.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdio.h>
#include ".\lib\List.h"

int main(){
    struct List list;
    List(&list);
    list.add(&list,1);
    printf("长度:%d\n",list.size);
    list.add(&list,2);
    printf("长度:%d\n",list.size);
    list.add(&list,3);
    printf("长度:%d\n",list.size);
    struct Node* p = NULL;
    p = list.selectByValue(&list,2);
    printf("%d",p==NULL);
    return 0;
}