// 0x801B0D5C FAMTarget::DoesFamilyExistInFamilyChoice(int) (80B)

class FAMTarget {
public:
    int ConvertSelectedFamilyIndexToActualGameIndex(int idx);
    int DoesFamilyExistInFamilyChoice(int idx);
};

extern void* g_familyMgr_SDA;

int FAMTarget::DoesFamilyExistInFamilyChoice(int idx) {
    int adjusted = ConvertSelectedFamilyIndexToActualGameIndex(idx);
    void* mgr = g_familyMgr_SDA;
    char* vt = *(char**)mgr;
    short adj = *(short*)(vt + 0x120);
    void* fn = *(void**)(vt + 0x124);
    int ret = ((int(*)(void*, int))fn)((char*)mgr + adj, adjusted);
    if (ret != 0) return 1;
    return 0;
}
