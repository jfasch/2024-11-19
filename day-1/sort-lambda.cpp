#include <array>
#include <algorithm>
#include <iostream>


int main()
{
    std::array<int, 6> my_numbers = { 42, 666, 1, 7, 13, 5 };
    std::sort(my_numbers.begin(), my_numbers.end(), [](int l, int r){return l>r;});

    for (int num: my_numbers)
        std::cout << num << std::endl;

    return 0;
}
