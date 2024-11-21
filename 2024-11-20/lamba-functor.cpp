#include <string>
#include <iostream>

class Functor
{
public:
    Functor(const std::string& prefix) : _prefix(prefix) {}
    void operator()(double arg) const
    {
        std::cout << _prefix << ": being called with double argument " << arg << "\n";
    }

private:
    std::string _prefix;
};


int main()
{
    // Functor foo("foo");
    auto foo = [prefix="foo"](double arg){
        std::cout << prefix << ": being called with double argument " << arg << "\n";
    };

    foo(42.666);
    return 0;
}
