// House::CreateInstance(void)
// Address: 0x800BB358 | Size: 40 bytes
// Pattern: Factory (alloc + init)

typedef unsigned int uint;

void* House_Alloc(int);
void* House_Init(void*);

void* House__CreateInstance(void) {
    void* p = House_Alloc(36);
    return House_Init(p);
}
