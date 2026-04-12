// 0x802E37D4 EEngine::GetDMARingMemoryUseInfo (32b)
// FLAGS: -fno-schedule-insns

struct HeapUseInfo {
    const char *name;
    int field1;
    int field2;
    int field3;
    int field4;
};
class EEngine {
public:
    void GetDMARingMemoryUseInfo(HeapUseInfo *);
};
static const char s_dmaRingName[] = "DMA Ring";
// FLAGS: -fno-schedule-insns
void EEngine::GetDMARingMemoryUseInfo(HeapUseInfo *info) {
    *(int*)((char*)info + 16) = 0;
    info->name = s_dmaRingName;
    info->field1 = 0;
    info->field2 = 0;
    info->field3 = 0;
}
