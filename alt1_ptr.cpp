#include <iostream>

// Outer template class
template <typename X>
class Outer
{
public:
    Outer() : y_{0}, inner1_{} {
        std::cout << "Outer constructor\n";
    }

    template <class Y>
    class Inner1 {
        // Remove friend declaration
    public:
        Inner1() : x_{0} {
            std::cout << "Inner1 constructor\n";
            Inner2<Y>* inner2 = new Inner2<Y>(this); // Use pointer
        }

        // Provide an interface for Inner2
        void setX(const Y& value) {
            x_ = value;
        }

    private:
        Y x_{0};
    };

    // Inner template class Inner2
    template <class Y>
    class Inner2 {
    public:
        Inner2(Inner1<Y>* inner1) : inner1_{inner1} {
            std::cout << "Inner2 constructor\n";
            inner1_->setX(1); // Use public method
        }
    private:
        Inner1<Y>* inner1_;
    };

private:
    X y_;
    Inner1<X> inner1_;
};

int main() {
    Outer<int> outer{};

    return 0;
}


