typedef unsigned int size_t;

void* operator new[](size_t size);

struct AptCharacterButtonInst {
    static void* operator new[](size_t size);
};

void* AptCharacterButtonInst::operator new[](size_t size)
{
    return ::operator new[](size);
}
