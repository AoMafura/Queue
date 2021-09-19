#include "CircularArrayQ.h"



/** \fn CircularArrayQueue create_array_queue();
 *  \brief Create an empty circular array queue.
*/
CircularArrayQueue create_array_queue(){
	CircularArrayQueue q;
	return q;
}

/** \fn void init_array_queue(CircularArrayQueue *list);
 *  \brief Initialize as an empty circular array queue.
 *  \param list The queue that needs to be initialize.
*/
void init_array_queue(CircularArrayQueue *list){
	list->front = 1;
	list->rear = 0;
}

/** \fn bool enqueue(CircularArrayQueue *list, Type p);
 *  \brief Adds a new person element into the last element available in the current queue. Returns true for a successful operation otherwise false.
 *  \param list The current queue.
 *  \param p The person to be added in the queue.
*/
bool enqueue(CircularArrayQueue *list, Type p){
	if(is_full(*list) != true){
		list->rear = (list->rear+1)%MAX;
		list->data[list->rear] = p;
	}
}

/** \fn bool dequeue(CircularArrayQueue *list);
 *  \brief Remove the first inserted element from the current queue. Returns true for a successful operation otherwise false.
 *  \param list The current queue.
*/
bool dequeue(CircularArrayQueue *list){
	if(is_empty(*list) != true){
		list->front = (list->front+1)%MAX;
	}
}

/** \fn bool is_empty(CircularArrayQueue list);
 *  \brief Return true if the current list is empty otherwise false.
 *  \param list The current queue.
*/
bool is_empty(CircularArrayQueue list){
	return ((list.rear+1)%MAX == list.front) ? true : false;
}

/** \fn bool is_full(CircularArrayQueue list);
 *  \brief Return true if the current list is full otherwise false.
 *  \param list The current queue.
*/
bool is_full(CircularArrayQueue list){
	return ((list.rear+2)%MAX == list.rear) ? true : false;
}

/** \fn Type front(CircularArrayQueue list);
 *  \brief Return the person in the front without removing them.
 *  \param list The current queue.
*/
Type front(CircularArrayQueue list){
	return list.data[list.front];
}
