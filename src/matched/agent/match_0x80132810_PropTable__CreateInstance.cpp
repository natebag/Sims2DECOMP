// PropTable::CreateInstance(void)
// Address: 0x80132810 | Size: 40 bytes
// Pattern: Factory (alloc + init)

typedef unsigned int uint;

void* PropTable_Alloc(int);
void* PropTable_Init(void*);

void* PropTable__CreateInstance(void) {
    void* p = PropTable_Alloc(8);
    return PropTable_Init(p);
}
