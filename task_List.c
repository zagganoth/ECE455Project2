#include "task_List.h"
#include <stdlib.h>

void List_Add(task_List* old_t_List, dd_Task* new_task)
{
    /* Allocate memory for new node in list */
    task_List *temp = old_t_List;
    task_List *node = (task_List*) pvPortMalloc(sizeof(task_List));
    /* initialize node with task atributes */
    node-> t_Task -> t_Handle = new_task -> t_Handle;
    node-> t_Task -> t_Deadline = new_task -> t_Deadline;
    node-> t_Task -> t_Type = new_task -> t_Type;
    node-> t_Task -> t_Name = pcTaskGetName(new_task -> t_Handle);
    /* add node to list based on value of t_Deadline */
    //first case: new empty list
    if(temp-> t_task  == NULL)
    {
        vPortFree((void*)node);
        temp-> t_Task -> t_Deadline = new_task -> t_Deadline;
        temp-> t_Task -> t_Handle = new_task ->  t_Handle;
        temp-> t_Task -> t_Name = pcTaskGetName(new_task -> new_t_Handle);
        temp-> t_Next = NULL;
    }
    //next case: new task has earliest Deadline
    else if(temp-> t_task -> t_Handle > new_task -> t_Handle)
    {
        node->t_Next = old_t_List;
        old_t_List = node;
    }
    //last case: new task has Longer Deadline 
    else while(temp)
    {
        if(temp->t_Next && (temp->t_Next->t_task -> t_Deadline > new_task -> t_Deadline))
        {
            node -> t_Next = temp->t_Next;
            temp -> t_Next = node;
            temp = NULL;
            break;
        }
        else if (temp->t_Next == NULL)
        {
            node -> t_Next = temp -> t_Next;
            temp -> t_Next = node;
            temp = NULL;
            break;
        }
        temp = temp -> t_Next;
    }
    return;
}

void List_Remove(task_List * old_t_List, uint32_t task_ID)
{
    //first case: empty list
    if (old_t_List == NULL)
        return;
    task_List * temp = old_t_List;
    //second case: overdue tasks list
    if(old_t_List -> t_Type ==1)
        vPortFree(del_t_Handle);
    //third case: remove first task on list
    if((temp -> t_Task -> t_ID == task_ID) && temp -> t_Next)
    {
        task_Node* old_t = temp -> t_Next;
        *old_t_List = *temp -> t_Next;
        vPortFree((void*)old_t);
    }
    //fourth case: active list with one entry
    else if((temp -> t_Task -> t_ID == task_ID) && temp -> t_Next)
    {
        old_t_List-> t_Next = 0;
        old_t_List -> t_ID = 0;
    }
    //general case: remove task entry specified by t_Handle
    else while(temp -> t_Next)
    {
        if (temp -> t_Next -> t_task -> t_ID == del_t_Handle)
        {
        task_Node * temp_2 = temp -> t_Next;
        temp->t_Next = temp_2 -> t_Next;
        vPortFree((void*)temp_2);
        }
        temp = temp -> t_Next;
    }
}

int List_Size(task_List * t_List){
    task_List * temp = t_List;
    int size =0;
    if (temp!=NULL)
    {
        while(temp -> t_Next)
        {
            size++;
            temp = temp -> t_Next;
        }
    }
    return size;
}

void Print_List(task_List * t_List){
    task_List * temp = t_List;
    int i = 1;
    if(temp!=NULL)
    {
        printf("Contents of List: (%d tasks on list)\n", List_Size(temp));
        printf("%d.    %s\n", i, temp -> t_Task -> t_Name);
        while(temp -> t_Next)
        {
            printf("%d.    %s\n", i, temp -> T_task -> t_Name);
            temp = temp -> t_Next;
        }
    }

    return;
}
