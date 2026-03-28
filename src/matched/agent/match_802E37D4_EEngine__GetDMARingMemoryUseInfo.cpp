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
void EEngine::GetDMARingMemoryUseInfo(HeapUseInfo *info) {
    info->name = s_dmaRingName;
    info->field1 = 0;
    info->field2 = 0;
    info->field3 = 0;
    info->field4 = 0;
}
