#include <memory>
#include <string>
#include <iostream>

class Object
{
public:
    Object(const std::string& tag) : _tag(tag) 
    {
        std::cout << __PRETTY_FUNCTION__ << ": " << _tag << std::endl;
    }

    ~Object()
    {
        std::cout << __PRETTY_FUNCTION__ << ": " << _tag << std::endl;
    }

    void doit() const
    {
        std::cout << __PRETTY_FUNCTION__ << ": " << _tag << std::endl;
    }

private:
    std::string _tag;
};

int main()
{
    {
        auto orig = std::make_unique<Object>("ein objekt");

        auto copy(std::move(orig));
        copy->doit();

        //orig->doit(); // <-- NO!
    }
    {
        auto obj = std::make_unique<Object>("ein objekt");
        obj = std::make_unique<Object>("another objekt");
    }

    return 0;
}
