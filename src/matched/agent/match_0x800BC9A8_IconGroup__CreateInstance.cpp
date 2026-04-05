// IconGroup::CreateInstance(void)
// Address: 0x800BC9A8 | Size: 40 bytes
// Pattern: Factory (alloc + init)

typedef unsigned int uint;

void* IconGroup_Alloc(int);
void* IconGroup_Init(void*);

void* IconGroup__CreateInstance(void) {
    void* p = IconGroup_Alloc(16);
    return IconGroup_Init(p);
}
