#include <list>

#include "declarations.h"

int main()
{
    //DLL<int> List;
    
    //----- Sample Code -----//
    
    /*List.add(4);
    List.add(3);
    List.add(712);
    List.add(2);
    List.add(1);*/

    /*int arr[6] = {6,4,2,7,9,1};
    List.add(myarr, 6);*/
    
    /*List.print(DLL_Base::forward);
    //bubblesort(List);
    //selectionsort(List);
    //insertionsort(List);
    //mergesort(List);
    quicksort(List);
    List.print(DLL_Base::forward);*/
    
    /*List.remove(2);
    List.print(DLL_Base::backwards);*/

    /*List.insert(77777, 5);
    List.print(DLL_Base::backwards);*/
    
    //----- End Sample Code -----//

    QLL<int> QList(1);

    QList.Add(2, QLL_Base::left);
    QList.Add(3, QLL_Base::down);
    QList.Add(4, QLL_Base::up);
    //QList.Add(5, QLL_Base::down);
    //QList.Add(6, QLL_Base::left);
    //QList.Add(7, QLL_Base::left);
    //QList.Add(8, QLL_Base::left);
    //QList.Add(9, QLL_Base::up);
    //QList.Add(10, QLL_Base::up);

    
    QList.Print();

    //for (int i{}; i < 10; i++)
    //{
    //    List.fill(DLL_Base::rand, 0, 99, 50);
    //    quicksort(List);
    //    List.clear();
    //}
    
    return 0;
}