// EBinaryManager::AllocateAndLoadResource - 0x803230C4 (92 bytes)
// TU: e_binaryman
// Pattern B: Uses EResourceManager::Alloc, size ~48 bytes

extern void* EResourceManager_Alloc(void* mgr, unsigned long size, unsigned int group);
extern void ERBinary_ctor(void* self);
extern void ERBinary_Load(void* self, void* file);

void* EBinaryManager_AllocateAndLoadResource(void* this_ptr, void* file, unsigned int typeId, unsigned int resourceId) {
    void* mgr = (void*)0x805E94EC;  // From lis/addi
    void* mem = EResourceManager_Alloc(mgr, 48, 8);
    ERBinary_ctor(mem);
    ((unsigned int*)mem)[2] = resourceId;  // offset 8
    ERBinary_Load(mem, file);
    return mem;
}
