// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>

template<typename T>
class TPQueue {
    private 
    T *arr;
    int size;
    int begin, end;
    int count;
 public:
    T pop();
    T get() const;
    bool isFull() const;
    bool isEmpty() const;

void push(const T & item) {
    assert(count < size);
        if (end != 0) {
        arr[end] = item;
                for (int i = end - 1; i >= begin; i--) {
                if (arr[i].prior < item.prior) {
                        arr[i] = item;
                        arr[i + 1] = arr[i];
                }
                }
        } else {
                arr[begin] = item;
        }

T pop() {
    assert(count > 0);
    T item = arr[begin++];
    count--;
    if (begin > size)
        begin -= size + 1;
    return item;
}

T get() const {
    assert(count > 0);
    return arr[begin];
}

bool isEmpty() const {
  return count == 0;
}

bool isFull() const {
  return count == size;
}

struct SYM {
  char ch;
  int  prior;
};

#endif // INCLUDE_TPQUEUE_H_
