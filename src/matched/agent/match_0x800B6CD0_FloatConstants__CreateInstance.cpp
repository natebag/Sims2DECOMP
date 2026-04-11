// FloatConstants::CreateInstance(void)
// Address: 0x800B6CD0 | Size: 40 bytes
// Pattern: Factory (alloc + init)

typedef unsigned int uint;

void* FloatConstants_Alloc(int);
void* FloatConstants_Init(void*);

void* FloatConstants__CreateInstance(void) {
    void* p = FloatConstants_Alloc(20);
    return FloatConstants_Init(p);
}
