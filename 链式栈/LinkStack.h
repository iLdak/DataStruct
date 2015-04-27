#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_

typedef void LinkStack;

LinkStack* LinkStack_Creat();

void LinkStack_Destroy(LinkStack* stack);

void LinkStack_Clear(LinkStack* stack);

int LinkStack_Push(LinkStack* stack, void* node);

void* LinkStack_Pop(LinkStack* stack);

void* LinkStack_Top(LinkStack* stack);

int LinkStack_Size(LinkStack* stack);

int LinkStack_Capacity(LinkStack* stack);

#endif
