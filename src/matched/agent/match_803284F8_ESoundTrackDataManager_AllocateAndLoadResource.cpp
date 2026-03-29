// ESoundTrackDataManager::AllocateAndLoadResource - 0x803284F8 (84 bytes)
// TU: e_soundtrackdataman
// Pattern B: Uses EResourceManager::Alloc, size ~56 bytes

extern void* EResourceManager_Alloc(void* mgr, unsigned long size, unsigned int group);
extern void ERSoundTrackData_ctor(void* self);
extern void ERSoundTrackData_Load(void* self, void* file);

void* ESoundTrackDataManager_AllocateAndLoadResource(void* this_ptr, void* file, unsigned int typeId, unsigned int resourceId) {
    void* mgr = (void*)0x805EC318;  // From lis/addi
    void* mem = EResourceManager_Alloc(mgr, 56, 8);
    ERSoundTrackData_ctor(mem);
    ((unsigned int*)mem)[2] = resourceId;  // offset 8
    ERSoundTrackData_Load(mem, file);
    return mem;
}
