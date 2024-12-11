#include <vector>
#include <iostream>

std::vector<int> /*RVO*/ mach_einen_haufen_ints()
{
    std::vector<int> v;
    for (int i=0; i<10000; i++)
        v.push_back(i);
    return v;   // <-- move! 
}

void mach_einen_haufen_ints_no_rvo_dirty_workaround_NO(std::vector<int>& v)
{
    v.clear();
    for (int i=0; i<10000; i++)
        v.push_back(i);
}

int main()
{
    {
        std::vector<int> my_haufen = mach_einen_haufen_ints();
        // ...
    }
    {
        std::vector<std::string> my_strings;
        std::string s1("blah");
        my_strings.push_back(s1);                       // <-- push_back(const T&)
        my_strings.push_back(std::move(s1));            // <-- push_back(T&&)
        my_strings.push_back(std::string("blech"));     // <-- push_back(T&&)
        my_strings.push_back("blech");                  // <-- push_back(T&&)
        my_strings.emplace_back("blech");               // <-- perfect forwarding
    }
    return 0;
}
