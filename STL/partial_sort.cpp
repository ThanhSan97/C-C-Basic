#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {8, 4, 9, 2, 1, 7, 2};

    std::partial_sort(v.begin(), v.begin() + 4, v.end());

    std::cout << "Partially sorted vector: ";
    for (int num : v) {
        std::cout << num << " ";
    }
    return 0;
}
