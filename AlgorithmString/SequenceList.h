//
//  SequenceList.h
//  AlgorithmString
//
//  Created by 龚杰洪 on 16/7/13.
//  Copyright © 2016年 龚杰洪. All rights reserved.
//

#ifndef SequenceList_h
#define SequenceList_h

#define ListSize 100 // 定义存储空间大小
typedef int DataType; // 定义类型

typedef struct
{
    DataType list[ListSize]; // 线性表的存储空间
    int length; // 线性表的长度
    
}SequenceList;

void init_list(SequenceList *seq_list);
bool list_is_empty(SequenceList seq_list);
int locate_element(SequenceList seq_list, DataType element);
bool get_element(SequenceList seq_list, int index, DataType *element);
bool insert_list(SequenceList *seq_list, int index, DataType element);
bool delete_list(SequenceList *seq_list, int index, DataType *element);
int  list_length(SequenceList seq_list);
void clear_list(SequenceList *seq_list);

void init_list(SequenceList *seq_list)
{
    seq_list -> length = 0; //线性表的长度，初始化为0
}

bool list_is_empty(SequenceList seq_list)
{
    if (seq_list.length == 0)
    {
        return false;
    }
    return true;
}

int locate_element(SequenceList seq_list, DataType element)
{
    for (int i = 0; i < seq_list.length; i++)
    {
        if (seq_list.list[i] == element)
        {
            return i+1;
        }
    }
    return 0;
}

bool get_element(SequenceList seq_list, int index, DataType *element)
{
    if (index < 1 || index > seq_list.length)
    {
        printf("越界了");
        return false;
    }
    *element = seq_list.list[index - 1];
    return true;
}

bool insert_list(SequenceList *seq_list, int index, DataType element)
{
    if (index < 1 || index > seq_list -> length + 1)
    {
        printf("越界了");
        return false;
    }
    else if (seq_list -> length >= ListSize)
    {
        printf("表满了");
        return false;
    }
    else
    {
        for (int j = seq_list->length; j >= index; j--)
        {
            seq_list->list[j] = seq_list->list[j-1];  ///移动顺序表的元素
        }
        seq_list->list[index - 1] = element;  ///插入该元素
        seq_list->length = seq_list->length+1; ///增加表长
        return true;
    }
}

bool delete_list(SequenceList *seq_list, int index, DataType *element)
{
    // 判断位置是否是空表
    if (seq_list->length == 0)
    {
        printf("空表不能删除\n");
        return false;
    }
    else if(index < 1 || index > seq_list->length)
    {
        printf("位置不合法\n");
        return false;
    }
    else
    {
        *element = seq_list->list[index - 1];
        for (int j = index; j < seq_list->length - 1; j++)
        {
            seq_list->list[j - 1] = seq_list->list[j]; ///移动元素
        }
        seq_list->length = seq_list->length -1;  ///表长减少
        return true;
    }
}

int  list_length(SequenceList seq_list)
{
    return seq_list.length;
}

void clear_list(SequenceList *seq_list)
{
    seq_list->length = 0;
}


#endif /* SequenceList_h */
