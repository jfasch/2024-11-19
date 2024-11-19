#include <map>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <memory>
#include <functional>
#include <variant>

using namespace std::chrono_literals;


int main()
{
    using tdl_value = 
        std::variant<
            std::function<void()>,
            std::shared_ptr<std::thread>
        >;

    using todo_list = std::map<std::string, tdl_value>;

    todo_list tdl = {
        {"up 1 to 10",
         [prefix="blah"]() {
             for (int i=1; i<=10; i++) {
                 std::cout << prefix << " UP " << i << '\n';
                 std::this_thread::sleep_for(1s);
             }
         }
        },
        {"down 1000 to 980",
         [prefix="blech"]() {
             for (int i=1000; i>=980; i--) {
                 std::cout << prefix << " DOWN " << i << '\n';
                 std::this_thread::sleep_for(0.5s);
             }
         }
        },
    };

    // create threads for each item
    for (auto& [_, item]: tdl)
        item = std::make_shared<std::thread>(std::get<0>(item));

    // wait for termination
    for (auto& [_, item]: tdl)
        std::get<1>(item)->join();

    return 0;
}
