#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Person.h"

Person createPerson(String name, char sex, String city) {
    Person p;

    strcpy(p.name, name);
    p.sex = sex;
    strcpy(p.city, city);

    return p;
}

void displayPersonInfo(Person p) {
    printf("\n\t{%30s | %c | %-30s}", p.name, p.sex, p.city);
}

/* Static Array List*/
void init_SAL(PersonStaticArrayList *list){
	list->count=0;
}

void insert_first_SAL(PersonStaticArrayList *list, Person p){
	int x;
	if(list->count!=MAX_LIST){
		for(x=list->count-1;x>-1;x--){
			list->data[x+1] = list->data[x];
		}
		list->data[0] = p;
		list->count++;
	}
}

void insert_last_SAL(PersonStaticArrayList *list, Person p){
	if(list->count!=MAX_LIST){
		list->data[list->count]=p;
		list->count++;
	}
}

void insert_at_SAL(PersonStaticArrayList *list, Person p, int index){
	int x;
	if(list->count!=MAX_LIST){
		for(x=list->count-1; x>index-1; x--){
			list->data[x+1]=list->data[x];
		}
		list->data[index] = p;
		list->count++;
	}
}

void delete_first_SAL(PersonStaticArrayList *list){
	int x;
	if(list->count==1){
		list->count--;
	}else if(list->count > 1){
		for(x=1;x<list->count;x++){
			list->data[x-1] = list->data[x];
		}
		list->count--;
	}
}

void delete_last_SAL(PersonStaticArrayList *list){
	if(list->count>0){
		list->count--;	
	}
}

void delete_by_sex_SAL(PersonStaticArrayList *list, char sex){ // all ocurrences
	int x, y;
	for(x=0;x<list->count;x++){
		if(list->data[x].sex == sex){
			
			for(y=x+1;y<list->count;y++){
				list->data[y-1] = list->data[y];
			}
			
			list->count--;
		}
	}
}

void display_SAL(PersonStaticArrayList list){
	int x;
	printf("\nDISPLAY SAL {");
	for(x=0;x<list.count;x++){
		displayPersonInfo(list.data[x]);
	}
	printf("\n\n}");	
}


/* Dynamic Array List - v1 
 * Doubles the maximum size of the array when full.
 */
void init_DAL(PersonDynamicArrayList *list){
	list->data = (Person*) malloc(sizeof(Person)*MAX_LIST);
	if(list->data!=NULL){
		list->count=0;
		list->max = MAX_LIST;	
	}else{
		list->count=-1;
	}
}

void insert_first_DAL(PersonDynamicArrayList *list, Person p){
	int x;
	if(list->count==list->max){
		list->max=list->max*2;
		realloc(list->data, list->max);
	}
	for(x=list->count-1;x>-1;x--){
		list->data[x+1] = list->data[x];
	}
	list->data[0]=p;
	list->count++;
}

void insert_last_DAL(PersonDynamicArrayList *list, Person p){
	if(list->count==list->max){
		list->max=list->max*2;
		realloc(list->data,list->max);
	}
	list->data[list->count] = p;
	list->count++;
}

void insert_at_DAL(PersonDynamicArrayList *list, Person p, int index){
	int x;
	if(list->count==0){
		list->data[0] = p;
		list->count++;
	}else{
		if(list->count==list->max){
			list->max = list->max * 2;
			realloc(list->data, list->max);
		}
		for(x=list->count; x > index; x--){
			list->data[x] = list->data[x-1];
		}
		list->data[x] = p;
		list->count++;
	}
}

void delete_first_DAL(PersonDynamicArrayList *list){
	int x;
	if(list->count==1){
		list->count--;
	}else if(list->count>1){
		if(list->count-1 < list->max/2 && list->max/2 > MAX_LIST){
			list->max = list->max/2;
			realloc(list->data, list->max);
		}
		for(x=1;x<list->count;x++){
			list->data[x-1]=list->data[x];
		}
		list->count--;
	}
}

void delete_last_DAL(PersonDynamicArrayList *list){
	if(list->count>0){
		if(list->count-1 > list->max/2 && list->max/2 > MAX_LIST){
			list->max = list->max/2;
			realloc(list->data,list->max);
		}
		list->count--;
	}
}

void delete_by_city_DAL(PersonDynamicArrayList *list, String city){
	int x, y;
	if(list->count>0){
		for(x=0;x<list->count && strcmp(list->data[x].city, city)!=0;x++){}
		if(x!=list->count){
			if(list->count-1<list->max/2 && list->max/2 > MAX_LIST){
				list->max=list->max/2;
				realloc(list->data, list->max);
			}
			for(x++;x<list->count;x++){
				list->data[x-1] = list->data[x];
			}
			list->count--;
		}
	}
}

void display_DAL(PersonDynamicArrayList list){
	int x;
	printf("\nDISPLAY DAL {");
	for(x=0;x<list.count;x++){
		displayPersonInfo(list.data[x]);
	}
	printf("\n\n}");
}

