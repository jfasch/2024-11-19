#include <future>
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> my_numbers = { 42, 666, 1, 7, 13, 5 };

    auto future_result_descending = std::async(
        [arr=my_numbers]() mutable {
            std::sort(arr.begin(), arr.end(), [](int l, int r){return l>r;});
            return arr;
        }
    );
    auto future_result_ascending = std::async(
        [my_numbers]() mutable {
            std::sort(my_numbers.begin(), my_numbers.end());
            return my_numbers;
        }
    );

    for (int i: future_result_descending.get())
        std::cout << i << std::endl;
    for (int i: future_result_ascending.get())
        std::cout << i << std::endl;

    return 0;
}
