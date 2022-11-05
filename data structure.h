#ifndef QUEUE
#define QUEUE
#define MAX 500
#define MAXCHAR 50
typedef struct birthday
{
    int day;
    int month;
    int year;
}Date;
typedef struct address
{
    char street[MAXCHAR];
    char city[MAXCHAR];
    char zip[MAXCHAR];
}Address;
typedef struct compny
{
    char name[MAXCHAR];
    char address[MAXCHAR];
    char number[MAXCHAR];
}Compny;
//********************************************
typedef struct employee
{
    char name[MAXCHAR];
    Address add;
    Date bir;
    Compny comp;

}Employee ;
typedef struct NodeList
{
    Employee el;
    struct NodeList *pNext;
}Node;
typedef struct list
{
    Node *head;
    int size;
}List;
//******************************************************
typedef Employee type;
//******************************************************
//create
void create(List *l);
//******************************************************
//is empty
int isEmpty(List l);
//******************************************************
//is full
int isFull(List l);
//******************************************************
//size
int listSize(List l);
//******************************************************
//destroy
void destroyList(List *l);
//******************************************************
//traverse
void traverse(List *l, void (*operation)(type *el) );
//******************************************************
//insert
int insertList(List *l,type el,int p);
//******************************************************
//delete from list
int deleteEl_List(List *l,type *el,int p);
//******************************************************
//retrieve elment
int retrieve(List *l,type *el,int p);
//******************************************************
//replace elment
int replace(List *l,type el,int p);
//******************************************************
//info
void input_information (type *el);
//********************************************************

#endif // QUEUE






