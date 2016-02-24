//
//  main.c
//  LinkedList_ simplified
//
//  Created by chenyufeng on 16/2/24.
//  Copyright © 2016年 chenyufengweb. All rights reserved.
//

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef int elemType;
typedef struct LinkNode{

    int element;
    struct LinkNode *next;
}Node;

//链表的初始化
void initList(Node *pHead){

    pHead = NULL;
    printf("%s函数执行,链表初始化完成\n",__FUNCTION__);
}

//创建线性表
Node *createList(Node *pHead){

    Node *p1;
    Node *p2;

    p1 = p2 = (Node*)malloc(sizeof(Node));
    if (p1 == NULL || p2 == NULL) {
        printf("%s函数执行，创建链表失败\n",__FUNCTION__);
        return NULL;
    }

    p1 = memset(p1, 0, sizeof(Node));
    scanf("%d",&(p1->element));
    p1->next = NULL;

    while (p1->element > 0) {

        if (pHead == NULL) {
            pHead = p1;
        }else{
            p2->next = p1;
        }

        p2 = p1;
        p1 = (Node*)malloc(sizeof(Node));
        if (p1 == NULL || p2 == NULL) {
            printf("%s函数执行，创建链表失败\n",__FUNCTION__);
            return NULL;
        }

        p1 = memset(p1, 0, sizeof(Node));
        scanf("%d",&(p1->element));
        p1->next = NULL;
    }
    printf("%s函数执行，链表创建完成\n",__FUNCTION__);

    return pHead;
}

//打印链表
void printList(Node *pHead){

    if (pHead == NULL) {
        printf("%s函数执行,链表为空\n",__FUNCTION__);
    }else{

        while (pHead != NULL) {
            printf("%d ",pHead->element);
            pHead = pHead->next;
        }
        printf("\n");
    }

}

//清除链表
void clearList(Node *pHead){

    Node *pNext;
    if (pHead == NULL) {
        printf("%s函数执行，链表为空，打印失败\n",__FUNCTION__);
    }else{
        while (pHead != NULL) {
            pNext = pHead->next;
            free(pHead);
            pHead = pNext;
        }
        printf("%s函数执行，链表清空成功\n",__FUNCTION__);
    }
}

//返回链表的长度
int sizeList(Node *pHead){

    int i = 0;
    if (pHead == NULL) {
        printf("%s函数执行，链表为空，获取长度失败\n",__FUNCTION__);
        return -1;
    }else{
        while (pHead != NULL) {
            i++;
            pHead = pHead->next;
        }
        printf("%s函数执行，链表长度为：%d\n",__FUNCTION__,i);
    }

    return i;
}

//判断链表是否为空
void isEmptyList(Node *pHead){

    if (pHead == NULL) {
        printf("%s函数执行，当前链表为空\n",__FUNCTION__);
    }else{
        printf("%s函数执行，当前链表非空\n",__FUNCTION__);
    }
}

//取出链表第pos个位置的元素
int getElement(Node *pHead,int pos){

    int i = 0;
    if (pHead == NULL) {
        printf("%s函数执行，当前链表为空，无法获取pos位置元素\n",__FUNCTION__);
        return 0;
    }

    if (pos <= 0 || pos > sizeList(pHead)) {
        printf("%s函数执行，输入的pos=%d不合法，获取元素失败\n",__FUNCTION__,pos);
        return 0;
    }

    while (pHead != NULL) {
        i++;
        if (i == pos) {
            break;
        }
        pHead = pHead->next;
    }

    printf("%s函数执行，%d位置的元素是：%d\n",__FUNCTION__,pos,pHead->element);

    return 0;
}

//从单链表中查找具有给定值x的第一个元素，若查找成功则返回该结点data域的存储地址，否则返回NULL
elemType *getElementArrr(Node *pHead,int x){

    if (pHead == NULL) {
        printf("%s函数执行，当前链表为空，获取值=%d地址失败\n",__FUNCTION__,x);
        return NULL;
    }

    while ((pHead->element != x) && (pHead->next != NULL)) {
        pHead = pHead->next;
    }

    if ((pHead->element != x) && (pHead->next == NULL)) {
        printf("%s函数执行，链表无法找到值=%d的元素\n",__FUNCTION__,x);
        return NULL;
    }

    if (pHead->element == x) {
        printf("%s函数执行，值=%d在链表中的内存地址：0x%x\n",__FUNCTION__,x,&(pHead->element));
    }

    return &(pHead->element);
}

//把单链表中第pos个结点的值修改为x的值，若修改成功返回１，否则返回０
elemType modifyList(Node *pHead,int pos,int x){

    int i = 0;
    if (pHead == NULL) {
        printf("%s函数执行，当前链表为空，修改值失败\n",__FUNCTION__);
        return 0;
    }

    if (pos <= 0 || pos > sizeList(pHead)) {
        printf("%s函数执行，输入的pos=%d不合法，修改元素失败\n",__FUNCTION__,pos);
        return 0;
    }

    while (pHead != NULL) {
        i++;
        if (i == pos) {
            break;
        }
        pHead = pHead->next;
    }
    pHead->element = x;
    printf("%s函数执行，pos=%d位置元素修改成功\n",__FUNCTION__,pos);

    return 1;
}

//向单链表的表头插入一个元素
Node *InsertHeadList(Node *pHead,int x){

    Node *pInsert;
    pInsert = (Node *)malloc(sizeof(Node));
    memset(pInsert, 0, sizeof(Node));
    pInsert->element = x;
    pInsert->next = NULL;

    if (pHead == NULL) {
        pHead = pInsert;
    }else{

        pInsert->next = pHead;
        pHead = pInsert;
    }

    printf("%s函数执行，在头部插入元素成功\n",__FUNCTION__);

    return pHead;
}

//向单链表的末尾添加一个元素
Node *InsertEndList(Node *pHead,int x){

    Node *pMove;
    Node *pInsert;
    pInsert = (Node *)malloc(sizeof(Node));
    memset(pInsert, 0, sizeof(Node));
    pInsert->element = x;
    pInsert->next = NULL;

    pMove = pHead;
    if (pHead == NULL) {
        pHead = pInsert;
    }else{
        while (pMove->next != NULL) {
            pMove = pMove->next;
        }
        pMove->next = pInsert;
    }

    printf("%s函数执行，在尾部插入元素成功\n",__FUNCTION__);

    return pHead;
}

int main(int argc,const char* argv[]){

    Node *pList;

    //链表初始化
    initList(pList);
    printList(pList);

    //创建链表
    pList = createList(pList);
    printList(pList);

    //链表长度
    sizeList(pList);
    printList(pList);

    //判断链表是否为空
    isEmptyList(pList);
    printList(pList);

    //获取某个位置的元素
    getElement(pList, 3);
    printList(pList);

    //某个值是否在链表中，获取其地址
    getElementArrr(pList, 5);
    printList(pList);

    //修改某位置的元素
    modifyList(pList, 2, 222);
    printList(pList);
    
    //在头部插入数据
    pList = InsertHeadList(pList,1111);
    printList(pList);
    
    //在尾部插入数据
    pList = InsertEndList(pList,9999);
    printList(pList);
    
    return 1;
}






