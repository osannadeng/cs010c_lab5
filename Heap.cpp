#include <iostream>
#include "Heap.h"

using std::swap;

// inserts a job to the heap
void Heap::enqueue(PrintJob* job){
    // if list is empty, just add to top
    if (numItems == 0) {
       arr[numItems] = job;
       ++numItems;
       return;
    }
    // if list is full, return -> would normally throw
    if (numItems >= MAX_HEAP_SIZE) return;
    // sets node to end of heap
    arr[numItems] = job;
    int index = numItems;
    // percolate up -> swaps node with parent until it is in the right place within heap
    while (index > 0) { // iterates through max heap
        int parentIndex = (index - 1) / 2;
        // current priority is greater than the parents -> swap nodes, set index to parent index
        if(arr[index]->getPriority() > arr[parentIndex]->getPriority()) {
            swap(arr[index], arr[parentIndex]);
            index = parentIndex;
        }
        // exit loop if done
        else return;
    }
    // increments numItems after inserting node
    ++numItems;
}


// removes the node with highest priority from the heap
void Heap::dequeue(){
    // if max heap is empty, just returns -> would normally throw error
    if (numItems == 0) return;
    // if there are elements, replaces root with last node
    if (numItems > 0) {
       // sets initial to last node
       --numItems;
       arr[0] = arr[numItems];
       // percolates new root down to proper place in heap with helper
       trickleDown(0);
    }
}


// returns node with highest priority (root within a max heap)
PrintJob* Heap::highest(){
    // if heap is empty, return nullptr -> would normally throw error
    if (numItems == 0) return nullptr;
    // highest priority is root/first element
    return arr[0];
}


// prints job with highest priority
void Heap::print(){
    // if max heap is empty, just returns -> would normally throw error
    if (numItems == 0) return;
    cout<< "Priority: "<< highest()->getPriority()
        << ", Job Number: "<< highest()->getJobNumber()
        << ", Number of Pages: "<< highest()->getPages() << endl;
}


// called by dequeue to move new root down heap to appropriate location
void Heap::trickleDown(int index){
    int childIndex = (2 * index) + 1;
    PrintJob* maxJob = arr[index];
    // checks for when numItems is greater than child
    if (numItems > (index * 2) + 2) {
        // iterates while within heap size
        while (childIndex < MAX_HEAP_SIZE) {
            // finds max among the element and all of the element's children
            PrintJob* currMax = maxJob;
            int maxIndex = -1;
            // iterates through to find index that node should be at
            for (int i = 0; i < 2 && ((i + childIndex) < numItems); ++i) {
                // checks if priority is higher to find index
                if (arr[i+childIndex]->getPriority() > currMax->getPriority()) {
                    currMax = arr[i+childIndex];
                    maxIndex = i + childIndex;
                }
            }
            // does nothing if duplicate
            if (maxJob->getPages() == currMax->getPages()) return;
            // swaps the elements in heap to correct spot
            swap(arr[index], arr[maxIndex]);
            index = maxIndex;
            childIndex = (2 * index) + 1;
       }
   }
}
