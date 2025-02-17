#pragma once

#include <vector>

template <typename T>
class Heap<T> {
    private:
        std::vector<T> vec;
        int size;
        int left(const Heap<T> &heap);
        int right(const Heap<T> &heap);
        int parent(const Heap<T> &heap);

    public:
        Heap(int size);
        void max_heapify(T t);
        Heap<T> build_max_heap(T arr[]);
        void heapsort();
};