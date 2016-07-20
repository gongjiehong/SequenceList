//
//  main.cpp
//  AlgorithmString
//
//  Created by 龚杰洪 on 16/7/12.
//  Copyright © 2016年 龚杰洪. All rights reserved.
//

#include <iostream>
#include "SequenceList.h"

using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    SequenceList testList;
    DataType element;
    
    
    init_list(&testList);
    
    int size = sizeof(testList);
    
    if (list_is_empty(testList))
    {
        std::cout << "表是空表\n";
    }
    
    for (int i = 0; i < 101; i++)
    {
        if (insert_list(&testList, i + 1, i))
        {
            std::cout << "插入成功\n";
        }
        else
        {
            std::cout << "插入失败\n";
        }
    }
    
    delete_list(&testList, 33, &element);
    delete_list(&testList, 33, &element);
    delete_list(&testList, 33, &element);
    
    for (int i = 0; i < 110; i++)
    {
        if (get_element(testList, i + 1, &element))
        {
            std::cout << "第" << i << "个元素是" << element << endl;
        }
        else
        {
            std::cout << "error" << endl;
        }
    }
    
    int t = locate_element(testList, 101);
    if (t == 0)
    {
        std::cout << "没找到";
    }
    else
    {
        std::cout << "找到了 元素在第" << t << "个";
    }
    
    int length = list_length(testList);
    std::cout << "现在长度： " << length;
    
    size = sizeof(testList);
    
    clear_list(&testList);
    
    length = list_length(testList);
    
    std::cout << "清空后长度： " << length;
    
    size = sizeof(testList);
    
    return 0;
}


