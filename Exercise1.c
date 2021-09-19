#ifndef EXERCISE1_H
#define EXERCISE1_H

#include <stdio.h>
#include <stdlib.h>
#include "CircularArrayQ.h"
#include "Exercise1.h"

/** \fn int get_queue_length(CircularArrayQueue list);
 *  \brief Get the number of elements in the current queue.
 *  \param list The current queue.
*/
int get_queue_length(CircularArrayQueue list){
	return (list.rear>list.front) ? 
			list.rear-list.front : MAX - list.front + list.rear;
}

/** \fn PersonLinkedList get_all_females(CircularArrayQueue list);
 *  \brief Returns all females as a linked list using the current list without removing them in the current list.
 *  \param list The current queue.
 *  Note: Use the queue basic operations (enqueue, dequeue, front)
*/
PersonLinkedList get_all_females(CircularArrayQueue list){
	PersonLinkedList LL = NULL;
	Type temp;
	int count = get_queue_length(list);
	
	while(count>-1){
		temp = front(list);
		dequeue(&list);
		enqueue(&list, temp);
		if(temp.sex=='F'){
			insert_first_LL(&LL, temp);
		}
		count--;
	}
	return LL;
}

/** \fn PersonDynamicArrayList remove_all_males(CircularArrayQueue *list);
 *  \brief Remove all males in the current list and returns the removed males as a dynamic array list.
 *  \param list The current queue.
 *  Note: Use the concept of queue with out using the basic operations.
*/
PersonDynamicArrayList remove_all_males(CircularArrayQueue *list){
	PersonDynamicArrayList DAL;
	Person temp;
	int count;
	
	if((list->rear+2)%MAX != list->front){
		init_DAL(&DAL);
		
		if(list->rear>list->front){ //Count
			count = list->rear-list->front;
		}else{
			count = MAX - list->front+list->rear;
		}
		
		for(; count!=-1; list->front = (list->front+1)%MAX, count--){
			temp = list->data[list->front]; //front & store
			list->front = (list->front+1) % MAX; //dequeue
			list->rear = (list->rear+1)%MAX; //enqueue
			list->data[list->rear] = temp; 
			
			if(DAL.count+1 > DAL.max){ //Resize
				DAL.max = DAL.max * 2;
				realloc(DAL.data, DAL.max);
			}
			DAL.data[DAL.count] = temp; //insertLast;
			DAL.count++;
		}
	}
}

void displayQueue(CircularArrayQueue *list){
	int count = get_queue_length(*list);
	Person p;
	printf("\nDISPLAY CAQ {");
	while(count>-1){
		p = front(*list);
		dequeue(list);
		count--;
		enqueue(list, p);
		
		displayPersonInfo(p);
	}
	printf("\n\n}");
}

#endif








