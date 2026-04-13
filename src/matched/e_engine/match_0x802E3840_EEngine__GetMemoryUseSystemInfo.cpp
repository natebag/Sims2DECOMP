// 0x802E3840 EEngine::GetMemoryUseSystemInfo (40b)
// FLAGS: -fno-schedule-insns

extern char gSystemMemoryName[];

struct HeapUseInfo {
    char *name;
    int used;
    int peak;
    int size;
    int flags;
};

void EEngine__GetMemoryUseSystemInfo(void *self, HeapUseInfo *info) {
    char *name = gSystemMemoryName;
    int one = 1;
    int zero = 0;
    info->flags = zero;
    info->name = name;
    info->used = one;
    info->peak = zero;
    info->size = zero;
}
