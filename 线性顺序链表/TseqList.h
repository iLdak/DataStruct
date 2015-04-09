#ifndef _SEQLIST_H_
#define _SEQLIST_H_

typedef void seqList;
typedef void seqListNode;

seqList* SeqList_Create(int capacity);

void SeqList_Destroy(seqList* list);

void SeqList_Clear(seqList* list);

int SeqList_Length(seqList* list);

int SeqList_Capacity(seqList* list);

int SeqList_Insert(seqList* list, seqListNode* node, int pos);

seqListNode* SeqList_Get(seqList* list, int pos);

seqListNode* SeqList_Delete(seqList* list, int pos);

#endif

