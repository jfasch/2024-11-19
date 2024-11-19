#include <vector>
#include <iostream>

std::vector<int> make_einen_haufen_ints()
{
    std::vector<int> v;
    for (int i=0; i<10000; i++)
        v.push_back(i);
    return v;
}

int main()
{
    auto haufen = make_einen_haufen_ints();
    for (auto i: haufen)
        std::cout << i << std::endl;
    return 0;
}
