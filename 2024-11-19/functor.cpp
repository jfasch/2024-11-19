#include <iostream>

class Functor
{
public:
    Functor(int foo) : _foo(foo) {}
    void operator()(double bar) const
    {
        std::cout << "jessas, aufgerufen: " << _foo << ',' << bar << std::endl;
    }
private:
    int _foo;
};

int main()
{
    Functor bar(42);
    bar(42.666);
    return 0;
}
