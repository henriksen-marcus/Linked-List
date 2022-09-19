#include <iostream>
#include "DoubleLinkedList.h"
#include "Queue.h"

int main()
{
    DLL<int> List;

    List.Add(1);
    List.Add(2);
    List.Add(712);
    List.Add(3);
    List.Add(4);

    List.Print();

    List.Remove(2);

    cout << endl << endl;

    List.Print();

#include "Node.h"
    Node<int>* Hey = new Node<int>();
    Hey->data = 1240;
    List.Insert(Hey, 2);
    cout << endl << endl;
    List.Print();
    
  /*  Queue myQ;

    myQ.add(1);
    myQ.add(2);
    myQ.add(72);
    myQ.add(3);

    myQ.Print();
    myQ.RemoveFirst();
    myQ.Print();*/
}