#ifndef SOURCES_TASK_LIST_H
#define SOURCES_TAKS_LIST_H

#include <stdint.h>
#include <stdio.h>
#include "stm32f4_discovery.h"
#include "options.h"


typedef struct task_List {
    TaskHandle_t Handle;
    TickType_t t_deadline;
    uint32_t t_type;
    char* t_name;
    struct task_List* t_next;
}task_List, task_Node;

//list function prototypes
void List_Add(task_List *, TaskHandle_t, TickType_t);
void list_remove(task_List *,TaskHandle_t );
void list_delete(task_List *);

#endif 
