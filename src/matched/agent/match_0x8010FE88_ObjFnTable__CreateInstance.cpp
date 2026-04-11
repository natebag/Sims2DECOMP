// ObjFnTable::CreateInstance(void)
// Address: 0x8010FE88 | Size: 40 bytes
// Pattern: Factory (alloc + init)

typedef unsigned int uint;

void* ObjFnTable_Alloc(int);
void* ObjFnTable_Init(void*);

void* ObjFnTable__CreateInstance(void) {
    void* p = ObjFnTable_Alloc(24);
    return ObjFnTable_Init(p);
}
