#include "circbuf/circbuf.hpp"

using namespace circular_buffer;

template <typename T>
circbuf<T>::circbuf(size_t size)
    : m_size{size}, m_elements{new T[size]},
      m_head{0}, m_tail{0}, m_size_curr{0}
{
    std::cout << "Initialized circbuf!";
    std::cout << " size=" << size << std::endl;
}

template <typename T>
T circbuf<T>::get()
{
    if (!empty())
    {
        // since buf is not empty, we read
        // the item in m_head place
        T elem = m_elements[m_head];
        m_head = (m_head + 1) % m_size;
        m_size_curr--;
        return elem;
    }
    else
    {
        throw std::range_error("empty buffer");
    }
}

template <typename T>
void circbuf<T>::put(T item)
{
    if (!full())
    {
        // since buf is not full, we put
        // the item in m_tail place
        m_elements[m_tail] = item;
        m_tail = (m_tail + 1) % m_size;
        m_size_curr++;
    }
    else
    {
        throw std::range_error("full buffer");
    }
}

template <typename T>
void circbuf<T>::show()
{
    std::cout << "circbuf: [ ";
    for (int i = 0; i < m_size; i++)
    {
        std::cout << m_elements[i];
        if (i == m_head) // mark head
            std::cout << "^";
        if (i == m_tail) // mark tail
            std::cout << "*";
        std::cout << " ";
    }
    std::cout << "]" << std::endl;
    std::cout << "m_head:" << m_head << std::endl;
    std::cout << "m_tail:" << m_tail << std::endl;
    std::cout << "m_size_curr:" << m_size_curr << std::endl;
    std::cout << std::endl;
}

template <typename T>
bool circbuf<T>::full()
{
    return m_head == m_tail && m_size_curr == m_size;
}

template <typename T>
bool circbuf<T>::empty()
{
    return m_head == m_tail && m_size_curr == 0;
}

template <typename T>
circbuf<T>::~circbuf()
{
    delete[] m_elements;
    std::cout << "Destroyed circbuf!" << std::endl;
}
