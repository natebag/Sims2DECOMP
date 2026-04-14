// 0x802E37F8 EEngine::GetTextureRingMemoryUseInfo (36b)
// FLAGS: -fno-schedule-insns

extern char gTextureRingName[];

struct HeapUseInfo {
    char *name;
    int used;
    int peak;
    int size;
    int flags;
};

void EEngine__GetTextureRingMemoryUseInfo(void *self, HeapUseInfo *info) {
    info->flags = 0;
    info->name = gTextureRingName;
    info->used = 0;
    info->peak = 0;
    info->size = 0;
}
