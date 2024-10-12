#include <iostream>

// Outer template class
template <typename X>
class Outer
{
public:
    Outer() : y_{0}, inner1_{} {
        std::cout << "Outer constructor\n";
    }

    // Forward declare Inner2
    template <class Y> class Inner2;

    // Inner template class Inner1
    template <class Y>
    class Inner1 {
        // Declare Inner2 as a friend of Inner1
        friend class Outer<X>::template Inner2<Y>;
    public:
        Inner1() : x_{0} {
            std::cout << "Inner1 constructor\n";
            Inner2<Y> inner2{*this};
        }
    private:
        Y x_{0};
    };

    // Inner template class Inner2
    template <class Y>
    class Inner2 {
    public:
        Inner2(Inner1<Y>& inner1) : inner1_{inner1} {
            std::cout << "Inner2 constructor\n";
            inner1_.x_ = 1;
        }
    private:
        Inner1<Y>& inner1_;
    };
private:
    X y_;
    Inner1<X> inner1_;
};

int main() {
    Outer<int> outer{};

    return 0;
}


