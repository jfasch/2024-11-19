#include <map>
#include <string>
#include <iostream>

int main()
{
    std::map<int, std::string> my_map;

    my_map[1] = "eins";
    my_map[2] = "zwei";

    std::cout << ':' << my_map[1] << ':' << std::endl;
    std::cout << ':' << my_map[2] << ':' << std::endl;
    std::cout << ':' << my_map[3] << ':' << std::endl;

    return 0;
}
