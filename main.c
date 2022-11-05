#include <stdio.h>
#include <stdlib.h>
#include "data structure.h"
void print(type *el);
int main()
{
    List l;
    type el;
    create(&l);
    for(int i=0;i<3;i++)
    {
        printf("###############info-%d-###############\n",i+1);
        input_information(&el);
        insertList(&l,el,i);
    }
    deleteEl_List(&l,&el,1);
    traverse(&l,&print);
    return 0;
}
void print(type *el)
{
    printf("-----------------------------------------\n");
    printf("name:%s\n",el->name);
    printf("Address:-\n");
    printf("street: %s\n",el->add.street);
    printf("city: %s\n",el->add.city);
    printf("zip: %s\n",el->add.zip);
    printf("Date:-\n");
    printf("day: %d\n",el->bir.day);
    printf("month: %d\n",el->bir.month);
    printf("year: %d\n",el->bir.year);
    printf("compny:-\n");
    printf("name: %s\n",el->comp.name);
    printf("address: %s\n",el->comp.address);
    printf("phone number: %s\n",el->comp.number);
    printf("-----------------------------------------\n");
}