/* Singly Linked List */
void insert_first_LL(PersonLinkedList *list, Person p){
	PersonLinkedList temp = (PersonNode*) malloc(sizeof(PersonNode));
	if(temp!=NULL){
		temp->elem = p;
		temp->next=*list;
		*list = temp;
	}
}

void insert_last_LL(PersonLinkedList *list, Person p){
	PersonLinkedList temp = (PersonNode*)malloc(sizeof(PersonNode)), *x;
	for(x=list; x!=NULL; x=&(*x)->next){}
	temp->elem=p;
	temp->next=NULL;
	*x=temp;
}

void insert_after_LL(PersonLinkedList *list, Person p, String name){
	PersonLinkedList temp = (PersonNode*)malloc(sizeof(PersonNode)), *x;
	for(x=list;x!=NULL && strcmp((*x)->elem.name, name)!=0; x=&(*x)->next){}
	temp->elem = p;
	temp->next = *x;
	*x = temp;
}
void delete_first_LL(PersonLinkedList *list){
	PersonLinkedList temp = *list;
	if(*list!=NULL){
		*list = (*list)->next;
		free(temp);
	}
}

void delete_last_LL(PersonLinkedList *list){
	PersonLinkedList temp, *x;
	if(*list != NULL){
		for(x=list;(*x)->next!=NULL;x=&(*x)->next){}
		temp = *x;
		*x = (*x)->next;
		free(temp);
	}
	
}

// all ocurrences
void delete_by_city_LL(PersonLinkedList *list, String city){
	PersonLinkedList temp, *x;
	for(x=list; *x!=NULL; x=&(*x)->next){
		if(strcmp((*x)->elem.city,city)==0){
			temp = *x;
			*x = (*x)->next;
			free(temp);
		}
	}
}

void display_LL(PersonLinkedList list){
	PersonLinkedList x;
	printf("\nDISPLAY LL {");
	for(x=list;x!=NULL;x=x->next){
		displayPersonInfo(list->elem);
	}
	printf("\n\n}");
}


/* Implement all VSpace conncept and Cusor Based List*/
void init_vspace(VSpace *vs){
	int x;
	vs->avail=MAX_VSPACE-1;
	
	for(x=MAX_VSPACE-1;x>-1;x--){
		vs->data[x].next = x-1;
	}
}

Position alloc_space(VSpace *vs){
	Position x = vs->avail;
	if(x!=-1){
		vs->avail = vs->data[x].next;
	}
	return x;
}

void free_space(VSpace *vs, Position index){
	if(index >-1 && index < MAX_VSPACE){
		vs->data[index].next = vs->avail;
		vs->avail = index;
	}
}

void insert_first_CBL(VSpace *vs, PersonCusorBasedList *list, Person p){
	Position temp = alloc_space(vs);
	if(temp!=-1){
		vs->data[temp].elem=p;
		vs->data[temp].next=*list;
		*list = temp;
	}
}

void insert_last_CBL(VSpace *vs, PersonCusorBasedList *list, Person p){
	Position temp = alloc_space(vs), *x;
	if(temp!=-1){
		for(x=list; *x!=-1; x = &vs->data[*x].next){}
		vs->data[temp].elem = p;
		vs->data[temp].next = -1;
		*x = temp;
	}
}

void insert_at_CBL(VSpace *vs, PersonCusorBasedList *list, Person p, int index){
	Position temp = alloc_space(vs), *x, count;
	if(temp!=-1){
		for(x=list; *x!=-1 && count!=index; x=&vs->data[*x].next, count++){}
		vs->data[*x].elem=p;
		vs->data[*x].next=*x;
		*x = temp;
	}
}

void delete_first_CBL(VSpace *vs, PersonCusorBasedList *list){
	Position temp;
	if(*list!=-1){
		temp = *list;
		*list = vs->data[*list].next;
		free_space(vs, temp);
	}
}

void delete_last_CBL(VSpace *vs, PersonCusorBasedList *list){
	Position temp, *x;
	if(*list!=-1){
		for(x = list; vs->data[*x].next!=-1; x=&vs->data[*x].next){}
		temp = *x;
		*x = vs->data[*x].next;
		free_space(vs, temp);
	}
}

// all ocurrences
void delete_by_sex_CBL(VSpace *vs, PersonCusorBasedList *list, char sex){
	Position temp, *x;
	if(*list != -1){
		for(x = list; *x!=-1; x=&vs->data[*x].next){
			if(vs->data[*x].elem.sex==sex){
				temp = *x;
				*x = vs->data[*x].next;
				free_space(vs, *x);
			}
		}
	}
}

void display_CBL(VSpace vs, PersonCusorBasedList list){
	Position x;
	printf("\nDISPLAY CBL {");
	for(x=list;x!=NULL;x=vs.data[x].next){
		displayPersonInfo(vs.data[x].elem);
	}
	printf("\n\n}");
	
}






