// FloatConstantsQuickData::CreateInstance(void)
// Address: 0x800B6CA8 | Size: 40 bytes
// Pattern: Factory (alloc + init)

typedef unsigned int uint;

void* FloatConstantsQuickData_Alloc(int);
void* FloatConstantsQuickData_Init(void*);

void* FloatConstantsQuickData__CreateInstance(void) {
    void* p = FloatConstantsQuickData_Alloc(20);
    return FloatConstantsQuickData_Init(p);
}
