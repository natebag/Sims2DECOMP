// FLAGS: -msdata=eabi -G 8
// 0x803273D0 EResourceManager::GetPos (56b)
extern int EResourceManager_LookupId(void* self, unsigned int id, int* pos, int* size);

int EResourceManager_GetPos(void* self, unsigned int id) {
    int pos = 0;
    int size = 0;
    EResourceManager_LookupId(self, id, &pos, &size);
    return pos;
}
