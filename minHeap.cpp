#include "minHeap.h"

MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    heaparray = new job[cap];
}

void MinHeap::insertKey(job k)
{
    if (heap_size == capacity)
    {
        std::cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    heap_size++;
    int i = heap_size - 1;
    heaparray[i] = k;

    while (i != 0 && (heaparray[parent(i)].processingTime > heaparray[i].processingTime))
    {
        swap(&heaparray[i], &heaparray[parent(i)]);
        i = parent(i);
    }

    if (i == 0) {
        if (heap_size > 1 && (heaparray[1].processingTime < heaparray[0].processingTime)) {
            swap(&heaparray[1], &heaparray[0]);
        }
        if (heap_size > 2 && (heaparray[2].processingTime < heaparray[0].processingTime)) {
            swap(&heaparray[2], &heaparray[0]);
        }
    }
}

bool MinHeap::isEmpty()
{
    if (heap_size == 0) {
        return true;
    }
    else {
        return false;
    }
}

void MinHeap::swap(job* x, job* y)
{
    job temp = *x;
    *x = *y;
    *y = temp;

}

void MinHeap::print()
{
    for (int arr_i = 0; arr_i < heap_size; arr_i++) {
        std::cout << "Type " << heaparray[arr_i].jobType << "   "
            << "Arrival Time " << heaparray[arr_i].arrivalTime << "   "
            << "Job Number " << heaparray[arr_i].jobNumber << "   "
            << "Type Number " << heaparray[arr_i].typeNumber << "   "
            << "Processing Time " << heaparray[arr_i].processingTime << std::endl;
    }
}

void MinHeap::addWaitTime()
{
    if (heap_size > 0) {
        for (int arr_i = 0; arr_i < heap_size; arr_i++) {
            heaparray[arr_i].waitTime++;
        }
    }

}

int MinHeap::getRemainingWaitTime()
{
    int totalWait = 0;
    if (heap_size > 0) {
        for (int arr_i = 0; arr_i < heap_size; arr_i++) {
            totalWait = totalWait + heaparray[arr_i].waitTime;
        }
    }
    return totalWait;
}

job MinHeap::extractMin()
{
    if (heap_size <= 0) {
        return { ' ',0,0,0,0 };
    }

    if (heap_size == 1)
    {
        heap_size--;
        return heaparray[0];
    }
    job root = heaparray[0];
    heaparray[0] = heaparray[heap_size - 1];
    heap_size--;
    MinHeapify(0);

    return root;
}

void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && heaparray[l].processingTime < heaparray[i].processingTime)
        smallest = l;
    if (r < heap_size && heaparray[r].processingTime < heaparray[smallest].processingTime)
        smallest = r;
    if (smallest != i)
    {
        swap(&heaparray[i], &heaparray[smallest]);
        MinHeapify(smallest);
    }
}