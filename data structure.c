#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data structure.h"
//******************************************************
//create
void create(List *l)
{
    l->head = NULL;
    l->size = 0;
}
//******************************************************
//is empty
int isEmpty(List l)
{
    return !l.size;
    //or  return l.head == NULL;
}
//******************************************************
//is full
int isFull(List l)
{
    return 0;
}
//******************************************************
//size
int listSize(List l)
{
    return l.size;
}
//******************************************************
//destroy
void destroyList(List *l)
{
    Node *q;
    while( l->head )
    {
        q = l->head->pNext;
        free(l->head);
        l->head = q;
    }
    l->size = 0;
}
//******************************************************
//traverse
void traverse(List *l, void (*operation)(type *el) )
{
    Node *q;
    q = l->head;
    while(q)
    {
        (*operation)(&q->el);
        q = q->pNext;
    }
}
//******************************************************
//insert
int insertList(List *l,type el,int p)
{
    if( p >= 0 && p <= l->size )
    {
        Node *pNewNode = (Node*) malloc( sizeof(Node) );
        if(pNewNode)//if malloc success to book memory
        {
            strcpy(pNewNode->el.name,el.name);
            pNewNode->el.bir.day        = el.bir.day;
            pNewNode->el.bir.month      = el.bir.month;
            pNewNode->el.bir.year       = el.bir.year;
            strcpy(pNewNode->el.add.city,el.add.city);
            strcpy(pNewNode->el.add.street,el.add.street);
            strcpy(pNewNode->el.add.zip,el.add.zip);
            strcpy(pNewNode->el.comp.name,el.comp.name);
            strcpy(pNewNode->el.comp.address,el.comp.address);
            strcpy(pNewNode->el.comp.number,el.comp.number);
            Node *q ;
            q = l->head;
            for(int i=0;i<p-1;i++)
            {
                q = q->pNext;
            }
            if(p==0)
            {
                pNewNode->pNext = q;//here q can be l->head
                l->head = pNewNode;//here l->head can't be q
                /*
                    because if you make q refer to pNewNode
                    you don't change l->head
                */
            }
            else
            {
                pNewNode->pNext = q->pNext;
                q->pNext = pNewNode;
            }

            l->size++;
            return 1;//success insert
        }
        else
            return 0;//fail to book size in memory
    }
    else
        return 0;//fail to insert
}
//******************************************************
//delete from list
int deleteEl_List(List *l,type *el,int p)
{
    if(  (p>=0) && (p < l->size) && ( !isEmpty(*l) )  )
    {
        if(p==0)
        {
            Node *q = l->head;
            strcpy(el->name,q->el.name);
            el->bir.day  = q->el.bir.day;
            el->bir.month = q->el.bir.month;
            el->bir.year       = q->el.bir.year;
            strcpy(el->add.city,q->el.add.city);
            strcpy(el->add.street,q->el.add.street);
            strcpy(el->add.zip,q->el.add.zip);
            strcpy(el->comp.name,q->el.comp.name);
            strcpy(el->comp.address,q->el.comp.address);
            strcpy(el->comp.number,q->el.comp.number);
            l->head = q->pNext;
            free(q);
        }
        else
        {
            Node *q = l->head;
            Node *d;
            for(int i=0;i<p-1;i++)
                q = q->pNext;
            d = q->pNext;
            q->pNext = d->pNext;
            *el = d->el;
            free(d);
        }
        l->size--;
        return 1;
    }
    else
        return 0;
}
//******************************************************
//retrieve elment
int retrieve(List *l,type *el,int p)
{
    if(p >= 0 && p <= l->size && !isEmpty(*l))
    {
        Node *q = l->head;
        for(int i=0;i<p;i++)
            q = q->pNext;
        strcpy(el->name,q->el.name);
        el->bir.day  = q->el.bir.day;
        el->bir.month = q->el.bir.month;
        el->bir.year       = q->el.bir.year;
        strcpy(el->add.city,q->el.add.city);
        strcpy(el->add.street,q->el.add.street);
        strcpy(el->add.zip,q->el.add.zip);
        strcpy(el->comp.name,q->el.comp.name);
        strcpy(el->comp.address,q->el.comp.address);
        strcpy(el->comp.number,q->el.comp.number);

        return 1;
    }
    else
        return 0;
}
//******************************************************
//replace elment
int replace(List *l,type el,int p)
{
    Node *q = l->head;
    for(int i=0;i<p;i++)
        q = q->pNext;
    q->el = el;
    strcpy(q->el.name,el.name);
    q->el.bir.day       =el.bir.day;
    el.bir.month        = q->el.bir.month;
    el.bir.year         = q->el.bir.year;
    strcpy(q->el.add.city,el.add.city);
    strcpy(q->el.add.street,el.add.street);
    strcpy(q->el.add.zip,el.add.zip);
    strcpy(q->el.comp.name,el.comp.name);
    strcpy(q->el.comp.address,el.comp.address);
    strcpy(q->el.comp.number,el.comp.number);
    return 1;
}
//******************************************************
//input information
void input_information (type *el)
{
    printf("name: ");
    scanf("%s",el->name);
    printf("Adress:-\n");
    printf("street: ");
    scanf("%s",el->add.street);
    printf("city: ");
    scanf("%s",el->add.city);
    printf("zip: ");
    scanf("%s",el->add.zip);
    printf("Birthday:-\n");
    printf("day: ");
    scanf("%d",&el->bir.day);
    printf("month: ");
    scanf("%d",&el->bir.month);
    printf("year: ");
    scanf("%d",&el->bir.year);
    printf("compny:-\n");
    printf("name: ");
    scanf("%s",el->comp.name);
    printf("Address: ");
    scanf("%s",el->comp.address);
    printf("phone number: ");
    scanf("%s",el->comp.number);
}
