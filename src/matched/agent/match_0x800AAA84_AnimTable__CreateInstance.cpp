// AnimTable::CreateInstance(void)
// Address: 0x800AAA84 | Size: 40 bytes
// Pattern: Factory (alloc + init)

typedef unsigned int uint;

void* AnimTable_Alloc(int);
void* AnimTable_Init(void*);

void* AnimTable__CreateInstance(void) {
    void* p = AnimTable_Alloc(8);
    return AnimTable_Init(p);
}
