#ifndef CIRCBUF_H
#define CIRCBUF_H

#include <mutex>
#include <iostream>

namespace circular_buffer
{
    template <typename T>
    class circbuf
    {
    public:
        explicit circbuf(std::size_t size);

        /*
         * get the next item from the buffer.
         *
         * @return the next element in the buffer if not empty , will throw exception in case empty.
         */
        T get();

        /*
         * put the given item as last in the buffer.
         *
         * @param item - item of type T to put.
         * @return void.
         */
        void put(T item);

        /*
         * put the given data buffer as last in the buffer.
         *
         * @param items - items of type T to write into the buffer.
         * @return void.
         */
        std::size_t write(T *items, std::size_t n);

        /*
         * put the given item as last in the buffer.
         *
         * @param item - item of type T to put.
         * @return void.
         */
        std::size_t read(T *items, std::size_t n);

        /*
         * print the current state of the buffer.
         *
         * @return void.
         */
        void show(); // print nicely the current state

        /*
         * check whether the buffer is full.
         *
         * @return bool indicating if the buffer is full (len 0).
         */
        bool full();
        /*
         * check whether the buffer is empty.
         *
         * @return bool indicating if the buffer is empty (len 0).
         */
        bool empty();
        /*
         * get the current size of the buffer.
         *
         * @return sum of `values`, or 0.0 if `values` is empty.
         */
        std::size_t size(); // print nicely the current state

        ~circbuf();

    private:
        T *m_elements;
        std::mutex m_mutex;
        std::size_t m_size;
        std::size_t m_head; // size indicating the place of the first item
        std::size_t m_tail; // size indicating the place of the last item
        std::size_t m_size_curr;
    };

} // namespace circular_buffer
#endif // CIRCBUF_H
