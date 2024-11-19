#include <memory>
#include <map>
#include <iostream>

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
    auto zwei = std::make_unique<Object>("zwei");
    Object* zwei_raw = zwei.get();

    std::map<int, std::unique_ptr<Object>> obj_repo;
    obj_repo[1] = std::make_unique<Object>("eins");
    obj_repo[2] = std::move(zwei);

    return 0;
}
