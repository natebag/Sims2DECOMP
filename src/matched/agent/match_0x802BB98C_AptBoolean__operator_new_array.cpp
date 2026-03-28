typedef unsigned int size_t;

void* operator new[](size_t size);

struct AptBoolean {
    static void* operator new[](size_t size);
};

void* AptBoolean::operator new[](size_t size)
{
    return ::operator new[](size);
}
