// 0x802E37D4 EEngine::GetDMARingMemoryUseInfo (36b)
// FLAGS: -fno-schedule-insns

extern char gDMARingName[];

struct HeapUseInfo {
    char *name;
    int used;
    int peak;
    int size;
    int flags;
};

void EEngine__GetDMARingMemoryUseInfo(void *self, HeapUseInfo *info) {
    info->flags = 0;
    info->name = gDMARingName;
    info->used = 0;
    info->peak = 0;
    info->size = 0;
}
