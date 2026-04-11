struct HeapUseInfo {
    const char *name;
    int field1;
    int field2;
    int field3;
    int field4;
};
class EEngine {
public:
    void GetMatrixRingMemoryUseInfo(HeapUseInfo *);
};
static const char s_name[] = "Matrix Ring";
void EEngine::GetMatrixRingMemoryUseInfo(HeapUseInfo *info) {
    info->name = s_name;
    info->field1 = 0;
    info->field2 = 0;
    info->field3 = 0;
    info->field4 = 0;
}
