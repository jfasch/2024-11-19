#include <vector>
#include <iostream>

int main()
{
    std::vector<int> my_array{42, 5};
    //std::vector<int> my_array(42, 5);

    for (int i: my_array)
        std::cout << i << std::endl;

    return 0;
}
