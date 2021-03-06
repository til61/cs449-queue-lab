/* 
 * Developed by R. E. Bryant, 2017
 * Extended to store strings, 2018
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "harness.h"
#include "queue.h"

/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
queue_t *q_new()
{
  if(malloc(sizeof(queue_t)) == NULL){
      return NULL;
  }
  queue_t *q =  malloc(sizeof(queue_t));
  /* What if malloc returned NULL? */
  q->head = NULL;
  q->tail = NULL;
  q->size = 0;
  return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    /* How about freeing the list elements and the strings? */
    list_ele_t *curr = q->head;
    while(curr != NULL){
      list_ele_t * fNode = curr;
      char * fString = curr->value;
      free(fString);
      free(fNode);
      curr = curr->next;
    }
    /* Free queue structure */
    free(q);
}

/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    list_ele_t *newh;
    /* What should you do if the q is NULL? */
    if(q == NULL){
      return false;
    }
    if(malloc(sizeof(list_ele_t)) == NULL){
      return false;
    }
    newh = malloc(sizeof(list_ele_t));
    /* Don't forget to allocate space for the string and copy it */
    /* What if either call to malloc returns NULL? */
    if(malloc(sizeof(s)) == NULL){
      return false;
    }
    char * news = malloc(sizeof(s));
    strcpy(news, s);
    newh->value = news;
    newh->next = q->head;
    q->head = newh;
    if(q->size == 0){
      q->tail = newh;
    } 
    q->size++;
    return true;
}


/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    list_ele_t * newt;
    /* You need to write the complete code for this function */
    /* Remember: It should operate in O(1) time */
    if(q == NULL){
      return false;
    }
    if(malloc(sizeof(list_ele_t)) == NULL){
      return false;
    }
    newt =  malloc(sizeof(list_ele_t));
    if(malloc(sizeof(s)) == NULL){
      return false;
    }
    char * news = malloc(sizeof(s));
    strcpy(news ,s);
    newt->value = news;
    newt->next = NULL;
    if(q->size == 0){
      q->head = newt;
      q->tail = newt;
    }
    else{
      q->tail->next = newt;
      q->tail = newt;
    }
    q->size++;
    return true;
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If sp is non-NULL and an element is removed, copy the removed string to *sp
  (up to a maximum of bufsize-1 characters, plus a null terminator.)
  The space used by the list element and the string should be freed.
*/
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    /* You need to fix up this code. */
    if(q == NULL || q->head == NULL){
      return false;
    }
    if(sp != NULL){
      sp = q->head->value;
    }
    list_ele_t * oldhead = q->head;
    q->head = q->head->next;
    free(oldhead);
    q->size--;
    return true;
}

/*
  Return number of elements in queue.
  Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    /* You need to write the code for this function */
    /* Remember: It should operate in O(1) time */
    return q->size;
}

/*
  Reverse elements in queue
  No effect if q is NULL or empty
  This function should not allocate or free any list elements
  (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
  It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    /* You need to write the code for this function */
}

