#ifndef SAFE_LOCK_H
#define SAFE_LOCK_H

#include <mutex>
#include <iostream>

// RAII style mutex wrapper
class safe_lock
{

public:
    safe_lock(std::mutex &m)
        : m_mutex{&m}
    {
        if (!m_mutex->try_lock())
        {
            throw std::runtime_error("failed aquiring lock");
        }
    }
    ~safe_lock()
    {
        m_mutex->unlock();
    }

private:
    std::mutex *m_mutex; // mutex cannot be copied or moved
};

#endif // SAFE_LOCK_H
