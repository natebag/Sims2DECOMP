// 0x802E381C EEngine::GetMatrixRingMemoryUseInfo (36b)
// FLAGS: -fno-schedule-insns

extern char gMatrixRingName[];

struct HeapUseInfo {
    char *name;
    int used;
    int peak;
    int size;
    int flags;
};

void EEngine__GetMatrixRingMemoryUseInfo(void *self, HeapUseInfo *info) {
    info->flags = 0;
    info->name = gMatrixRingName;
    info->used = 0;
    info->peak = 0;
    info->size = 0;
}
