typedef unsigned int size_t;

void* operator new[](size_t size);

struct AptFloat {
    static void* operator new[](size_t size);
};

void* AptFloat::operator new[](size_t size)
{
    return ::operator new[](size);
}
