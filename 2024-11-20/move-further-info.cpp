#include <vector>
#include <string>

std::vector<int> /*RVO c++<11*/ mach_einen_haufen_integers()
{
    std::vector<int> v;
    for (int i=0; i<10000; i++)
        v.push_back(i);
    return v;
}

void mach_einen_haufen_integers_workaround(std::vector<int>& v)
{
    v.clear();
    for (int i=0; i<10000; i++)
        v.push_back(i);
}

std::string make_a_string(const char* s)
{
    return std::string(s);
}

int main()
{
    {
        std::vector<int> my_haufen = mach_einen_haufen_integers();
    }
    {
        std::vector<int> my_haufen;
        mach_einen_haufen_integers_workaround(my_haufen);
    }
    {
        std::vector<std::string> my_strings = { "ein string" };
        auto another_string = make_a_string("another string");
        my_strings.push_back(another_string); // <-- push_back(const std::string&)

        auto yet_another_string = make_a_string("yet another string");
        my_strings.push_back(std::move(yet_another_string)); // <-- push_back(std::string&&)

        my_strings.push_back(make_a_string("yeyeyet"));      // <-- push_back(std::string&&)

        my_strings.emplace_back("blah");
        my_strings.emplace_back(make_a_string("blah"));     // <-- string(string&&)
    }

    return 0;
}
