void operator delete[](void* ptr);

struct AptInteger {
    static void operator delete[](void* ptr);
};

void AptInteger::operator delete[](void* ptr)
{
    ::operator delete[](ptr);
}
