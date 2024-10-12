#include <iostream>

// Forward declare Inner1
template <typename X, class Y> class Inner1;

// Inner2 is now a separate template class
template <typename X, class Y>
class Inner2 {
public:
    Inner2(Inner1<X, Y>& inner1) {
        std::cout << "Inner2 constructor\n";
        inner1.x_ = 1;
    }
};

// Inner1 now includes Inner2 as a friend, with complete definition
template <typename X, class Y>
class Inner1 {
    friend class Inner2<X, Y>;
public:
    Inner1() : x_{0} {
        std::cout << "Inner1 constructor\n";
        Inner2<X, Y> inner2{*this};
    }

private:
    Y x_{0};
};

// Outer template class
template <typename X>
class Outer {
public:
    Outer() : y_{0}, inner1_{} {
        std::cout << "Outer constructor\n";
    }
private:
    X y_;
    Inner1<X, X> inner1_;
};

int main() {
    Outer<int> outer{};

    return 0;
}
