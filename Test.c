#include <stdio.h>
#include <string.h>
#include "Exercise1.h"
#include <stdlib.h>

#include "CircularArrayQ.h"

void newPerson(Person *p, char *x);
void funcSAL(PersonStaticArrayList *SAL, Person *p, char *x);
void funcDAL(PersonDynamicArrayList *SAL, Person *p, char *x);
void funcCAQ(CircularArrayQueue *list, Person* p, char x[], PersonLinkedList LL, PersonDynamicArrayList DAL);

int main(void) 
{
	char x[2] = "A";
	Person p = createPerson("Astolfo", 'M', "Throne of Heroes");
	PersonStaticArrayList SAL;
    PersonDynamicArrayList DAL, DAL2;
    PersonLinkedList PLL;
    PersonCusorBasedList CBL;
    VSpace VS;
    CircularArrayQueue CAQ;
    
    PersonLinkedList FList;
    PersonDynamicArrayList MList;
    
    funcSAL(&SAL, &p, x);
    funcDAL(&DAL, &p, x);
    funcCAQ(&CAQ, &p, x, PLL, DAL2);
    
    return 0;
}

void funcCAQ(CircularArrayQueue *list, Person *p, char y[], PersonLinkedList LL, PersonDynamicArrayList DAL){
	int x;
	init_array_queue(list);
	
	for(x=0;x<28;x++){
		newPerson(p, y);
		enqueue(list, *p);
	}
	
	displayQueue(list);
	printf("\nENQUEUE\n");
	system("pause");
	system("CLS");
	
	for(x=0;x<2;x++){
		dequeue(list);
	}
	
	displayQueue(list);
	printf("\nDEQUEUE\n");
	system("pause");
	system("CLS");
	
	LL = get_all_females(*list);
	
	display_LL(LL);
	printf("\nDISPLAY FEMALES WITH LINKED LIST\n");
	system("pause");
	system("CLS");
	
	DAL = remove_all_males(list);
	
	display_DAL(DAL);
	printf("\nDISPLAY MALES WITH LINKED LIST\n");
	system("pause");
	system("CLS");
	
	displayQueue(list);
	printf("\nDEQUEUE\n");
	system("pause");
	system("CLS");
}

void newPerson(Person *p, char *x){
	if(p->sex=='M' && (*x-65)%6 != 0){
		p->sex='F';
	}else{
		p->sex='M';
	}
	strcpy(p->city, "Throne of Heroes ");
	strcat(p->city, x);
	*x = ((*x-64) % 22) + 65;
}

void funcSAL(PersonStaticArrayList *list, Person *p, char *y){
	int x;
	init_SAL(list);
	
	for(x=0;x<7;x++){
		newPerson(p, y);
		insert_first_SAL(list, *p);
	}
	
	
	for(x=0;x<7;x++){
		newPerson(p, y);
		insert_last_SAL(list, *p);
	}
	
	for(x=0;x<7;x++){
		newPerson(p, y);
		insert_at_SAL(list, *p, x+2);
	}
	
	display_SAL(*list);
	printf("\nINSERT\n");
	system("pause");
	system("CLS");
	
	delete_first_SAL(list);
	delete_last_SAL(list);
	
	display_SAL(*list);
	printf("\nDELETE FIRST LAST\n");
	system("pause");
	system("CLS");
	
	delete_by_sex_SAL(list,'M');
	
	display_SAL(*list);
	printf("\nDELETE ALL MALE\n");
	system("pause");
	system("CLS");
}

void funcDAL(PersonDynamicArrayList *list, Person *p, char *y){
	int x;
	init_DAL(list);
	
	for(x=0;x<9;x++){
		newPerson(p, y);
		insert_first_DAL(list, *p);
	}
		
	for(x=0;x<9;x++){
		newPerson(p, y);
		insert_last_DAL(list, *p);
	}
	
	display_DAL(*list);
	printf("\nINSERT\n");
	system("pause");
	system("CLS");
	
	delete_first_DAL(list);
	delete_last_DAL(list);
	
	display_DAL(*list);
	printf("\nDELETE FIRST LAST\n");
	system("pause");
	system("CLS");
	
	delete_by_city_DAL(list,"Throne of Heroes F");
	delete_by_city_DAL(list,"Throne of Heroes A");
	delete_by_city_DAL(list,"Throne of Heroes H");
	
	display_DAL(*list);
	printf("\nDELETE CITY FAH\n");
	system("pause");
	system("CLS");
}
