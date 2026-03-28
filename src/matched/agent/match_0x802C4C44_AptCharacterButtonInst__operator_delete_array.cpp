void operator delete[](void* ptr);

struct AptCharacterButtonInst {
    static void operator delete[](void* ptr);
};

void AptCharacterButtonInst::operator delete[](void* ptr)
{
    ::operator delete[](ptr);
}
