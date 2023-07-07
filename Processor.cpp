#include "Processor.h"


Processor::Processor()
{
}

void Processor::push(job inputJob)
{
    if (jobCount == 0) {
        currentJob = inputJob;
        jobCount++;
    }
}

job Processor::pop()
{
    job tempJob = currentJob;
    currentJob = {};
    jobCount--;
    return tempJob;

}

bool Processor::isEmpty()
{
    if (jobCount == 0) {
        return true;
    }
    else {
        return false;
    }
}

bool Processor::isFull()
{
    if (jobCount == 1) {
        return true;
    }
    else {
        return false;
    }
}

bool Processor::isComplete()
{
    if (currentJob.processingTime == 0) {
        return true;
    }
    else {
        return false;
    }
}

void Processor::processJobOne() {
    currentJob.processingTime--;
}


Processor::~Processor()
{
}