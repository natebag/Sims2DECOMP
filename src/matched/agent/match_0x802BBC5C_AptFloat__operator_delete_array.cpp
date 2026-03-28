void operator delete[](void* ptr);

struct AptFloat {
    static void operator delete[](void* ptr);
};

void AptFloat::operator delete[](void* ptr)
{
    ::operator delete[](ptr);
}
