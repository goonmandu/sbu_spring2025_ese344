#pragma once

#include <vector>
#include <unordered_map>

template <typename T>
auto mergesort(const std::vector<T> &vec);

template <typename T>
auto mergesort(const std::vector<T> &vec, const std::unordered_map<T, int> &ord);

std::vector<int> relative_sort(const std::vector<int> &arr, const std::vector<int> &ord);
