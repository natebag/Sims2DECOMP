void operator delete[](void* ptr);

struct AptString {
    static void operator delete[](void* ptr);
};

void AptString::operator delete[](void* ptr)
{
    ::operator delete[](ptr);
}
