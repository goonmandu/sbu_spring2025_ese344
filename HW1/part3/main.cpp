#include <iostream>
#include "utils.h"

int main() {
    auto vec = std::vector<int>{2,3,1,3,2,4,6,7,9,2,19};
    auto ord = std::vector<int>{2,1,4,3,9,6};
    auto sorted = relative_sort(vec, ord);

    for (const auto &i : sorted) {
        std::cout << i << " ";  // prints "2 2 2 1 4 3 3 9 6 7 19"
    }
}