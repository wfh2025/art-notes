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
    ~A() {
        std::cout << __LINE__ << ", ~A()" << "value = " << this->m_value << std::endl;
    }

  private:
    int m_value;
};

int main() {
    // Empty parentheses interpreted as a function declaration
    // 1. 编译器解析成函数声明，
    // 2. 没有调用构造函数
    // 3. 编译器会告警：Empty parentheses interpreted as a function declaration
    // 4. 效果等于什么都没做
    A a();
    return 0;
}