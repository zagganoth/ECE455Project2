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


typedef struct task_List {
    TaskHandle_t t_Handle;
    TickType_t t_Deadline;
    uint32_t t_Type;
    char* t_Name;
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
