// 0x802E3868 EEngine::GetMemoryUseDmaInfo (40b)
// FLAGS: -fno-schedule-insns

extern char gDMAMemoryName[];

struct HeapUseInfo {
    char *name;
    int used;
    int peak;
    int size;
    int flags;
};

void EEngine__GetMemoryUseDmaInfo(void *self, HeapUseInfo *info) {
    char *name = gDMAMemoryName;
    int one = 1;
    int zero = 0;
    info->flags = zero;
    info->name = name;
    info->used = one;
    info->peak = zero;
    info->size = zero;
}
