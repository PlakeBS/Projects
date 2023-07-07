#pragma once
#include <iostream>
#include "jobStack.h"

class MinHeap
{
    job* heaparray;
    int capacity;
    int heap_size;
public:
    MinHeap(int capacity);
    void MinHeapify(int);
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }
    job extractMin();
    job getMin() { return heaparray[0]; }
    void insertKey(job k);
    bool isEmpty();
    void swap(job* x, job* y);
    void print();
    int size() { return heap_size; }
    void addWaitTime();
    int getRemainingWaitTime();
};