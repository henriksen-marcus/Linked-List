# Linked-List
This project consists of two classes with a doubly linked list;

<img src="https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2014/03/DLL1.png" width = "600">

and a quad linked list:

<img src="https://user-images.githubusercontent.com/89453098/193153582-946a2aae-9cdd-4583-81cf-3287c2455d5d.png" width = "600">
<i>image credit: taheri-meisam</i><br><br>


The doubly linked list includes an optimization algorithm that reduces move operations by 90% when sorting the linked list using quicksort.
Instead of starting from _head_ and doing `node->next` until we find the desired index, we save the last used index and compare the length needed to go to get to the desired index. This greatly reduces move operations in sorting algorithms.

<img src="https://user-images.githubusercontent.com/89453098/193157399-81331043-e48a-447d-907b-21f3dd72356a.png" width = "600">

Here you can see that starting from the previous node/index is faster than starting from head.


### Visualization of the quad linked list demo:

<img src="https://user-images.githubusercontent.com/89453098/193154955-efb4525c-8d32-4131-958d-e49b2c034bf3.png" width = "350">

- The user decides where to add a new node
- The user can traverse/move between nodes
- The program automatically connects to adjacent nodes
- The program can print all nodes

The _green_ line represents the parth the _cursor_ is taking in the **task1Demo()**.
The _red_ lines represent automatic connections made by the program.
The numbers represent the order the nodes were added in.
