#include <iostream>
#include "DoubleLinkedList.h"
#include "Node.h"

int main()
{
    DLL<int> List;

    /*List.add(1);
    List.add(2);
    List.add(712);
    List.add(3);
    List.add(4);*/

    int myarr[3] = {6,4,2};

    List.add(myarr, 3);
    List.print(DLL_Base::forward);

    List.swap(0,1);
    cout << "space" << endl;
    List.print(DLL_Base::forward);
    

   // List.print(DLL_Base::forward);

    //List.remove(2);
    

    //List.print(DLL_Base::backwards);
    
    return 0;
}