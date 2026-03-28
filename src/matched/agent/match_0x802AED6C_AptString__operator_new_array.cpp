typedef unsigned int size_t;

void* operator new[](size_t size);

struct AptString {
    static void* operator new[](size_t size);
};

void* AptString::operator new[](size_t size)
{
    return ::operator new[](size);
}
