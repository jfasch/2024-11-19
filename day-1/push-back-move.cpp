#include <vector>
#include <string>

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
    Object o("blah");

    std::vector<Object> my_objects;
    my_objects.push_back(o);             // <-- push_back(const Object&)
    my_objects.push_back(std::move(o));  // <-- push_back(Object&&)
    my_objects.emplace_back("zwei");     // <-- perfect forwarding
    my_objects.push_back(Object("drei"));// <-- push_back(Object&&)

    return 0;
}
