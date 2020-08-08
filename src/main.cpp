#include "circbuf.cpp"

using namespace circular_buffer;

// explicitly telling the compiler to instansiate cicrbuf<int>
// this is *not* acting lazy and will instansiate all member functions
// in order to let the compiler see circbuf member functions
// definition we are including circbuf.cpp
template class circbuf<int>;

int main(int argc, char *argv[])
{
    circbuf<int> c(4);

    c.show();
    c.put(1);
    c.show();
    c.put(2);
    c.show();
    c.put(3);
    c.show();
    c.put(4);
    c.show();
    try
    {
        c.put(5);
        c.show();
    }
    catch (const std::exception &e)
    {
        std::cout << "exception:" << e.what() << std::endl;
    }

    std::cout << "got:" << c.get() << std::endl;
    c.show();
    std::cout << "got:" << c.get() << std::endl;
    c.show();
    std::cout << "got:" << c.get() << std::endl;
    c.show();
}