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
    // in an ideal world, one would not use new and an explcit
    // shared_ptr ctor, but rather ...

    // std::make_shared<>

    Object* o_ein = new Object("ein objekt");
    Object* o_nochein = new Object("noch ein objekt");

    std::shared_ptr<Object> o_ein_ptr(o_ein);

    auto copy_ein = o_ein_ptr;
    o_ein_ptr->doit();
    copy_ein->doit();

    // char c;
    // std::cin >> c;

    o_ein_ptr.reset(o_nochein);
    o_ein_ptr->doit();
    copy_ein->doit();

    // double free
    // o_ein_ptr.reset(o_ein);
    // copy_ein.reset(o_ein);

    return 0;
}
