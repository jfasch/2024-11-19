struct point
{
    int x, y, z;
};

int main()
{
    point p = {1,2,3};
    auto [x,y,_] = p;
    return 0;
}
