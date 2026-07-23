#include <iostream>
template <typename T, typename U>
class Pair
{
private:
    T value1;
    U value2;

public:
    Pair(T value1, U value2) : value1(value1), value2(value2) {};
    T getValue1() const { return value1; }
    U getValue2() const { return value2; }
    void setValue1(T value) { this->value1 = value; }
    void setValue2(U value) { this->value2 = value; }
};

int main()
{
    Pair onePair(3, "hallo");

    std::cout << onePair.getValue1() << std::endl;
    std::cout << onePair.getValue2() << std::endl;
}