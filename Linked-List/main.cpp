#include <iostream>
#include "SingleLinkedList.h"

int main()
{
    SLL<int> List;

    List.Add(1);
    List.Add(2);
    List.Add(712);
    List.Add(3);
    List.Add(4);

    List.Print();
}