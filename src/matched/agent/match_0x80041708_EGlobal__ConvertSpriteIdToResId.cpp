// 0x80041708 EGlobal::ConvertSpriteIdToResId(unsigned int) (80B)

class SpriteIdToResIdNode;

extern char str_SpriteIdToResId_803D28D8[];
extern char* ERQuickdata__getTable(void* qd, char* name);
extern SpriteIdToResIdNode* FindRes(SpriteIdToResIdNode* a, SpriteIdToResIdNode* b, int n);

class EGlobal {
public:
    void* m_236;
    unsigned int ConvertSpriteIdToResId(unsigned int id);
};

unsigned int EGlobal::ConvertSpriteIdToResId(unsigned int id) {
    void* qd = *(void**)((char*)this + 0xEC);
    char* table = ERQuickdata__getTable(qd, str_SpriteIdToResId_803D28D8);
    int count = *(int*)(table + 12);
    char* base = *(char**)(table + 4);
    char* end = base + count * 12;
    return (unsigned int)FindRes((SpriteIdToResIdNode*)base, (SpriteIdToResIdNode*)end, (int)id);
}
