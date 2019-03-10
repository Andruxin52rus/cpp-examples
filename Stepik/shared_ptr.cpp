#include <map>
#include <cassert>
#include <iostream>

struct Expression {
    int x;
};

struct SharedPtr
{
    private:
        Expression* m_ptr;
        unsigned* m_count;
    public:
        explicit SharedPtr(Expression* ptr = 0) : m_ptr (ptr), m_count(new unsigned{1}) {}
        ~SharedPtr() {
            if (--*m_count == 0) {
                delete m_count;
                delete m_ptr;
            }
        }
        SharedPtr(const SharedPtr& other) : m_ptr(other.m_ptr), m_count(other.m_count) {
            ++*m_count;
        }
        SharedPtr& operator=(const SharedPtr& other) {
            if (this != &other) {
                if (--*m_count == 0) {
                    delete m_count;
                    delete m_ptr;
                }

                m_ptr = other.m_ptr;
                m_count = other.m_count;
                ++*m_count;
            }
            return *this;
        }
        Expression* get() const {
            return m_ptr;
        }
        void reset(Expression *ptr = 0) {
            if (--*m_count == 0) {
                delete m_count;
                delete m_ptr;
            }
            m_ptr = ptr;
            m_count = new unsigned{1};
        }
        Expression& operator*() const {
            return *m_ptr;
        }
        Expression* operator->() const {
            return m_ptr;
        }
};

int main() {
    SharedPtr p {new Expression()};
    SharedPtr sp = p;
    system("pause");
}
