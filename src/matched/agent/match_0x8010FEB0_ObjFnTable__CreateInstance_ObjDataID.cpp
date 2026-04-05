// ObjFnTable::CreateInstance(ObjectDataID &)
// Address: 0x8010FEB0 | Size: 40 bytes
// Pattern: Factory (alloc + init)

typedef unsigned int uint;

void* ObjFnTable_Alloc(int);
void* ObjFnTable_Init(void*);

void* ObjFnTable__CreateInstance_ObjDataID(void* id) {
    void* p = ObjFnTable_Alloc(24);
    return ObjFnTable_Init(p);
}
