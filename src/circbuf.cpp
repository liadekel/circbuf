#include "circbuf/circbuf.hpp"

using namespace circular_buffer;

template <typename T>
circbuf<T>::circbuf(size_t size) : m_size{size}
{
    std::cout << "Initialized circbuf!";
    std::cout << " size=" << m_size << '\n';
}

template <typename T>
void circbuf<T>::show()
{
    std::cout << "Showing circbuf" << '\n';
}

template <typename T>
circbuf<T>::~circbuf()
{
    std::cout << "Destroyed circbuf!" << '\n';
}
