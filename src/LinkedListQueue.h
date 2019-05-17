#pragma once

#include "Queue.h"
#include <stddef.h>

class QueueNode {
  friend class LinkedListQueue;

public:
  const int element() const { return element_; }

  QueueNode *next() { return next_; }

  const QueueNode *next() const { return next_; }

private:
  explicit QueueNode(const int an_element)
      : element_(an_element), next_(NULL) {}

  int element_;
  QueueNode *next_;
};

class LinkedListQueue : public Queue {
public:
  LinkedListQueue()
      : head_(NULL), last_(NULL) /*,
                      size(0)*/
  {}

  ~LinkedListQueue() {
    if (size > 0) {
      QueueNode *node = head_;
      QueueNode *next = node->next();
      for (;;) {
        delete node;
        node = next;
        if (node == NULL)
          break;
        next = node->next();
      }

      head_ = last_ = NULL;
      size = 0;
    }
  }

  void Enqueue(const int element) {
    QueueNode *new_node = new QueueNode(element);

    if (size == 0) {
      head_ = last_ = new_node;
      size = 1;
    } else {
      last_->next_ = new_node;
      last_ = new_node;
      size++;
    }
  }

  int Dequeue() {
    if (size == 0) {
      throw std::out_of_range("MyQueue is empty");
    }

    const QueueNode *const old_head = head_;
    head_ = head_->next_;
    size--;
    if (size == 0) {
      last_ = NULL;
    }

    int element = old_head->element();
    delete old_head;

    return element;
  }

  //    size_t Size() const { return size; }

private:
  QueueNode *head_;
  QueueNode *last_;
  //    size_t size;
};
