// ECharacterManager::AllocateAndLoadResource - 0x80323224 (108 bytes)
// TU: e_characterman
// Pattern B: Uses EResourceManager::Alloc, size ~64 bytes

extern void* EResourceManager_Alloc(void* mgr, unsigned long size, unsigned int group);
extern void ERCharacter_ctor(void* self);
extern void ERCharacter_Load(void* self, void* file);

void* ECharacterManager_AllocateAndLoadResource(void* this_ptr, void* file, unsigned int typeId, unsigned int resourceId) {
    void* mgr = (void*)0x805E964C;  // From lis/addi
    void* mem = EResourceManager_Alloc(mgr, 64, 8);
    ERCharacter_ctor(mem);
    ((unsigned int*)mem)[2] = resourceId;  // offset 8
    ERCharacter_Load(mem, file);
    return mem;
}
