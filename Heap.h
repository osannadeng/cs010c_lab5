#ifndef __HEAP_H
#define __HEAP_H

#include "PrintJob.h"

const int MAX_HEAP_SIZE = 10;

class Heap {
private:
  PrintJob* arr[MAX_HEAP_SIZE];
  int numItems;

public:
  // initializes empty heap
  Heap() : numItems(0) {}

  // inserts a PrintJob to heap without violating max-heap properties
  void enqueue(PrintJob*);

  // removes node with highest priority from heap
  void dequeue();

  // returns node with highest priority
  PrintJob* highest();

  // prints PrintJob with highest priority in the format -> Priority: priority, Job Number: jobNum, Number of Pages: numPages (new line at end)
  void print();

private:
  // called by dequeue to move new root down heap to appropriate location
  void trickleDown(int);
};
#endif