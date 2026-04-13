// 0x802E37F8 EEngine::GetTextureRingMemoryUseInfo (32b)
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
    void GetTextureRingMemoryUseInfo(HeapUseInfo *);
};
static const char s_name[] = "Texture Ring";
// FLAGS: -fno-schedule-insns
void EEngine::GetTextureRingMemoryUseInfo(HeapUseInfo *info) {
    *(int*)((char*)info + 16) = 0;
    info->name = s_name;
    info->field1 = 0;
    info->field2 = 0;
    info->field3 = 0;
}
