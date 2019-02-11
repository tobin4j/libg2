#include <malloc.h>
#include <stdio.h>
#include "com_1.h"


void printLinkList(LinkList linkList)
{
    LinkList list=linkList->next;
    printf("%c",'\n');
    while (list!=NULL){
        printf("%d ",list->data);
        list=list->next;
    }
    printf("%c",'\n');
}

LinkList initLinkList()
{
    printf("%s","init LinkList start ... print 0 end");
    LinkList head = malloc(sizeof(Node));
    DateType val;
    Node *node,*t;
    t=head;
    scanf("%d",&val);

    while (val!=0){
        node=malloc(sizeof(Node));
        node->data=val;
        t->next=node;
        t=node;
        scanf("%d",&val);
    }
    t->next=NULL;
    printf("%s","init LinkList end ...");
    printLinkList(head);
    return head;
}
int getLinkListLength(LinkList head)
{
    int count = 0;
    while(head->next!=NULL)
    {
        head=head->next;
        count++;
    }
    return count;
}
int insertBySort(SeqList *list,DateType dat)
{

    int i = list->length-1;
    while (i>=0)
    {
        if (list->data[i]<=dat)
            break;
        list->data[i+1]=list->data[i];
        list->data[i]=dat;

        i--;
    }
    list->length++;
    return list->length;

}

void insertLinkListBySort(LinkList list,DateType x)
{
    Node *node = list->next;
    Node *t;

    if (node==NULL){
        t=malloc(sizeof(Node));
        t->data=x;
        t->next=NULL;
        list->next=t;
        return;
    }

    while(node!=NULL && node->next!=NULL){
        if (node->data<=x && node->next->data>x){
            t=malloc(sizeof(Node));
            t->data=x;
            t->next=node->next;
            node->next=t;
            return;
        }
        node = node->next;
    }
    t=malloc(sizeof(Node));
    t->data=x;
    t->next=NULL;
    node->next=t;
}

void printSeqList(SeqList seqList)
{
    printf("%c",'\n');
    for (int j = 0; j <seqList.length; ++j) {
        printf("%d ",seqList.data[j]);
    }
    printf("%c",'\n');
}

int count(LinkList list,DateType x)
{
    int count = 0;
    Node *head = list;
    while (head!=NULL){
        if (head->data==x){
            count++;
        }
        head=head->next;
    }
    return count;
}

void mergeAB2C(LinkList A,LinkList B)
{
    Node *p = A->next;
    Node *q = B->next;
    Node *t ;
    LinkList C = malloc(sizeof(Node));
    C->next=NULL;
    while (p!=NULL && q!=NULL){
        if (p->data<q->data){
            t = p->next;
            p->next = C->next;
            C->next = p;
            p = t;
        } else{
            t = q->next;
            q->next = C->next;
            C->next = q;
            q = t;
        }
    }
    while (p!=NULL){
        t = p->next;
        p->next = C->next;
        C->next = p;
        p = t;
    }
    while (q!=NULL){
        t = q->next;
        q->next = C->next;
        C->next = q;
        q = t;
    }
    printLinkList(C);
}

int isIncrease(LinkList list)
{
    Node *node = list->next;
    DateType val =NULL;
    while (node!=NULL){

        if (val!=NULL && val>node->data){
            return 0;
        }

        val = node->data;
        node = node->next;
    }
    return 1;
}

void reverseLinkList(LinkList head)
{
    Node *cur = head->next;
    Node *pre,*t ;
    pre=NULL;

    while (cur->next!=NULL){
        t=cur->next;
        cur->next=pre;
        pre=cur;
        cur = t;
    }
    cur->next=pre;
    head->next=cur;
}

int main()
{

    LinkList linkList = initLinkList();
    reverseLinkList(linkList);
    printLinkList(linkList);
    return -1;
}
