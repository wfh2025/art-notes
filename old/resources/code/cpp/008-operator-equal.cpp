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
    
    A& operator=(A & other) {
        std::cout << __LINE__ << ", A& operator=(A & other)  " << std::endl;
        this->m_value = gen_random();
        return *this;
    }

  private:
    int m_value;
};


int main() {
    A a1;
    A a2;
    a2 = a1;
    return 0;
}

// 运行结果
// 14, A(), value = 85
// 14, A(), value = 8
// 25, A& operator=(A & other)  
// 21, ~A(), value = 85
// 21, ~A(), value = 85
// Program ended with exit code: 0