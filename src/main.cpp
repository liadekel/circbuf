#include "circbuf.cpp"

using namespace circular_buffer;

// explicitly telling the compiler to instansiate cicrbuf<int>
// this is *not* acting lazy and will instansiate all member functions
// in order to let the compiler see circbuf member functions
// definition we are including circbuf.cpp
template class circbuf<int>;

int main(int argc, char *argv[])
{
    circbuf<int> c = circbuf<int>(0);
    c.show();
}