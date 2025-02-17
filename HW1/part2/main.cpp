#include <iostream>
#include <vector>
#include <cmath>

template <typename T>
auto helper_inversions(const std::vector<T> &vec, int &accumulated_inversions) {
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
    auto v1_inversions = helper_inversions(v1, accumulated_inversions);
    auto v2_inversions = helper_inversions(v2, accumulated_inversions);

    // merge
    auto ret = std::vector<T>(v1.size() + v2.size());
    auto ret_it = ret.begin();
    auto v1_it = v1.begin();
    auto v2_it = v2.begin();
    while (v1_it != v1.end() && v2_it != v2.end()) {
        if (*v1_it <= *v2_it) {
            *ret_it++ = *v1_it++;
        } else {
            *ret_it++ = *v2_it++;
            accumulated_inversions += std::distance(v1_it, v1.end());
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
auto inversions(const std::vector<T> &vec) {
    int ret = 0;
    helper_inversions(vec, ret);
    return ret;
}

int main() {
    auto vec = std::vector<int>{4,3,2,1};
    auto invs = inversions(vec);
    std::cout << invs << "\n";
    return 0;
}