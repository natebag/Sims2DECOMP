// 0x802E3840 EEngine::GetMemoryUseSystemInfo (32b)
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
    void GetMemoryUseSystemInfo(HeapUseInfo *);
};
static const char s_name[] = "System Memory";
// FLAGS: -fno-schedule-insns
void EEngine::GetMemoryUseSystemInfo(HeapUseInfo *info) {
    info->name = s_name;
    *(int*)((char*)info + 16) = 0;
    info->field1 = 1;
    info->field2 = 0;
    info->field3 = 0;
}
