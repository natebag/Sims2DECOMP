// ObjFnTableQuickData::CreateInstance(void)
// Address: 0x8010FE60 | Size: 40 bytes
// Pattern: Factory (alloc + init)

typedef unsigned int uint;

void* ObjFnTableQuickData_Alloc(int);
void* ObjFnTableQuickData_Init(void*);

void* ObjFnTableQuickData__CreateInstance(void) {
    void* p = ObjFnTableQuickData_Alloc(24);
    return ObjFnTableQuickData_Init(p);
}
