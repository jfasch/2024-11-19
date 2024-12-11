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
    {
        auto orig = std::make_unique<Object>("blah", 42);
        auto copy = std::move(orig);
        copy->doit();
        // orig->doit(); // NO!
    }

    return 0;
}
