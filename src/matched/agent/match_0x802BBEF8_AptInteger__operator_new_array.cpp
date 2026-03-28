typedef unsigned int size_t;

void* operator new[](size_t size);

struct AptInteger {
    static void* operator new[](size_t size);
};

void* AptInteger::operator new[](size_t size)
{
    return ::operator new[](size);
}
