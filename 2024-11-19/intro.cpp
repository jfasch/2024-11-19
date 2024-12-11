#include <map>
#include <string>
#include <iostream>
#include <functional>


int main()
{
    using todo_list = std::map<std::string, std::function<void()>>;

    const todo_list tdl = {
        {
            "up 1 to 10",
            [prefix="blah"]() -> void {
                for (int i=1; i<=10; i++)
                    std::cout << prefix << ", UP: " << i << std::endl;
            }
        },
        {
            "down 1000 to 980",
            []() -> void {
                for (int i=1000; i>=980; i--)
                    std::cout << "DOWN: " << i << std::endl;
            }
        },
    };

    for (const auto& [name, item]: tdl) {
        std::cout << "NAME: " << name << '\n';
        item();
        std::cout << '\n';
    }

    return 0;
}
