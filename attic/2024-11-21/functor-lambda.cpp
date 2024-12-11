#include <algorithm>
#include <iostream>

int foo(double d)
{
    return d;
}

class Functor
{
public:
    Functor(int offset) : _offset(offset) {}
    int operator()(double d)
    {
        return _offset + d;
    }
private:
    int _offset;
};

int main()
{
    std::cout << foo(42.666) << std::endl;

    Functor bar(2);
    std::cout << bar(42.666) << std::endl;

    Functor baz(666);
    std::cout << baz(42.666) << std::endl;

    auto foobar = [offset=42](double d) -> int {
        return offset+d;
    };

    std::cout << foobar(666.42) << std::endl;

    int mein_offset = 42;
    auto another_foobar = [&](double d) -> int {
        return mein_offset+d;
    };

    std::cout << another_foobar(23456.8765432) << std::endl;

    mein_offset = 666;
    std::cout << another_foobar(23456.8765432) << std::endl;

    std::cout << "sorting" << std::endl;
    int array[] = { 3, 42, 666, 1, 5 };
    std::sort(array, array+5, [](int l, int r){return l>r;});
    for (int i: array)
        std::cout << i << std::endl;
    
    return 0;
}
