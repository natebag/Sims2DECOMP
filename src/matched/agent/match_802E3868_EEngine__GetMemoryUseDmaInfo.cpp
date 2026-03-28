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
void EEngine::GetMemoryUseDmaInfo(HeapUseInfo *info) {
    info->name = s_name;
    info->field1 = 1;
    info->field2 = 0;
    info->field3 = 0;
    info->field4 = 0;
}
