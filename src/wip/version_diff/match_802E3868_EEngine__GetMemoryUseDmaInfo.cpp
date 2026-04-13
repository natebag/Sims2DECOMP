// 0x802E3868 EEngine::GetMemoryUseDmaInfo (32b)
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
    void GetMemoryUseDmaInfo(HeapUseInfo *);
};
static const char s_name[] = "DMA Memory";
// FLAGS: -fno-schedule-insns
void EEngine::GetMemoryUseDmaInfo(HeapUseInfo *info) {
    *(int*)((char*)info + 16) = 0;
    info->name = s_name;
    info->field1 = 1;
    info->field2 = 0;
    info->field3 = 0;
}
