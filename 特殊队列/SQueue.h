#ifndef _SQUEUE_H_
#define _SQUEUE_H_

typedef void SQueue;

SQueue* SQueue_Create();

void SQueue_Destroy(SQueue* queue);

void SQueue_Clear(SQueue* queue);

void SQueue_Append(SQueue* queue, void* item);

void* SQueue_Departure(SQueue* queue);

void* SQueue_Header(SQueue* queue);

int SQueue_Length(SQueue* queue);

#endif
