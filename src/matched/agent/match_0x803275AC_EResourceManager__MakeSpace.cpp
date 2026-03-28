/* EResourceManager::MakeSpace at 0x803275AC (72 bytes) */

typedef unsigned int u32;

u32 CheckAvailSpace(void* list);
u32 ReleaseSpace(void* list, int mode);

u32 EResourceManager_MakeSpace(void* self)
{
    void* list = (void*)((char*)self + 88);
    u32 result = CheckAvailSpace(list);
    if (result == 0) {
        return 0;
    }
    return ReleaseSpace(list, 3);
}
