#include <map>
#include <string>
#include <iostream>


int main()
{
    std::map<int, std::string> my_map;
    my_map[42] = "zweiundvierzig";

    std::cout << ':' << my_map[42] << ':' << std::endl;
    std::cout << ':' << my_map[666] << ':' << std::endl;

    return 0;
}
