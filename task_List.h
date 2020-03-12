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

typedef struct dd_task
{
    TaskHandle_t t_Handle;
    TickType_t t_Deadline;
    uint32_t t_Type;
    uint32_t t_ID;
    uint32_t t_Release_Time;
    uint32_t t_Completion_Time;
    char* t_Name;
};
typedef struct task_List {
	struct dd_task t_Task;
    struct task_List* t_Next;
}task_List, task_Node;

//list function prototypes
void List_Add(task_List *, TaskHandle_t, TickType_t);
void List_Remove(task_List *,TaskHandle_t );
void List_Delete(task_List *);
int List_Size(task_List *);
//list debug functions prototypes
void Print_List(task_List *);

#endif
