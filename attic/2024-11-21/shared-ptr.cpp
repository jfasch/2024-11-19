#include <string>
#include <memory>
#include <iostream>

class Object
{
public:
    Object(const std::string& tag, int id) : _tag(tag), _id(id) {}
    ~Object()
    {
        std::cout << __PRETTY_FUNCTION__ << ':' << _tag << std::endl;
    }

    void doit() const
    {
        std::cout << __PRETTY_FUNCTION__ << ':' << _tag << std::endl;
    }

private:
    std::string _tag;
    int _id;
};


int main()
{
    auto orig = std::make_shared<Object>("blah", 42); // perfect forwarding
    std::cout << orig.use_count() << std::endl;
    std::cout << orig.get() << std::endl;

    auto copy = orig;
    std::cout << copy.use_count() << std::endl;
    std::cout << copy.get() << std::endl;

    return 0;
}
