#include "declarations.h"


int main()
{
    srand(time(0));
    
    task1Demo();
    Sleep(5000);
    task2();
    
    //----- Sample Code -----//

    //DLL<int> List;

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
    
    return 0;
}


void task1Demo()
{
    // See README.md on github for drawing/visualization. 
    QLL<int> QList(0);
    QList.PrintEnvir();
    Sleep(3000);
    QList.Add(1, QLL_Base::right);
    Sleep(3000);
    QList.Move(QLL_Base::left);
    Sleep(3000);
    QList.Add(2, QLL_Base::up);
    Sleep(3000);
    QList.Move(QLL_Base::down);
    Sleep(3000);
    QList.Move(QLL_Base::right);
    Sleep(3000);
    QList.Add(3, QLL_Base::up);
    Sleep(3000);
    QList.Add(4, QLL_Base::up);
    Sleep(3000);
    QList.Add(5, QLL_Base::left);
    Sleep(3000);
    
    system("cls");
    QList.PrintSorted();
}


void task2()
{
    const int arrSize = 40;
    int arr[arrSize];

    // Populate array with random numbers
    for (int i{}; i < arrSize; i++) arr[i] = rand() % 10;

    // Transfer data to a doubly linked list
    DLL<int> List;
    List.add(arr, arrSize);

    // Insert new data in the middle
    List.insert(999, List.size() >> 1);

    List.print(DLL_Base::forward);

    quicksort(List);

    List.print(DLL_Base::forward);

    List.clearDuplicates();

    List.print(DLL_Base::forward);
    List.print(DLL_Base::backwards);
}


