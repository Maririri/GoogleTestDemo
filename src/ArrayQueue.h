#pragma once

#include "Queue.h"
#include <stdexcept>

class ArrayQueue : public ::Queue {
public:
  explicit ArrayQueue(int MaxSize = 500) : cap(MaxSize), front(0), back(0) {
    data = new int[cap + 1];
  }

  ~ArrayQueue() { delete[] data; }

  void Enqueue(const int item) {
    if (size >= cap)
      shrink(2);

    data[back++] = item;
    ++size;
  }

  int Dequeue() {
    if (size == 0)
      throw std::out_of_range("ArrayQueue is empty");

    int retVal = data[front++];
    --size;

    if (size < cap / 2) {
      shrink(1.5);
    }

    return retVal;
  }

protected:
  void shrink(double times) {
    cap *= times;

    int *p = new int[cap];

    for (int i = 0; i < size; i++) {
      p[i] = data[i];
    }

    delete[] data;

    data = p;
  }

  int *data;
  int front, back;
  int cap;
};
