#include <iostream>
#include "SingleLinkedList.h"
#include "Queue.h"

int main()
{
    SLL<int> List;

    List.Add(1);
    List.Add(2);
    List.Add(712);
    List.Add(3);
    List.Add(4);

    List.Print();

    Queue myQ;

    myQ.add(1);
    myQ.add(2);
    myQ.add(72);
    myQ.add(3);

    myQ.Print();
    myQ.RemoveFirst();
    myQ.Print();
}