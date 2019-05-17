#pragma once

#include <cstddef>
#include <stdexcept>

class Queue {
public:
  virtual ~Queue() {}

  virtual void Enqueue(const int) = 0;

  virtual int Dequeue() = 0;

  virtual size_t Size() const { return size; }

protected:
  size_t size = 0;
};