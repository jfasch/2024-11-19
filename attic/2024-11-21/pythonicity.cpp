#include <vector>
#include <iostream>

struct point
{
    int x, y;
};

int main()
{
    int array[] = { 1, 2, 3, 4 };
    for (int i: array)
        std::cout << i << std::endl;

    auto& [e0, e1, e2, e3] = array;
    e0 = 5;
    for (int i: array)
        std::cout << i << std::endl;

    point p = {1, 2};
    auto [a, b] = p;

    // const std::vector<int> v = {1, 2, 3};
    // auto [f0, f1, f2] = v;

    return 0;    
}
