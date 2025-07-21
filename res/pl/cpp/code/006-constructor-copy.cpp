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


void f(A a) {
    std::cout << __LINE__ << ", func(A a) " << std::endl;
}

int main() {
    A a1;
    f(a1);
    return 0;
}


// 运行结果
// 14, A(), value = 77
// 18, A(const A& other), value = 91
// 30, func(A a) 
// 21, ~A(), value = 91
// 21, ~A(), value = 77
// Program ended with exit code: 0