void operator delete[](void* ptr);

struct AptBoolean {
    static void operator delete[](void* ptr);
};

void AptBoolean::operator delete[](void* ptr)
{
    ::operator delete[](ptr);
}
