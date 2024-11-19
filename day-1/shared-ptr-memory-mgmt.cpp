#include <memory>
#include <map>
#include <iostream>

class Object
{
public:
    Object(const std::string& msg) : _msg(msg) {}
    const std::string& msg() const { return _msg; }

private:
    std::string _msg;
};

int main()
{
    std::map<int, std::shared_ptr<Object>> my_objects;

    {
        auto eins = std::make_shared<Object>("eins");
        auto zwei = std::make_shared<Object>("zwei");

        // std::shared_ptr<Object> eins(new Object("eins"));
        // std::shared_ptr<Object> zwei(new Object("zwei"));

        my_objects[1] = eins;
        my_objects[2] = zwei;
    }

    std::cout << my_objects[1]->msg() << std::endl;
//    std::cout << eins->msg() << std::endl;
    
    return 0;
}
