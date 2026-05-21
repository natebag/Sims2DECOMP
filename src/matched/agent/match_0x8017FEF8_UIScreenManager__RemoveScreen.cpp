// 0x8017FEF8 UIScreenManager::RemoveScreen(UIScreenID) (76B)
// ASMPROC_swap_adj: a="addi" b="slwi" which=0

typedef int UIScreenID;

struct ScreenRecord {
    char data[16];
};

class UIScreenManager {
public:
    char pad[0x88];
    ScreenRecord m_records[1];
    int FindRecordIndexByID(UIScreenID id);
    bool RemoveScreen(UIScreenID id);
};

bool UIScreenManager::RemoveScreen(UIScreenID id) {
    bool result = false;
    int idx = FindRecordIndexByID(id);
    if (idx != -1) {
        char* base = (char*)this + 0x88;
        unsigned int off = (unsigned int)idx << 4;
        *(int*)((unsigned int)base + off) = 0;
        result = true;
    }
    return result;
}
