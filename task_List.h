#ifndef SOURCES_TASK_LIST_H
#define SOURCES_TAKS_LIST_H

#include <stdint.h>
#include <stdio.h>
#include "options.h"
#include "../FreeRTOS_Source/include/FreeRTOS.h"
#include "../FreeRTOS_Source/include/queue.h"
#include "../FreeRTOS_Source/include/semphr.h"
#include "../FreeRTOS_Source/include/task.h"
#include "../FreeRTOS_Source/include/timers.h"

typedef struct dd_Task
{
    TaskHandle_t t_Handle;
    TickType_t t_Deadline;
    uint32_t t_Type;
    TickType_t t_Release_Time;
    TickType_t t_Completion_Time;
    uint32_t t_ID;
    char* t_Name;
};
typedef struct task_List {
	struct dd_Task t_Task;
    struct task_List* t_Next;
}task_List, task_Node;

//list function prototypes
void List_Add(task_List *, dd_Task *);
void List_Remove(task_List *,uint32_t t_ID);
void List_Delete(task_List *);
int List_Size(task_List *);
//list debug functions prototypes
void Print_List(task_List *);

#endif
