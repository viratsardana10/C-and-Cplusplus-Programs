/*
 * queue.h
 *
 *  Created on: 24-Jul-2010
 *      Author: vivek
 */

#ifndef QUEUE_H_
#define QUEUE_H_

typedef int ElementType;
#ifndef _Queue_h
#define _Queue_h

struct QueueRecord;
typedef struct QueueRecord *Queue;

int IsEmpty( Queue Q );
int IsFull( Queue Q );
Queue CreateQueue( int MaxElements );
void DisposeQueue( Queue Q );
void MakeEmpty( Queue Q );
void Enqueue( ElementType X, Queue Q );
ElementType Front( Queue Q );
void Dequeue( Queue Q );
ElementType FrontAndDequeue( Queue Q );


#endif /* QUEUE_H_ */
