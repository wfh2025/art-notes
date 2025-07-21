#include <iostream>
#include <random>

static int gen_random() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 99);
    return dis(gen);
}

class A {
  public:
    A():m_value(gen_random()) {
        std::cout << __LINE__ << ", A(), " << "value = " << this->m_value << std::endl;
    }
    A(const A& other) {
        this->m_value = gen_random();
        std::cout << __LINE__ << ", A(const A& other), " << "value = " << this->m_value << std::endl;
    }
    ~A() {
        std::cout << __LINE__ << ", ~A(), " << "value = " << this->m_value << std::endl;
    }

  private:
    int m_value;
};


A f() {
    A tmp;
    std::cout << __LINE__ << ", func(A a) " << std::endl;
    return tmp;
}

int main() {
    std::cout << __LINE__ << ", before func(A a) " << std::endl;
    A a = f();
    std::cout << __LINE__ << ", after func(A a) " << std::endl;
    return 0;
}

// 运行结果
// 36, before func(A a) 
// 14, A(), value = 72
// 31, func(A a) 
// 38, after func(A a) 
// 21, ~A(), value = 72
// Program ended with exit code: 0
