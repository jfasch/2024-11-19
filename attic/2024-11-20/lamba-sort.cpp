#include <algorithm>
#include <iostream>

int main()
{
    int numbers[] = { 666, 42, 1, 5, 13, 2 };
    bool reverse = true;

    std::sort(numbers, numbers+6, [reverse](int l, int r){
        if (reverse)
            return l>r;
        else
            return l<r;
    });

    for (int i: numbers)
        std::cout << i << std::endl;
    return 0;
}
