#include "utils.h"

template <typename T>
auto mergesort(const std::vector<T> &vec) {
    // term cond
    if (vec.size() <= 1) {
        return vec;
    }

    // recurse
    auto mid = vec.size() / 2;
    auto v1 = std::vector<T>(vec.begin(), vec.begin() + mid);
    auto v2 = std::vector<T>(vec.begin() + mid, vec.end());
    std::copy(vec.begin(), vec.begin() + mid, v1.begin());
    std::copy(vec.begin() + mid, vec.end(), v2.begin());
    v1 = mergesort(v1);
    v2 = mergesort(v2);

    // merge
    auto ret = std::vector<T>(v1.size() + v2.size());
    auto ret_it = ret.begin();
    auto v1_it = v1.begin();
    auto v2_it = v2.begin();
    while (v1_it != v1.end() && v2_it != v2.end()) {
        if (*v1_it < *v2_it) {
            *ret_it++ = *v1_it++;
        } else {
            *ret_it++ = *v2_it++;
        }
    }

    // cleanup
    if (v1_it != v1.end()) {
        std::copy(v1_it, v1.end(), ret_it);
    } else {
        std::copy(v2_it, v2.end(), ret_it);
    }

    // done
    return ret;
}

template <typename T>
auto mergesort(const std::vector<T> &vec, const std::unordered_map<T, int> &ord) {
    // term cond
    if (vec.size() <= 1) {
        return vec;
    }

    // recurse
    auto mid = vec.size() / 2;
    auto v1 = std::vector<T>(vec.begin(), vec.begin() + mid);
    auto v2 = std::vector<T>(vec.begin() + mid, vec.end());
    std::copy(vec.begin(), vec.begin() + mid, v1.begin());
    std::copy(vec.begin() + mid, vec.end(), v2.begin());
    v1 = mergesort(v1, ord);
    v2 = mergesort(v2, ord);

    // merge
    auto ret = std::vector<T>(v1.size() + v2.size());
    auto ret_it = ret.begin();
    auto v1_it = v1.begin();
    auto v2_it = v2.begin();
    while (v1_it != v1.end() && v2_it != v2.end()) {
        if (ord.at(*v1_it) < ord.at(*v2_it)) {
            *ret_it++ = *v1_it++;
        } else {
            *ret_it++ = *v2_it++;
        }
    }

    // cleanup
    if (v1_it != v1.end()) {
        std::copy(v1_it, v1.end(), ret_it);
    } else {
        std::copy(v2_it, v2.end(), ret_it);
    }

    // done
    return ret;
}

std::vector<int> relative_sort(const std::vector<int> &arr, const std::vector<int> &ord) {
    auto ord_map = std::unordered_map<int, int>();
    for (int i = 0; i < ord.size(); ++i) {
        ord_map[ord[i]] = i;
    }

    auto in_subset = std::vector<int>();
    auto not_in_subset = std::vector<int>();
    for (const auto &i : arr) {
        if (ord_map.find(i) != ord_map.end()) {
            in_subset.push_back(i);
        } else {
            not_in_subset.push_back(i);
        }
    }
    auto in_subset_sorted = mergesort(in_subset, ord_map);
    auto not_in_subset_sorted = mergesort(not_in_subset);

    std::vector<int> ret;
    ret.reserve(in_subset_sorted.size() + not_in_subset_sorted.size());
    ret.insert(ret.end(), in_subset_sorted.begin(), in_subset_sorted.end());
    ret.insert(ret.end(), not_in_subset_sorted.begin(), not_in_subset_sorted.end());

    return ret;
}