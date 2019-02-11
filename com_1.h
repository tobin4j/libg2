//
// Created by Z2 on 2019/2/8.
//

#ifndef LIBG_COM_1_H
#define LIBG_COM_1_H

#endif //LIBG_COM_1_H
typedef int DateType;

typedef struct node
{
    DateType data;
    struct node *next;
}Node, *LinkList;


typedef struct
{
    DateType data[100];
    int length;
}SeqList;
